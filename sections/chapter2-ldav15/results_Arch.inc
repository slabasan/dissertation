\subsection{Phase 6: Architecture}

Phase 6 did not build on any previous phases.
%
Instead, it explored CPU2, whose results do not translate to any of the previous
CPU1 experiments.
%
The factors held constant were: MPI, 24 cores on CPU2, Enzo-10M, and the BaselineImplementation.
%
Table~\ref{table:phase6-mpi} contains the results.

\begin{table}[h!]
\centering
\begin{tabular}{||c|c|c|c|c|c|c|c||}
\hline
$F$   & $F_{rat}$ & $T$     & $T_{rat}$ & $E$   & $E_{rat}$ & $P$     & $P_{rat}$ \\
\hline
2.4GHz & 1X        & 2.265s & 1X        & 549J & 1X        & 242.4W & 1X        \\
2.2GHz & 1.1X      & 2.479s & 1.1X      & 558J & 1X        & 225W   & 1.1X      \\
2.0GHz & 1.2X      & 2.695s & 1.2X      & 571J & 1X        & 211.9W & 1.1X      \\
1.8GHz & 1.3X      & 3.024s & 1.3X      & 573J & 1X        & 189.5W & 1.3X      \\
1.6GHz & 1.5X      & 3.385s & 1.5X      & 631J & 0.9X      & 186.4W & 1.3X      \\
1.4GHz & 1.7X      & 3.836s & 1.7X      & 668J & 0.8X      & 174.1W & 1.4X      \\
1.2GHz & 2X        & 4.466s & 2X        & 697J & 0.8X      & 156W   & 1.6X      \\
\hline
\end{tabular}
\caption[Results for the baseline isosurfacing OpenMP implementation on a
hardware architecture with a shared clock frequency between the memory and
compute units.]{Experiment results from Phase 6, which uses
CPU2 with MPI and the BaselineImplementation.}
\label{table:phase6-mpi}
\end{table}

CPU2 is significantly different than CPU1 in that it contains
Ivy Bridge processors,
while CPU1 contains Haswell processors.
%
On Haswells, the core (compute units, private L1 and L2
caches) and uncore (shared L3 cache) are on separate clock domains, so slowing
down the frequency only applies to the speed of the executing instructions and
accessing L1 and L2 caches.
%
On Ivy Bridge, core and uncore share the same clock frequency, and so
data-intensive workloads cannot benefit with respect to $T_{rat}$.

Table~\ref{table:phase6-mpi} shows that, while $P_{rat}$ is better
at lower clock frequencies, $E_{rat}$ is worse.
%
Restated, while the power dropped, its drop was not steep enough to offset
the increases in runtime, and so overall energy usage goes up.
%
This does not match the results in Phase 5, where a compute-bound workload
created a similar ``$T_{rat}$ equals $F_{rat}$" situation.
%
As explanation, we again note the non-linear relationship between power
and clock frequency (which varies over architecture).
