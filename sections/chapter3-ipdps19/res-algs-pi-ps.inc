\begin{table*}[]
\centering
\begin{tabular}{||l|c|c|c|c|c|c|c|c|c|c||}
\hline
                           & $P$         & 120W  & 110W  & 100W  & 90W   & 80W   & 70W   & 60W   & 50W   & 40W  \\
                           & $P_{rat}$ & 1X  & 1.1X  & 1.2X  & 1.3X  & 1.5X  & 1.7X  & 2X  & 2.4X  & 3X \\
\hline
\multirow{2}{*}{1}            & $T_{rat}$ & 1X & 1X & 1X & 1X & 1X & 0.91X & 0.91X & 0.93X & \fix{1.17X} \\
                                    & $F_{rat}$ & 1X & 1.06X & 1X & 1X & 1.01X & 1X & 1.02X & 1.01X & \fix{1.23X} \\
\hline
\multirow{2}{*}{2} & $T_{rat}$ & 1X & 1.01X & 1.03X & 1.02X & 1X & 1.05X & 1.02X & \fix{1.18X} & 1.48X \\
                                    & $F_{rat}$ & 1X & 1.21X & 1X & 1.02X & 1X & 1X & 1.03X & \fix{1.11X} & 1.48X \\
\hline
\multirow{2}{*}{3}          & $T_{rat}$ & 1X & 1.01X & 0.99X & 1.04X & 1.02X & 1.06X & \fix{1.14X} & 1.30X & 1.81X \\
                                    & $F_{rat}$ & 1X & 1X & 1X & 1X & 1.03X & \fix{1.13X} & 1.31X & 1.61X & 2.55X \\
\hline
\multirow{2}{*}{4}          & $T_{rat}$ & 1X & 0.98X & 0.98X & 1X & 0.99X & 0.99X & 1.02X & 1.08X & \fix{1.31X} \\
                                    & $F_{rat}$ & 1X & 0.99X & 1X & 0.99X & 0.99X & 1X & 1X & \fix{1.12X} & 1.38X \\
\hline
\multirow{2}{*}{5}              & $T_{rat}$ & 1X & 0.98X & 1X & 0.99X & 0.98X & 1.02X & 1.04X & 1.03X & \fix{1.26X} \\
                                    & $F_{rat}$ & 1X & 0.98X & 0.99X & 1.03X & 1.04X & 1.01X & 1.03X & 1.01X & \fix{1.22X} \\
\hline
\multirow{2}{*}{6} & $T_{rat}$ & 1X & 1X & 0.99X & 0.99X & 1X & 1.01X & \fix{1.10X} & 1.31X & 1.75X \\
                                    & $F_{rat}$ & 1X & 1X & 1X & 1X & 1X & 1.01X & \fix{1.11X} & 1.32X & 1.73X \\
\hline
\multirow{2}{*}{7} & $T_{rat}$ & 1X & 1X & 1.01X & 1.05X & \fix{1.11X} & 1.21X & 1.34X & 1.57X & 3.12X \\
                                    & $F_{rat}$ & 1X & 1X & 1X & 1.04X & \fix{1.10X} & 1.18X & 1.31X & 1.51X & 2.69X \\
\hline
\multirow{2}{*}{8} & $T_{rat}$ & 1X & 1X & 0.99X & 1X & 1.04X & \fix{1.12X} & 1.23X & 1.46X & 1.86X \\
                                    & $F_{rat}$ & 1X & 1X & 1X & 1X & 1.04X & \fix{1.12X} & 1.23X & 1.45X & 1.84X \\
\hline
\end{tabular}
\caption[Performance of all algorithms explored in Chapter~\ref{ch:ipdps} using
a data set size of $128^3$ and reduced power limits.]{\label{table:algs-128-deck2}Slowdown factor for all algorithms with a
data set size of $128^3$.
%
The mapping between number and algorithm is defined as follows: (1) Contour,
(2) Spherical Clip, (3) Isovolume, (4) Threshold, (5) Slice, (6) Ray Tracing,
(7) Particle Advection, and (8) Volume Rendering.
%
Slowdown is calculated by dividing execution time at 40W by execution time at
120W.
%
Numbers highlighted in red indicate the first time a 10\% slowdown in execution
time or frequency occurs due to the processor power cap $P$.}
\end{table*}

\subsection{Phase 2: Visualization Algorithm}
\label{sec:ch3-res-algs}

In Phase 1, we determined that the contour algorithm is sufficiently
memory-bound to avoid a change in execution time until a severe power cap.
%
In Phase 2, we want to explore if this data intensive trend is common
across other algorithms, so we extend the previous phase and vary the
visualization algorithm.
%
We continue to focus on a data set size of $128^3$.
%
We identify two clear groupings: those algorithms that are insensitive to
changes in power (power opportunity), and those algorithms that are sensitive
to changes in power (power sensitive).
%
We will discuss the two categories in more detail below.

\subsubsection{Power Opportunity Algorithms}
The algorithms that fall into the power opportunity category are contour
(discussed in the previous section), spherical clip, isovolume, threshold,
slice, and ray tracing.
%
Table~\ref{table:algs-128-deck2} shows the slowdown in execution time and CPU
frequency for all algorithms.
%
The power opportunity algorithms do not see a significant slowdown (of 10\%,
denoted in red) until $P_{ratio}$ is at least 2X or higher.
%
These algorithms are data-bound --- the bottleneck is the memory subsystem, not
the processor --- so reducing the power cap does not significantly impact
the overall performance.
%
This is confirmed since $T_{ratio}$ is less than $P_{ratio}$.

\begin{figure*}
\centering
\includegraphics[width=0.5\columnwidth]{images/chapter3/legend_algs_long.pdf} \\
\begin{subfigure}[t]{0.32\textwidth}
    \centering
    \includegraphics[width=1\linewidth]{images/chapter3/jan3_freq_large.pdf}
    \subcaption{\label{fig:freq_all_algs}Effective frequency}
\end{subfigure}
\hfil
\begin{subfigure}[t]{0.32\textwidth}
    \centering
    \includegraphics[width=1\linewidth]{images/chapter3/jan3_ipc_large.pdf}
    \subcaption{\label{fig:ipc_all_algs}IPC}
\end{subfigure}
\hfil
\begin{subfigure}[t]{0.32\textwidth}
    \centering
    \includegraphics[width=1\linewidth]{images/chapter3/jan3_llc_miss_rate_large.pdf}
    \subcaption{\label{fig:llc_miss_rate_all_algs}Last level cache miss rate}
\end{subfigure}
\caption[CPU frequency, instructions per cycle, and last level cache miss rate for the eight algorithms
explored in Chapter~\ref{ch:ipdps}.]{\label{fig:all_algs}Effective frequency (GHz), instructions per cycle
(IPC), and last level cache miss rate for all algorithms as the processor power
cap is reduced.
%
For each algorithm, we use a data set size of $128^3$.
}
\end{figure*}

When looking at the CPU operating frequency in Figure~\ref{fig:freq_all_algs}, we
see that all algorithms, regardless of whether it is in the power opportunity or power
sensitive class, run at the
same frequency of 2.6 GHz at a 120W power cap, which is the maximum turbo
frequency for this architecture when all cores are active.
%
The differences across the algorithms are seen in the rate at which the
frequency declines because of the enforced power cap and the power usage of the
algorithms.

The default power usage varies across visualization algorithms, ranging
from as low as 55W up to 90W per processor.
%
For algorithms that do not consume TDP, the processor decides it can run in
turbo mode (\ie above 2.1 GHz base clock frequency) to maximize performance.
%
Once the power cap is at or below the power usage of the algorithm, the
operating frequency begins to drop because the processor can no longer maintain
a high frequency without exceeding the power cap.
%
For algorithms with a high power usage, the frequency will start dropping at
power caps close to TDP.
%
For algorithms with a low power usage (\eg contour, described previously), the
processor runs in turbo mode for most power caps to maximize performance.
%
It is not until the lowest power cap of 40W that we see a reduction in the
clock frequency for contour.

Figure~\ref{fig:ipc_all_algs} shows the average instructions per cycle (IPC) for
all algorithms.
%
The dotted line drawn at an IPC of 1 shows the divide between compute-bound
algorithms (IPC $>$ 1) and memory-bound algorithms (IPC $<$ 1).
%
Spherical clip, contour, isovolume, and threshold make up one class of
algorithms.
%
Their IPC is characteristic of a data-bound algorithm, and their power usage is
also very low, so the decrease in IPC is not seen until the lowest power cap of
40W.
%
Threshold is dominated by loads and stores of the data, so it has a
low IPC value.
%
Contour and isovolume have higher IPC values (out of this group of algorithms)
because it calculates interpolations.

Another class of algorithms (with respect to IPC) consists of ray tracing and
slice, which have an IPC that falls into compute-bound range.
%
Although they have an IPC larger than 1, they have low power usage and their
performance remains unchanged until low power caps.
%
For this study, we created an image database of 50 rendered images (either with
volume rendering or ray tracing) per visualization cycle to increase algorithm
time.
%
Investigating ray tracing further, we discover that the execution time includes the
time to gather triangles and find external faces, build a spatial acceleration
structure, and trace the rays.
%
Tracing the rays is the most compute intensive operation within ray tracing, but
it is being dominated by the data intensive operations of gathering triangles
and building the spatial acceleration structure.
%
As such, ray tracing behaves similarly to the cell-centered algorithms in this
category: spherical clip, threshold, contour, isovolume, and slice.
%
It also has the best slowdown factor.

Slice has a higher IPC than contour, which is expected since it is doing
a contour three times.
%
Three-slice creates three slice planes on $x$-$y$, $y$-$z$, and $z$-$x$ intersecting the
origin.
%
Consequently, the output size is fixed for any given time step.
%
Three-slice under the hood uses contour, but differs in the fact that each
slice plane calculates the signed distance field for each node on the mesh,
which is compute intensive.

Figure~\ref{fig:llc_miss_rate_all_algs} shows the last level cache miss rate for
all algorithms, and is the inverse of Figure~\ref{fig:ipc_all_algs}.
%
Isovolume has the highest last level cache miss rate, indicating that a high
percentage of its instruction mix is memory-related.
%
Because of the high miss rate, the isovolume algorithm spends a lot of time
waiting for memory requests to be satisfied.
%
Memory access instructions have a longer latency than compute instructions.
%
Therefore, it cannot issue as many instructions per cycle, and has a low IPC.

Another interesting metric to investigate is shown in Figure~\ref{fig:elem_sec},
which is the number of elements (in millions) processed per second.
%
Because the power usage of these algorithms is low, the denominator (\eg
seconds) stays constant for most power caps, yielding a near constant rate for each
algorithm.
%
At severe power caps, the number of elements processed per second
declines because the algorithm incurs slowdown.
%
Algorithms with very fast execution times will have a high rate, while
algorithms with a longer execution time will have a low rate.

\subsubsection{Power Sensitive Algorithms}

The power sensitive algorithms are volume rendering and particle advection.
%
They consume the most power at roughly 85W per processor.
%
When the power cap drops below 85W, the frequency starts dropping as it
can no longer maintain the desired power cap at the 2.6 GHz frequency.
%
Thus, there are slowdowns of $10\%$ at 70W and 80W, respectively, which
is at a higher power cap than the power opportunity algorithms.
%
These algorithms not only have the highest IPC values overall as shown in
Figure~\ref{fig:ipc_all_algs} (peak IPC of 2.68, highly compute-bound), but also
have the biggest change in IPC as the power cap is reduced.
%
Such algorithms are dominated by the CPU, so a reduction in power greatly
impacts the number of cycles it takes to issue the same set of instructions
(\ie slows down the algorithm).

Figure~\ref{fig:ipc_all_algs} coupled with Figure~\ref{fig:llc_miss_rate_all_algs}
shows volume rendering and particle advection with a high IPC because they have
the lowest last level cache miss rate (\ie better memory performance).
%
Additionally, more instructions can be retired per cycle because the processor
is not stalled waiting on memory requests to be satisfied (\ie high IPC).
%
Everything fit into cache, and IPC was changing drastically with changing power
caps, so we can infer that IPC behavior was dominated by compute instructions.

\subsubsection{Key Takeaways}

For most of the algorithms explored in this chapter, the power cap has little
effect on performance.
%
This is because the power usage of visualization algorithms is low compared to
typical HPC applications.
%
For similar algorithms, we can run them with the lowest power cap without
impacting performance.
%
In a larger scheme where we are running the simulation and visualization on the
same resources, we can more intelligently allocate power between the two,
rather than using a na{\"\i}ve scheme of evenly distributing the power.
%
Said another way, we can allocate most of the power to the power-hungry
simulation, leaving minimal power to the visualization, since it does not
need it.
%
Additionally, we find two of the algorithms explored (volume rendering and particle
advection) have high power usage, consistent with typical HPC
applications.
%
These algorithms have a poor tradeoff between power and performance.
%
There may be other algorithms that behave similarly.

\begin{figure}
\centering
\includegraphics[width=0.6\columnwidth]{images/chapter3/oct15_elempersec.pdf}
\caption[Number of data elements processed per second under varying power
limits for cell-centered algorithms.]{\label{fig:elem_sec}Elements processed per second for cell-centered
algorithms using $128^3$ data set size.
}
\end{figure}
