\subsection{Phase 2: Data Set}
\label{sec:ch2-results_dataset}

Phase 2 extended Phase 1 by varying over data set.
%
Table~\ref{table:custom_cpu1_omp_renzo10} shows specific results
for the REnzo-10M data set (which compares with the Enzo-10M data set in
Table~\ref{table:custom_cpu1_omp_enzo10} of Section~\ref{sec:ch2-basecase}),
and Figure~\ref{fig:POWERphase2-omp} shows aggregate results over
all data sets.

In terms of our three ratios:
\begin{itemize}
\item $F_{rat}$ and $T_{rat}$: The right sub-figure of
Figure~\ref{fig:POWERphase2-omp} shows that the slowdown factor
varies over data set.
%
In the worst case, for the Enzo-1M data set, the slowdown factor is
at 2.2X --- \ie exactly 3.5 GHz over 1.6 GHz --- meaning that it is
performing like a computationally-intensive workload.
%
This makes sense, however, since Enzo-1M is our smallest data set, and
it has a regular data access pattern.
%
\item $T_{rat}$ and $E_{rat}$: This tradeoff varies based on data set.
The data sets with randomized access patterns (REnzo, RNek) have better
propositions, as do large data sets.
%
Also, when comparing Table~\ref{table:custom_cpu1_omp_renzo10}
and Table~\ref{table:custom_cpu1_omp_enzo10}, we can see that the
tradeoffs got more favorable with REnzo-10M, with energy savings of 1.7X against
slowdowns of 1.4X (where it was 1.44X and 1.84X for Enzo-10M).
%
\item $T_{rat}$ and $P_{rat}$: Table~\ref{table:custom_cpu1_omp_renzo10} shows us that the power tradeoff
for REnzo-10M is slightly worse than Enzo-10M.
%
We attribute the increase in instantaneous power to increased data intensity
(see Table~\ref{table:datasets_perf}).
\end{itemize}

\input{sections/chapter2-ldav15/results_tables.inc}

The performance measurements listed in Table~\ref{table:datasets_perf}
help explain the differences between the data sets.
%
Specifically, the L3 miss rate (unsurprisingly) goes up when data sets
get larger and their accesses become randomized.
%
This in turn pushes down the number of instructions per cycle
(a surrogate for capturing how many stalls are occurring in the pipeline,
which is difficult to measure).

\begin{table}[h]
\centering
\begin{tabular}{||c|c|c|c|c||}
\hline
Data Set  & Time    & Cycles & 	IPC 	& 	L3 Miss Rate \\ \hline
Enzo-1M   & 0.39s	& 614M	 &	1.42	&	597 \\
Enzo-10M  & 2.40s	& 3.0B	 &	1.89	&	1027 \\
Enzo-80M  & 13.2s	& 18B	 &	2.24	&	1422 \\
Nek5000   & 14.3s	& 20B	 &	1.54	&	949 \\
REnzo-1M  & 0.44s	& 700M	 &	1.17	&	5420 \\
REnzo-10M & 4.2s	& 6.0B	 & 	0.94	&	10913 \\
REnzo-80M & 33.9s	& 51B	 &	0.78	&	12543 \\
RNek5000  & 27.2s	& 38B	 &	0.81	&	11593 \\ \hline
\end{tabular}
\caption[Comparing performance metrics at 1.6 GHz clock frequency for the
baseline isosurfacing OpenMP implementation across all data
sets defined in Chapter~\ref{ch:ldav}.]{Performance measurements for the 1.6 GHz experiments from Phase 2.
IPC is short for Instructions Per Cycle,
and the L3 Miss Rate is the number of L3 cache misses per one million cycles.}
\label{table:datasets_perf}
\end{table}

\input{sections/chapter2-ldav15/results_figures.inc}
