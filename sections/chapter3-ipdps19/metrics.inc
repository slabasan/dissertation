This section defines the variables and metrics that will be used
in the following results section.

\subsection{Abstract Case}
Assume a visualization algorithm takes $T_D$ seconds to run at the
default power (TDP) of $P_D$ watts.
%
As the power cap is reduced, the same visualization algorithm now takes $T_R$
seconds to run with a power cap of $P_R$ watts.
%
The following derived terms are used to explain our results:
\begin{itemize}
\item $P_{ratio}$ = $P_D$/$P_R$: This is the ratio of power caps.
%
If the processor-level power cap is reduced by a factor of 2, then $P_{ratio}$
= 2.
\item $T_{ratio}$ = $T_R$/$T_D$: This is the ratio of execution times.
%
If the algorithm takes twice as long to run, then $T_{ratio}$ = 2.
\item $F_{ratio}$ = $F_D$/$F_R$: This is the ratio of CPU frequencies. If the
frequency was twice as slow, then $F_{ratio}$ = 2.
\end{itemize}
%
These terms have been defined such that all ratios will be greater than 1.
%
To accomplish this, $P_{ratio}$ and $F_{ratio}$ have the default value in the
numerator and the reduced value in the denominator, while $T_{ratio}$ has them
reversed.
%
Inverting the ratio simplifies our comparisons.

Using our three ratios, we can make the following conclusions.
%
First, if $T_{ratio}$ is less than $P_{ratio}$,
then the algorithm was sufficiently data intensive to avoid a slowdown equal to
the reduction in power cap.
%
In addition, users can make a tradeoff between running their algorithm
$T_{ratio}$ times slower and using $P_{ratio}$ less times power.
%
Alternatively, this ratio enables us to optimize performance under a given
power cap.
%
Second, the relationships between $F_{ratio}$ and $P_{ratio}$ and $T_{ratio}$
and $F_{ratio}$ will be architecture-specific.
%
Enforcing a power cap will lower the CPU frequency, however, the reduction in
frequency will be determined by the processor itself.
%
The reduction in clock frequency may slowdown the application proportionally
(if the application is compute-bound) or not at all (if the application is
memory-bound).
%
The results in Section~\ref{sec:ch3-results} present the ratios for a particular
Intel processor (\ie Broadwell), but this relationship may change across
other architectures.

\subsection{Performance Measurements}
To collect power usage information, the energy usage of each
processor in the node is sampled
every 100 ms throughout the application (\ie
simulation and visualization) execution.
%
The power usage for each processor
is calculated by dividing the
energy usage (contained in a 64-bit register) by the elapsed time between samples.
%
In addition to energy and power counters, we also sample fixed counters,
frequency-related counters, and two programmable counters ---
last level cache misses and references.
%
From these counters, we can derive the following metrics.
%
We show the derivation of these metrics using the Intel-specific performance
counter event names~\cite{intelpmon}, where applicable.
%
\begin{itemize}
%
\item Effective CPU frequency = \verb|APERF/MPERF|
%
\item Instructions per cycle (IPC) = \verb|INST_RET.ANY/CPU_CLK_UNHALT.REF_TSC|
%
\item Last level cache miss rate = \verb|LONG_LAT_CACHE.MISS/LONG_LAT_CACHE.REF|
%
\end{itemize}

\subsection{Efficiency Metric}
We leverage a
rate in terms of the size of the input (\ie data set size) rather
than speedup
for comparing the efficiency of one visualization algorithm to another.
%
If the speedup of a parallel algorithm is defined as $\frac{T_{n,1}}{T_{n,p}}$,
then one must know the serial execution time of the algorithm.
%
This is challenging with increasingly complex simulations running
at higher concurrency levels.
%
Instead, we assess speedup using a rate originally proposed by Moreland and
Oldfield~\cite{Kaminsky:2016:BCB:3066343,10.1007/978-3-319-20119-1_34}.
%
They express the rate in terms of the data set size, $n$, as follows:
$\frac{n}{T_{n,p}}$.

The higher the resulting rate, the more efficient the algorithm.
%
Because the rate is computed using the size of the data set, we only compare
those algorithms that iterate over each cell in the data set (\eg contour,
spherical clip, isovolume, threshold, and slice).
%
At higher concurrencies, an algorithm with good scaling will show an upward
incline, then will gradually flatten from the perfect efficiency curve.
