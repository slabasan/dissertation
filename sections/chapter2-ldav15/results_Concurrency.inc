\subsection{Phase 4: Concurrency}

Phase 4 did not build on Phase 3, but rather went back to Phase 1 and
extended it by considering multiple concurrency levels and
programming models.
%
Figure~\ref{fig:phase4-omp} shows plots of our results with OpenMP
and Figure~\ref{fig:phase4-mpi} shows the results with MPI.
%
Table~\ref{tab:concurrencyL3} contains data that complements
the figures.

Higher levels of concurrency issue more memory requests,
leading to saturation of the memory infrastructure.
%
As a result, runtimes steadily increase.
%
Because some processes may have to wait for the memory infrastructure to
satisfy requests, we observed energy savings by slowing down the clock
frequency, making waiting processes consume less power and
having their memory requests satisfied more quickly
(relative to the number of cycles, since cycles lasted longer).
%
Table~\ref{tab:concurrencyL3} shows this trend, in particular that the
four core configurations overwhelm their memory (as seen in
the increase in L3 cache misses and in the
reduction in instructions per cycle), while
the one core configurations fare better.

In terms of our three ratios:
\begin{itemize}
\item $F_{rat}$ and $T_{rat}$: The right sub-figures of
Figures~\ref{fig:phase4-omp} and~\ref{fig:phase4-mpi}
show that the slowdown factor varies over concurrency.
%
Lower concurrencies (which have faster runtimes) have higher
slowdowns, because their memory accesses are being
supported by the caching system.
%
Higher concurrencies (which have longer runtimes) have
lower slowdowns, because the cache was not keeping
up as well at high clock frequencies (since more
processors were issuing competing requests).
%
\item $T_{rat}$ and $E_{rat}$:
The tradeoff between slowdown and energy varies quite a bit over concurrency.
%
With OpenMP, a single core suffers over a 2X slowdown to receive a 1.2X energy savings.
%
But, with four cores, the slowdown improves to 1.86X and the energy savings improve to 1.45X.
%
With MPI, the trends are similar, but less pronounced.
%
\item $T_{rat}$ and $P_{rat}$: As seen in Table \ref{tab:concurrencyL3},
the power savings get better as more cores are used, but not dramatically so.
%
With one core, both OpenMP and MPI provide 2.5X power improvements by dropping
the clock frequency.
%
Going up to four cores raises this power improvement to 2.85 (MPI) and 2.68
(OpenMP).
\end{itemize}

\begin{table}[h]
\centering
\begin{tabular}{||c|c|c|c|c|c||}
\hline
Configuration   & Time & Energy & Power & IPC & L3 Miss Rate \\ \hline
MPI/1/3.5 GHz	& 0.90s	& 24.4J & 26.9W & 2.37 & 5652 \\
MPI/1/1.6 GHz	& 2.0s	& 21.1J & 10.8W & 2.41 & 3788 \\
OpenMP/1/3.5 GHz & 0.83s & 19.9J & 23.9W & 2.06 & 1697 \\
OpenMP/1/1.6 GHz & 1.74s & 16.7J & 9.6W & 2.11 & 931 \\ \hline
MPI/4/3.5 GHz	& 0.96s	& 69.5J & 72.2W & 2.07 & 10476 \\
MPI/4/1.6 GHz	& 2.02s & 51.2J & 25.3W & 2.37 & 3456 \\
OpenMP/4/3.5 GHz & 1.29s & 74.3J & 57.4W & 1.51 & 3351 \\
OpenMP/4/1.6 GHz & 2.40s & 51.1J & 21.4W & 1.89 & 1027 \\ \hline
\end{tabular}
\caption[Comparing performance metrics for the baseline isosurfacing
OpenMP and MPI implementations at varying concurrency levels.]
{Experiment results from Phase 4.  IPC is short for Instructions Per Cycle, and
L3 is the number of L3 cache
misses per one million cycles.}
\label{tab:concurrencyL3}
\end{table}
