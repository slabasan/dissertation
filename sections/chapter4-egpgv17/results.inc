We organized our study into four phases.
%
We first look at a base case, which uses eight nodes and a single power
scheduling strategy detailed in Section~\ref{sec:ch4-strategies}.
%
Subsequent sections evaluate the benefits of PaViz when varying the power
scheduling strategy, workload configuration, and concurrency under different
power budgets.
%
These factors were previously described in Section~\ref{sec:ch4-study}.
%
In each phase, we vary the job power budget, and analyzed its impact.

\subsection{Phase 1: Base Case}

In this phase, we compare the speedups of the \emph{Min} scheduling
strategy under various job power budgets.
%
The x-axis has been reversed, such that the job power budgets are decreasing,
as would be the case with a power-constrained environment.
%
The results are for an imbalanced rendering workload configuration (labeled as
``A" and defined in
Table~\ref{table:renderconfigs}) and are shown in
Figure~\ref{fig:minstrategy_configA}.

The performance degradation is minimal for job power budgets between
1800W and 1600W.
%
This is because the allocated power exceeds the observed (\ie actual) power
consumption of the application.
%
The dotted line, which represents the unused job power, shows the same
execution time can be achieved by using up to $12\%-20\%$ less than the allocated
job power budget.
%
If the job power budget is extremely constrained to 1024W, we similarly see no
benefit as there is a small amount of job power available to reallocate between
the nodes.

In this configuration, PaViz produces up to $10\%$ speedup over the current
practice for job power budgets between 1400W and 1100W.
%
For these speedups, PaViz reallocates all of the job power budget, such that
there is $0\%$ unused job power.
%
At a job power budget of 1500W, PaViz achieves about $4\%$ speedup in this
configuration by using $3\%$ less than the job power budget.
%
If we assume the job power budget is the actual power consumption of the job,
then PaViz can also save energy by having a faster runtime than the current
practice.
%
For example, with a job power budget of 1360W, PaViz produces a speedup of
$10\%$ by using the entire power budget (\ie $0\%$ unused power).
%
This produces an energy savings of about $9\%$ as compared to the current
practice.

\begin{figure}
\centering
\includegraphics[width=0.7\columnwidth]{images/chapter4/configA-8-speedupjobpower-minstrategy.pdf}
\caption[Speedup results for a single rendering workload using the Min predictive
power scheduling strategy defined in
Chapter~\ref{ch:egpgv}.]{\label{fig:minstrategy_configA}Speedups and allocated
power for
Rendering Workload A using the Min power scheduling strategy.
%
The solid line shows the resulting speedups as compared to uniform power
caps (right y-axis).
%
The black dotted line identifies where the speedup is 1, indicating no change
in performance.
%
The dotted line shows the percentage of unused job power budget that resulted
in a particular speedup (left y-axis).
%
A percentage of $0\%$ means that the entire job power budget was reallocated
across the nodes.
}
\end{figure}

\subsection{Phase 2: Vary Scheduling Strategy}

In this phase, we compare the speedups and unused job power of the five
power scheduling strategies (see Figure~\ref{fig:allstrategies_configA}).
%
The \emph{Min} strategy performed the best of all strategies in this
configuration, since it assigns the highest power limit to those nodes with
high estimated render times and vice versa.

On the other hand, the \emph{Max} strategy performed the worst of all
strategies.
%
This strategy assigns high power caps to those nodes with low predicted
render times, while assigning low power caps to those with high predicted
render times.
%
With this strategy, performance degrades significantly since the node with the
most work to do (\eg the bottleneck node) will execute at a lower power cap.

The \emph{Normalized} strategy has a similar behavior to the \emph{Min}
strategy.
%
This is because power caps are scaled directly by the estimated render time,
which will assign high power caps to high render times and low power caps to
low render times.
%
For this configuration, the \emph{Normalized} strategy does not achieve as high
a speedup as the \emph{Min} strategy because it is unaware of the fastest
render time, and will assign a less aggressive power cap.

The \emph{Mean} strategy performs as well as the current practice for this
configuration with the camera positioned inside the data set.
%
With an imbalanced workload, some nodes will be higher than the mean and others
will be lower than the mean, and will average out to the same performance as
running all nodes at the same power cap.

The \emph{Median} strategy degrades performance slightly.
%
Depending on the distribution of estimated render times, the median may cause
the non-ideal assignment of power caps to predicted render times.

\begin{figure}
\centering
\includegraphics[width=0.7\columnwidth]{images/chapter4/configA-8-speedupjobpower-5strategies.pdf}
\caption[Comparing speedup results for a single rendering
workload using five different predictive power scheduling
strategies.]{\label{fig:allstrategies_configA}Comparing speedups and unused job
power budget for Rendering Workload A across all five power scheduling
strategies.
}
\end{figure}

\begin{figure*}[t]
\centering
\includegraphics[width=0.32\columnwidth]{images/chapter4/configB-8-speedupjobpower-5strategies-nolegend.pdf}
\includegraphics[width=0.32\columnwidth]{images/chapter4/configC-8-speedupjobpower-5strategies-nolegend.pdf}
\includegraphics[width=0.32\columnwidth]{images/chapter4/configD-8-speedupjobpower-5strategies-nolegend-samenodes.pdf} \\
\includegraphics[width=0.75\columnwidth]{images/chapter4/legend_horiz.pdf}
\caption[Comparing speedup results when varying across the different
rendering workloads and predictive power scheduling strategies outlined in
Chapter~\ref{ch:egpgv}.]{\label{fig:allstrategies_allconfigs_8nodes}Comparing
speedups and unused job power for Rendering Workloads B, C, and D at 8 node
concurrency
using all five power scheduling strategies.
%
The solid lines show the resulting speedups as compared to uniform power caps
(right y-axis).
%
The black dotted line identifies where the speedup is 1, indicating no change
in performance.
%
The dotted lines show the percentage of unused job power that resulted in a
particular speedup (left y-axis).
}
\end{figure*}

\subsection{Phase 3: Vary Workload Configuration}

We vary the workload configuration to demonstrate how rendering parameters
may impact the potential for performance improvements.
%
With the camera positioned inside the data set (Rendering Workloads A and C),
there is greater work imbalance (\ie wider distribution of predicted render
times) between the nodes because
some nodes will have no geometry in the field of view of their cameras, and
thus will perform no rendering.
%
Moving the camera position far away from the data set, such as in
Rendering Workloads B and D, creates a more even distribution of predicted render
times, and this balance limits the ability of PaViz to achieve significant
speedups.

Figure~\ref{fig:allstrategies_allconfigs_8nodes} shows the speedups and unused
job power for the remaining workload configurations --- B, C, and D.
%
Rendering Workload C has a maximum speedup of $10\%$ that is comparable to
Rendering Workload A, which was previously shown in
Figure~\ref{fig:allstrategies_configA}.
%
This is because there is significant imbalance when the camera is positioned
inside the data set, providing more benefit from adaptively rebalancing power.
%
However, we note that Rendering Workload A provides speedups with the
\emph{Min} and \emph{Normalized} strategies over more job power budgets than
Rendering Workload C.
%
The range of raw render estimates is far greater in Rendering Workload A (0.3
sec to 1.4 sec) than Rendering Workload C (0.15 sec to 0.64 sec) due to the
data set size per node.
%
The increased distance between the minimum and maximum predicted runtime gives
Rendering Workload A more opportunity for benefits with PaViz.

We achieve little to no speedup on Rendering Workloads B and D because the
render estimates are balanced when the camera is positioned further away from
the data set, which matched our initial intuition.
%
For these configurations, the render estimates ranged from 0.10 sec to 0.14 sec
for workload B, and 0.12 sec to 0.16 sec for workload D, which did not provide
much room for adapting power (in several cases, all nodes were assigned the
same uniform power cap).
%
The \emph{Min} strategy results in a $4\%$ speedup on Rendering Workload D,
but we attribute this to performance variability when the processor is under a
power cap.

\subsection{Phase 4: Vary Concurrency}

In this phase, we increase the node concurrency from 8 nodes to 64 nodes to
understand the potential benefits at scale.
%
The initial intuition was that a higher concurrency would lead to better
performance since there would be a larger work imbalance per node and a larger
job power budget that can be reallocated between nodes.
%
Figure~\ref{fig:allstrategies_64nodes} shows the speedups and unused job power
for all rendering configurations enumerated in Table~\ref{table:renderconfigs}
using 64 nodes.
%
We weak scale the data size to maintain the same work per node.

For these configurations, PaViz achieves up to $33\%$ speedup over uniform
distribution of power.
%
At 64 nodes, we see the render predictions change in two ways.
%
First, the range of predictions between the minimum and maximum render value is
much smaller.
%
Secondly, a larger percentage of nodes have very little, or even no, geometry
to render.
%
In the imbalanced configurations A and C, the scheduling strategies in PaViz
assign these nodes low power caps, enabling nodes with lots of work to
operate at a high power cap.
%
We suspect that imbalanced workloads at even higher concurrencies will
achieve even greater speedups.
%
In the balanced configurations B and D, the performance estimates were
extremely fast (less than 0.08 sec), the range of estimates was much
closer to one another that they were with eight nodes (ranging from 0.06 sec to
0.07 sec), and the scheduling policies assigned uniform power caps across all
nodes.

\begin{figure*}
\centering
\includegraphics[width=2.8in]{images/chapter4/configA-64-speedupjobpower-5strategies-nolegend.pdf}
\includegraphics[width=2.8in]{images/chapter4/configB-64-speedupjobpower-5strategies-nolegend.pdf} \\
\includegraphics[width=2.8in]{images/chapter4/configC-64-speedupjobpower-5strategies-nolegend.pdf}
\includegraphics[width=2.8in]{images/chapter4/configD-64-speedupjobpower-5strategies-nolegend.pdf} \\
\includegraphics[width=4in]{images/chapter4/legend_horiz.pdf}
\caption[Comparing speedups when varying across rendering workloads and
predictive power scheduling strategies at higher node concurrency.]{\label{fig:allstrategies_64nodes}Comparing speedups and unused job
power for all rendering workloads at 64 node concurrency using the five power
scheduling strategies.
%
The solid lines show the resulting speedups as compared to uniform power caps
(right y-axis).
%
The black dotted line identifies where the speedup is 1, indicating no change
in performance.
%
The dotted lines show the percentage of unused job power that resulted in a
particular speedup (left y-axis).
}
\end{figure*}
