\subsection{Software Infrastructure}
For our software infrastructure, we used Strawman~\cite{larsen2015strawman}, an
open-source in situ framework containing three physics proxy applications.
%
Of these three proxy applications, we used
Cloverleaf3D~\cite{cloverleaf,mallinson2013cloverleaf}, a hydrodynamics
mini-app on a three-dimensional structured grid.
%
Strawman also includes a rendering infrastructure, which combines node-level
rendering using VTK-m~\cite{vtkm}, configured with Intel's Thread Building
Blocks~\cite{ReindersTBB}, and distributed memory image compositing using
IceT~\cite{moreland2011image}.
%
For our study, we integrated PaViz into Strawman and added infrastructure to
calculate per node rendering estimates based on the performance model.

\subsection{Hardware Architecture}
\label{sec:ch4-hardware}

We ran tests on Catalyst, an Intel Ivy Bridge cluster at Lawrence Livermore
National Laboratory.
%
Each node contains two hyper-threaded Intel Xeon E5-2695 v2 CPUs
containing 12 physical cores.
%
The processor operates at a base frequency of 2.4 GHz, and has a maximum
TurboBoost frequency of 3.2 GHz.
%
Each node contains 128 GB of memory.
%
Access to socket-level power capping and monitoring is done through
model-specific registers (MSRs), specifically through the msr-safe kernel
driver~\cite{msrsafe}.
%
Using Intel's Running Average Power Limit (RAPL) technology~\cite{intel2017},
we can power cap each processor in the node between 115W (\ie thermal design
power (TDP)) and 64W, and the processor will adjust the CPU operating frequency
to guarantee the specified power cap.

\subsection{Study Parameters}
\label{sec:ch4-study}

We varied the following parameters as part of this study:
%
\begin{itemize}
\item Rendering Workload (4 options)
\item MPI Task Concurrency (2 options)
\item Power Scheduling Strategy (5 options)
\item Job Power Budget (12 options)
\end{itemize}

We ran the cross product of the study parameters for a total of 480 tests.
%
We detail each of the parameters listed above in the following subsections.

\input{sections/chapter4-egpgv17/clover_renders.inc}

\subsubsection{Rendering Workload}

We selected four representative configurations varying in the size of the data
set, image resolution, and camera position.
%
These configurations spanned commonly used values for each parameter, and yet
each configuration differed in terms of the amount of work per task.
%
The configurations used in this study are enumerated in
Table~\ref{table:renderconfigs}.
%
Images of the data from the three camera positions used --- inside the data set,
near the data set, and far away from the data set --- are shown in
Figure~\ref{fig:cloverrenders}.

\subsubsection{MPI Task Concurrency}
We varied the number of MPI tasks to explore the effects of concurrency on the
number of active pixels per task.
%
For the architecture previously described in Section~\ref{sec:ch4-hardware}, the
number of MPI tasks used were 8 and 64, mapping one task to each node.
%
On this hardware architecture, there are 24 cores per node, so our experiments
used a total of 192 and 1,472 cores, for 8 and 64 nodes, respectively.
%
We ran this as a weak scaling study, \ie the data set size per task was held
constant with each level of concurrency.

\begin{table}
\centering
\begin{tabular}{||c|c|c|c|c||}
\hline
\textbf{Wkld} & \textbf{Data Set} & \textbf{Image Res} & \textbf{Cam Pos} & \textbf{IFact} \\
\hline
A & $240^3$ & $2880^2$ & inside & 1.57 \\
B & $470^3$ & $1080^2$ & near & 1.16 \\
C & $128^3$ & $1920^2$ & inside & 1.58 \\
D & $320^3$ & $2048^2$ & far & 1.12 \\
\hline
\end{tabular}
\caption[Rendering workloads used by the predictive approach implemented in
PaViz.]{\label{table:renderconfigs}Selected rendering workloads for this
study.
%
The configurations use 1000 samples per ray and render 100 images per cycle.
%
IFact is a quantitative representation of the work imbalance, derived by taking
the maximum estimated render time over the average of all estimates.
}
\end{table}

\subsubsection{Power Scheduling Strategy}
%
We explore the performance improvements of the five power scheduling strategies
defined in Section~\ref{sec:ch4-strategies} to rebalance power based on need.
%
Some strategies are more aggressive in terms of assigning socket power caps,
%
while others are less aggressive, but risk leaving further performance to be
reclaimed.
%
In addition to exploring the benefit of rebalancing power based on a
performance model, we wanted to explore the benefits of using different
power scheduling strategies.

\subsubsection{Job Power Budget}

We vary the power budget by assuming a uniform node power cap (ranging from 230W
down to 128W per node, 115W to 64W per processor).
%
In this study, we only consider the power consumption of the socket domain.
%
For example, assume there are eight nodes in the job.
%
The range of job power budgets ranges from 1840W (per node power cap of 230W)
down to 1024W (per node power cap of 128W).
%
By enforcing lower node power caps, we arbitrarily limit the job power budget,
and can compare the performance of PaViz to a uniform power distribution under
a power-limited environment.

\subsection{Efficacy Metrics}

We define two efficacy metrics quantifying the benefits of adaptively
rebalancing power based on a performance model.
%
We explain these metrics in more detail in the following subsections.

\subsubsection{Speedup Over Uniform Power Caps}
The speedup metric compares the runtime of PaViz to a uniform power
distribution computed by $\frac{job\_power\_budget}{nnodes}$.
%
This scenario is currently implemented in practice.
%
With PaViz, each node may be running at a different power cap, but the
aggregate sum of the power caps is less than or equal to the job power budget.
%
A speedup greater than 1 indicates better performance with PaViz in adapting
power caps
relative to the predicted render time.
%
A speedup less than 1 indicates degraded performance with PaViz, and a speedup
equal to 1 indicates no change in performance.

To see the impacts of RAPL's power capping mechanism, the workload must be long
enough to overcome the delay between when the new power cap is set and when the
processor recognizes (and begins operating at) the new cap.
%
Rendering a single image can be a very quick operation, less than a fraction of
a second.
%
However, it is not uncommon to create several images per time step, and on the
extreme side, image-based in situ~\cite{Ahrens:2014:IAE:2683593.2683640},
where hundreds of images are rendered per time step.
%
This use case increases overall render time and amortizes out the RAPL delay.

\subsubsection{Unused Job Power}

The second metric compares the job power allocated by PaViz to the original
power budget.
%
PaViz rebalances power based on a predicted rendering estimate generated by a
performance model, such that the original power budget is not exceeded.
%
The percentage of unused job power is computed by taking the difference between
the job power budget and the job power allocated by PaViz divided by the job
power budget.
%
We observed the best performance when the entire job power budget is allocated
by PaViz, particularly in a power-constrained environment, where some nodes may
not be able to execute at TDP.
