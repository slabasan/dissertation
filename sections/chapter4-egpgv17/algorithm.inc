In an overprovisioned environment, the total power allocated to the machine is
not enough to run all nodes at peak power simultaneously.
%
The default strategy for handling this reduction in power is to uniformly
assigned reduced power --- if the total power is 50\% of peak, then each node
would be capped at 50\% of its maximum power.
%
The performance effects of this power cap will vary from node to node.
%
In cases where the node was approaching maximum power, the slowdown
would be greater, while in cases where the node was already using less
than the power cap, there would be no effect in runtime.
%
Therefore, since the rendering task is only as fast as the slowest processor,
the choice of uniform reduction is poor.
%
A better choice is to adapt the power assigned to each node based on how
much work it has to do --- nodes with lots of work get higher power caps and
nodes with less work get lower power caps.
%
In an ideal scenario, each node would complete rendering at the same time.

Adaptively assigning power is a non-trivial task.
%
At its essence, it involves assessing how much work each processor needs to do.
%
For our approach, we incorporate an existing rendering performance
model~\cite{Larsen:SC16}.
%
When the performance model predicts a high rendering time, we assign more
power, and when it predicts low rendering time, we assign less.
%
In terms of specifics, we consider a family of strategies, detailed in the
next subsection.

For volume rendering, the performance model predicts the rendering time by
considering the camera configuration and data set size.
%
The model is based on the observation that there are two distinct types of
operations in volumetric ray casting, each with a cost determined by the
hardware architectural factors.
%
Operations that are associated with entering a new cell (\eg loading nodal
scalar values) occur with a frequency influenced by the size of the
data set and the distance between samples relative to cell size, and operations
that are associated with each sample (\eg interpolating scalars and compositing
colors) occur with a frequency influenced by the total data set spatial extents
and sample distance.
%
The combination of these operations represent the total amount of work per ray,
and with an estimate of the number of rays that intersect the volume using
camera parameters, a total amount of work for the entire image can be
predicted.
%
Architectural costs for each of the two operations were calculated using
multiple linear regression data gathered on the architecture on which the model
was used~\cite{Larsen:SC16}.
%
In all, given a camera position, data set size, and sampling parameters, the
time to render on a node could be predicted with high accuracy.

\subsection{Power Scheduling Strategies}
\label{sec:ch4-strategies}

\begin{table}
\centering
\begin{tabular}{||l|l||}
\hline
\textbf{Parameter} & \textbf{Description} \\
\hline
$n$ & Number of MPI tasks \\
$pow_{node\_min}$ & Minimum node power needed to execute job \\
$pow_{avail}$ & Available power to allocate \\
$ren_{i}$ & Predicted render time for task $i$ \\
$ren_{min}$ & Global minimum predicted render time among all $n$ tasks \\
$ren_{mean}$ & Global mean predicted render time among all $n$ tasks \\
$ren_{med}$ & Global median predicted render time among all $n$ tasks \\
$ren_{max}$ & Global maximum predicted render time among all $n$ tasks \\
\hline
\end{tabular}
\caption[Power scheduling strategy parameters used in the predictive approach
in PaViz.]{\label{table:params}Power scheduling strategy parameters.}
\end{table}

In this section, we describe the power scheduling strategies used in this
study.
%
For this exploratory work, we implemented a handful of simple strategies, and
evaluate their ability to improve performance.

Each scheduling strategy produces a scalar factor, which we use to assign a
portion of the ``available power" (denoted as $pow_{avail}$) to each node.
%
This guarantees that the allocated job power budget is not exceeded as per-node
power assignments are being made.
%
The $pow_{avail}$ is calculated by taking the difference between the specified
power budget and the minimum power required to execute the job reliably (\ie
the minimum power needed to operate all nodes sufficiently).

\subsubsection{\emph{Min} Scheduling Strategy}
This strategy uses the difference from the minimum estimated render time to
determine the power allocation.
%
For each predicted rendering runtime, the node power cap is determined as
follows:
%
\begin{equation*}
pow_{node\_min} +
\frac{|ren_{min}-ren_{i}|}{\sum_{i=0}^{n-1}{|ren_{min}-ren_{i}|}}
* pow_{avail}
\end{equation*}
%
We speculate that this strategy will produce the best speedups of all the
strategies described in this section.
%
Nodes that are furthest away from the minimum (\ie highest render time, most
work to be done) will be allocated a high amount of power, and this should
produce the highest speedups in a balanced and imbalanced workload
configuration, since the rendering task is only as fast as the slowest
processor.

\subsubsection{\emph{Normalized} Scheduling Strategy}
This strategy calculates node power assignments by the value of the predicted
render time:
%
\begin{equation*}
pow_{node\_min} + \frac{ren_{i}}{\sum_{i=0}^{n-1}ren_{i}}*pow_{avail}
\end{equation*}
%
This strategy behaves similarly to \emph{Min}, since power assignments
correlate with the render times.
%
It assigns less aggressive power caps, since the computation does not take into
account the global minimum of the predicted render times.

\subsubsection{\emph{Mean} Scheduling Strategy}
This strategy uses the distance from the average estimated render time to
assign power allocations.
%
\begin{equation*}
%p_{pkg\_min} \times nskts\_per\_node +
pow_{node\_min} +
\frac{|ren_{mean}-ren_{i}|}{\sum_{i=0}^{n-1}{|ren_{mean}-ren_{i}|}}
* pow_{avail}
\end{equation*}
%
The intuition is that this strategy has no impact on performance when the rendering
workload is evenly balanced.
%
If the rendering workload is imbalanced, the \emph{Mean} strategy may provide
some benefits, but we speculate it will not produce as aggressive of a power
schedule as the \emph{Min} strategy, since the mean falls between all estimates.

\subsubsection{\emph{Median} Scheduling Strategy}
%
This strategy uses the distance from the median estimated render time in making
its power decision.
%
\begin{equation*}
%p_{pkg\_min} \times nskts\_per\_node +
pow_{node\_min} +
\frac{|ren_{med}-ren_{i}|}{\sum_{i=0}^{n-1}{|ren_{med}-ren_{i}|}}
* pow_{avail}
\end{equation*}
%
We speculate that the \emph{Median} strategy will perform similarly to the
\emph{Mean} strategy, since the median and mean will not differ significantly
in our rendering configurations.
%
We envision cases where the median is better for assigning more aggressive
power caps than the mean, producing better speedups than the \emph{Mean}
strategy.

\subsubsection{\emph{Max} Scheduling Strategy}
This scheduling strategy uses the difference from the maximum estimated render
time to determine the power allocation.
%
For each predicted rendering runtime, the node power cap is determined as
follows:
%
\begin{equation*}
pow_{node\_min} +
\frac{|ren_{max}-ren_{i}|}{\sum_{i=0}^{n-1}{|ren_{max}-ren_{i}|}}
* pow_{avail}
\end{equation*}
%
Intuitively, this scheduling strategy will perform the worst of all implemented
strategies as it rebalances power in a sub-optimal manner.
%
It allocates higher power to nodes with only a small amount of work to complete
(\ie fast render time), and low power to nodes with long render times,
only increasing the overall runtime.
