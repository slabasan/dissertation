\begin{figure*}
\centering
\begin{subfigure}[t]{0.22\textwidth}
    \centering
    \includegraphics[width=\textwidth]{images/chapter5/-10_-18_bananas.png}
    \caption{Workload A}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.22\textwidth}
    \centering
    \includegraphics[width=\textwidth]{images/chapter5/120_-90_bananas.png}
    \caption{Workload B}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.22\textwidth}
    \centering
    \includegraphics[width=\textwidth]{images/chapter5/52_18_bananas.png}
    \caption{Workload C}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.22\textwidth}
    \centering
    \includegraphics[width=\textwidth]{images/chapter5/74_-90_bananas.png}
    \caption{Workload D}
\end{subfigure}
\caption[Rendered images of a contour of the pressure at the 200th cycle for the
CloverLeaf hydrodynamics proxy application.]{\label{fig:cloverrenders}Ray
traced images of CloverLeaf at the
200th simulation cycle.
%
The figure shows a contour of the pressure at various values after it has
expanded from the initial position where the energy was deposited.}
\end{figure*}

The following subsections detail the experimental setup and methodology.

\subsection{Software Infrastructure}
We used VTK-m and Ascent to provide visualization and analysis capabilities.
%
VTK-m~\cite{vtkm} is a library of scientific visualization
algorithms optimized for shared-memory parallelism.
%
The algorithms use data parallel primitives to provide portable performance
across many different hardware architectures.
%
VTK-m is an extension of the Visualization ToolKit~\cite{VTK}, a library of
visualization algorithms.
%
VTK is the basis for VisIt~\cite{HPV:VisIt} and
ParaView~\cite{Ahrens+Geveci+Law2005}.

Ascent is a flyweight in situ visualization and analysis runtime system for
scientific simulations.
%
It aims for portable performance on future many-core CPU and GPU
architectures~\cite{Larsen:2017:ASI:3144769.3144778}.
%
It is designed to support other in situ visualization tools, such as VisIt's
LibSim~\cite{Whitlock:2011:PSC:2386230.2386245} and ParaView's
Catalyst~\cite{Ayachit:2015:PCE:2828612.2828624}.
%
Ascent depends on VTK-m for inter-node parallelism and OpenMP for intra-node
parallelism.
%
Ascent's framework includes three proxy simulations ---
Kripke~\cite{kunen2015kripke}, Lulesh~\cite{karlin2012tuning}, and
CloverLeaf~\cite{cloverleaf,mallinson2013cloverleaf}.
%
For the scientific simulation in this study, we used CloverLeaf, a
hydrodynamics proxy application on a three-dimensional structured grid.

\subsection{Hardware Architecture}
We conduct our experiments on the Quartz supercomputer at Lawrence Livermore
National Laboratory, which is a 2,634 node Broadwell system (Intel E5-2695).
%
Each node contains two hyperthreaded processors and 18 physical cores per
processor.
%
The base clock frequency is 2.10 GHz and the processor is rated at 120W TDP.

The msr-safe~\cite{msrsafe} kernel module enables power monitoring and control
from user space.
%
We enforce a processor-level power limit using Intel's Running Average Power
Limit (RAPL) interfaces~\cite{intel2017}.
%
Under a more severe power limit, the processor operates at a lower CPU
frequency to guarantee that the average power usage does not exceed the
specified limit.
%
For this particular architecture, we can enforce a processor-level power cap
ranging from 120W down to 40W.

\subsection{Study Parameters}
This study was designed to evaluate two power-aware runtime systems (PaViz and
GEOPM) under a variety of rendering workloads.
%
We varied the following parameters in order to study a representative set of
configurations:
%
\begin{itemize}
\item Job Power Budget (9 options)
\item Rendering Workload (4 options)
\item MPI Tasks (5 options)
\item Power Scheduling Strategy (2 options)
\end{itemize}

We ran the cross product of the aforementioned parameters totaling 104 tests
configurations.
%
Each of the parameters are discussed in the following subsections.

\subsubsection{Job Power Budget}
Both GEOPM and PaViz assume a specified job power budget.
%
Individual compute nodes may be allocated varying amounts of power, but at no
given moment can the aggregate sum of the allocated power across all nodes
exceed the specified job power budget.
%
To simplify this study, both runtime systems are only concerned with the power
usage of the processors within the node.
%
Table~\ref{table:powbudgets} shows the power limits for each runtime system.

\begin{table}[h]
\centering
\begin{tabular}{||ccc||}
\hline
\begin{tabular}[c]{@{}c@{}}\textbf{GEOPM}\\(Per-Node)\end{tabular} & \begin{tabular}[c]{@{}c@{}}\textbf{PaViz}\\(Per-Processor)\end{tabular} & \textbf{\% TDP} \\
\hline
\hline
260W & 120W & 100\% \\
\hline
200W & 100W & 83.3\% \\
\hline
180W & 90W & 75\% \\
\hline
160W & 80W & 66.7\% \\
\hline
140W & 70W & 58.3\% \\
\hline
136W & 68W & 56.7\% \\
\hline
120W & 60W & 50\% \\
\hline
100W & 50W & 41.7\% \\
\hline
80W & 40W & 33.3\% \\
\hline
\hline
\end{tabular}
\caption[Node-level and processor-level power budgets used by the adaptive and
predictive runtime systems.]{\label{table:powbudgets}Enumerating the
user-specified power budgets
used in each runtime system.
%
The GEOPM power budget is node-level (split evenly across all processors within the
node).
%
The PaViz power budget is processor-level (scale by the number of
processors within the node to derive node power budget).
%
Scaling the power budgets by the number of nodes will determine the total job
power budget.
}
\end{table}

\begin{figure*}
\centering
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-configA-rendertime-per-rank.pdf}
    \caption{Rendering Workload A}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-configB-rendertime-per-rank.pdf}
    \caption{Rendering Workload B}
\end{subfigure}
\\
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-configC-rendertime-per-rank.pdf}
    \caption{Rendering Workload C}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-configD-rendertime-per-rank.pdf}
    \caption{Rendering Workload D}
\end{subfigure}
\caption[Total rendering times across all visualization cycles for each
rank.]{\label{fig:rendertimeperrank}For each rank, we aggregate the time
spent rendering across all visualization cycles.
%
If the workload was perfectly balanced, each rank would have the same execution
time.
%
However, rendering is a highly imbalanced workload, so there are significant
differences in execution time across ranks.
%
We aim to address the imbalance by shifting power away from the ranks with low
execution times, and shifting power to the ranks with high execution times.
}
\end{figure*}

\subsubsection{Rendering Workload}

We selected four workloads that varied in the size of the data set, the
isovalues used for the contour, the number of images generated per
visualization cycle, and the image resolution.
%
The rendering workloads and their parameters are listed in
Table~\ref{table:renderconfigs} and an image of the resulting contour is shown
in Figure~\ref{fig:cloverrenders}.
%
These configurations span commonly used values for each parameter, and each
workload exhibits a different amount of work imbalance.
%
Figure~\ref{fig:rendertimeperrank} shows the imbalance in the total rendering
times across all visualization cycles per rank.

The amount of time spent doing rendering can vary greatly depending on
different user-specified parameters, such as the camera position and the image
resolution.
%
Typically, rendering is a very quick operation and is a small fraction of the
total time doing visualization operations.
%
Reducing the amount of data saved to disk is a common strategy for mitigating
the I/O challenges of future supercomputers.
%
One method of reducing the amount of data is rendering hundreds to thousands of
images per timestep of the resulting analysis (\ie cinema) and save them to
disk, which is significantly smaller than the original data set.

Our rendering infrastructure used cinema-based in
situ~\cite{Ahrens:2014:IAE:2683593.2683640,o2016cinema}, where an interactive
database is generated by taking many pictures from various camera positions
around the data set.
%
In this paradigm, the cost of rendering can become a significantly large
percentage of the overall visualization and analysis pipeline.
%
Selecting the number of images to be generated during each visualization cycle
is another user-specified parameter that can greatly impact overall execution
time.
%
Thus, understanding how to improve the performance of this operation is
critical.

\begin{table}[h]
\centering
\begin{tabular}{||ccccccc||}
\hline
\textbf{Wkld} & \textbf{Data Set} & \textbf{Isoval} & \textbf{Res} & \textbf{Phi} & \textbf{Theta} & \textbf{IFact} \\
\hline
\hline
A & $240^3$ & 0.4 & $2880^2$ & 17 & 10 & 1.32 \\
\hline
B & $190^3$ & 0.6 & $1080^2$ & 18 & 9 & 1.26 \\
\hline
C & $128^3$ & 0.9 & $1920^2$ & 17 & 10 & 1.18 \\
\hline
D & $320^3$ & 1, 3.4, 5.2 & $2048^2$ & 17 & 10 & 1.56 \\
\hline
\end{tabular}
\caption[Rendering workloads used in the adaptive and predictive power
scheduling study in Chapter~\ref{ch:tpds}.]{\label{table:renderconfigs}Selected
rendering workloads
for this study.
%
The data set size is per rank.
%
It is multiplied by the cube root of the number of nodes to get the total data
set size.
%
The number of images rendered per cycle is determined by $Phi \times Theta$.
%
The simulation ran for a total of 300 cycles.
%
Visualization occurred every 50 cycles.
%
IFact is a quantitative representation of the work imbalance, derived by taking
the maximum aggregate sum of the predicted render time over the median of all
estimates.
}
\end{table}

\subsubsection{MPI Tasks}
We varied the number of MPI tasks to study the scaling behaviors of adaptive
and predictive strategies at higher concurrencies.
%
We used a single MPI task per node (OpenMP threaded), and selected the number
of tasks such that the data set size was constant per task.
%
The number of nodes used were 8, 125, 216, 343, and 512.

\subsubsection{GEOPM Power Balancer Policy}
We used the Power Balancer policy included in GEOPM for dynamically varying the
power limit of individual nodes to optimize performance.
%
The Power Balancer monitors the performance of the application and regularly
redistributes power between the nodes.
%
Similar to PaViz, more power is given to the nodes on the critical path,
enabling them to run at a higher power limit, while power is taken away from
nodes not on the critical path.
%
With this mode, power allocations to each node are non-uniform, inversely
proportional to the load imbalance.
%
The Power Balancer measures the loop execution time on each node and compares
execution times across nodes to identify critical path nodes and how much
correction is needed.

The power redistribution occurs in a hierarchical tree.
%
The average power cap is passed to all compute nodes.
%
Each node reports their performance under this power cap up the tree.
%
The root node aggregates the performance per-node, and passes back the worst
performance.
%
Each node reduces its power limit until its performance matches that of the
worst node, passing back its extra unneeded power.
%
This pool of unused power is redistributed across the nodes to improve overall
performance.

\subsubsection{PaViz Power Scheduling Strategy}
We used the \emph{Min} power scheduling strategy, which resulted in the best
performance of all the strategies explored in~\cite{pgv.20171088}.
%
The \emph{Min} strategy uses the difference from the fastest predicted render
time to determine the power allocation.
%
Using the per-node predicted rendering execution times, the node power cap is
computed as follows:
%
\begin{equation*}
pow_{node\_min} +
\frac{|ren_{min}-ren_{i}|}{\sum_{i=0}^{n-1}{|ren_{min}-ren_{i}|}}
* pow_{avail},
\end{equation*}
%
where $pow_{node\_min}$ is the hardware-specified minimum node power needed to
execute the job, $ren_{min}$ is the global minimum predicted render time among
all $n$ MPI tasks, $ren_{i}$ is the predicted render execution time for rank
$i$, and $pow_{avail}$ is the available power to allocate to the job.
%
Nodes that are furthest away from the minimum (i.e., highest render time, most
work to be done) are allocated a large amount of power, resulting in the
highest speedups in a balanced and imbalanced workload configuration, since the
rendering task is only as fast as the slowest processor.
