\subsection{Phase 5: Algorithm Implementation}

Phase 5 once again went back to Phase 1 as a starting point,
this time extending the experiments to consider multiple algorithm
implementations.
%
The factors held constant were: OpenMP, 4 cores on CPU1, and the Enzo-10M
data set.
%
Table~\ref{table:gen_cpu1_mpi_enzo10} contains the results.

\begin{table}[h]
\centering
\begin{tabular}{||c|c|c|c|c|c|c|c|c||}
\hline
$F$   & $F_{rat}$ & $T$       & $T_{rat}$ & $E$       & $E_{rat}$ & $P$    & $P_{rat}$ \\
\hline
3.5GHz & 1X        & 16.06s  & 1X        & 1056J & 1X        & 65.8W & 1X        \\
3.3GHz & 1.1X      & 16.57s  & 1X        & 992J  & 1.1X      & 59.9W & 1.1X      \\
3.1GHz & 1.1X      & 17.64s  & 1.1X      & 950J  & 1.1X      & 53.9W & 1.2X      \\
2.9GHz & 1.2X      & 19.00s  & 1.3X      & 928J  & 1.1X      & 48.8W & 1.3X      \\
2.7GHz & 1.3X      & 20.85s  & 1.3X      & 914J  & 1.2X      & 43.9W & 1.5X      \\
2.5GHz & 1.4X      & 21.82s  & 1.4X      & 876J  & 1.2X      & 40.1W & 1.6X      \\
2.3GHz & 1.5X      & 24.01s  & 1.4X      & 784J  & 1.3X      & 32.7W & 2X        \\
2.1GHz & 1.7X      & 26.09s  & 1.7X      & 763J  & 1.4X      & 29.3W & 2.2X      \\
2.0GHz & 1.8X      & 27.43s  & 1.7X      & 768J  & 1.4X      & 28.0W & 2.4X      \\
1.8GHz & 1.9X      & 30.67s  & 1.9X        & 764J  & 1.4X      & 24.9W & 2.6X      \\
1.6GHz & 2.2X      & 34.17s  & 2.1X        & 756J  & 1.4X      & 22.1W & 3X        \\
\hline
\end{tabular}
\caption[Results for the VTK isosurfacing OpenMP implementation on the Enzo
data set as the CPU clock frequency is reduced.]{Experiment results for
GeneralImplementation of Phase 5.
These results compare with BaselineImplementation,
whose corresponding results are in
Table~\ref{table:custom_cpu1_omp_enzo10}.}
\label{table:gen_cpu1_mpi_enzo10}
\end{table}

With GeneralImplementation, runtime and clock frequency are highly correlated,
\ie reducing the clock frequency by 2.2 causes the workload
to take 2.1X longer to run.
%
This relationship between frequency and runtime is characteristic of a
compute-intensive workload, depicted by our \emph{computeBound}
micro-benchmark.
%
In contrast, the BaselineImplementation exhibited behavior closer
to data-intensive in our previous phases.

The explanation for the difference between the
two implementations is in the number of instructions.
%
While both issue the same number of loads and stores,
the GeneralImplementation issues 102 billion instructions, while the
BaselineImplementation issues only 7 billion.
%
These additional instructions change the nature of the computation
(from somewhat data-intensive to almost entirely compute intensive),
as well as making the overall runtimes and energy consumption much higher.
%
Of course, these instructions add value for general toolkits, in terms of
supporting more data models and algorithms.
%
The takeaway from this study is that the approach from general toolkits appears
to tilt the instruction mix (at least for isosurfacing).

Interestingly, the $E_{rat}$ and $P_{rat}$ ratios are still favorable, at
1.4X and 3X, respectively.
%
This is because the relationship between clock frequency and energy consumed
is not strictly linear.
%
As a result, even compute-intensive workloads can benefit from clock frequency reductions,
although their $T_{rat}$'s will still match the clock frequency reduction.
