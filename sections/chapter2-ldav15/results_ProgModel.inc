\subsection{Phase 3: Parallel Programming Models}

\begin{table}[h]
\centering
\begin{tabular}{||c|c|c|c|c|c|c|c||}
\hline
$F$ & $F_{rat}$ & $T$    & $T_{rat}$ & $E$    & $E_{rat}$ & $P$  & $P_{rat}$ \\
\hline
3.5GHz  & 1X     & 1.08s & 1X        & 74.5J  & 1X        & 69.2W & 1X     \\
3.3GHz  & 1.1X   & 1.12s & 1X        & 70.4J  & 1.1X      & 62.7W & 1.1X   \\
3.1GHz  & 1.1X   & 1.18s  & 1.1X      & 67.3J  & 1.1X      & 57.0W & 1.2X   \\
2.9GHz  & 1.2X   & 1.20s & 1.1X      & 66.2J  & 1.1X      & 55.0W & 1.3X   \\
2.7GHz  & 1.3X   & 1.35s & 1.3X      & 63.5J  & 1.2X      & 47.1W & 1.5X   \\
2.5GHz  & 1.4X   & 1.36s & 1.3X      & 59.8J  & 1.2X      & 43.9W & 1.6X   \\
2.3GHz  & 1.5X   & 1.46s & 1.4X      & 55.3J & 1.3X      & 37.8W & 1.8X   \\
2.1GHz  & 1.7X   & 1.59s & 1.4X      & 51.7J & 1.4X      & 32.6W & 2.1X   \\
2.0GHz  & 1.8X   & 1.80s & 1.7X      & 55.4J & 1.3X      & 30.8W & 2.2X   \\
1.8GHz  & 1.9X   & 1.92s & 1.7X      & 52.6J & 1.4X      & 27.4W & 2.5X   \\
1.6GHz  & 2.2X   & 2.08s & 2X        & 51.8J & 1.4X      & 24.9W & 2.8X   \\
\hline
\end{tabular}
\caption[Results from the baseline isosurfacing MPI implementation on the Enzo data
set.]{Experiment results from Phase 3 for the
Enzo-10M data set, which uses MPI and the
BaselineImplementation.}
\label{table:custom_cpu1_mpi_enzo10}
\end{table}

\begin{table}[h!]
\centering
\begin{tabular}{||c|c|c|c|c|c|c|c||}
\hline
$F$    & $F_{rat}$ & $T$     & $T_{rat}$ & $E$      & $E_{rat}$ & $P$     & $P_{rat}$ \\
\hline
3.5GHz  & 1X        & 3.46s & 1X        & 179.5J & 1X        & 51.9W & 1X     \\
3.3GHz  & 1.1X      & 3.48s & 1X        & 166.8J & 1.1X      & 47.9W & 1.1X   \\
3.1GHz  & 1.1X      & 3.59s & 1X        & 158.9J & 1.1X      & 44.2W & 1.2X   \\
2.9GHz  & 1.2X      & 3.62s & 1X        & 147.7J & 1.2X      & 40.8W & 1.3X   \\
2.7GHz  & 1.3X      & 3.78s & 1.1X      & 143.0J & 1.3X      & 37.9W & 1.4X   \\
2.5GHz  & 1.4X      & 3.88s & 1.1X      & 135.4J & 1.3X      & 34.9W & 1.5X   \\
2.3GHz  & 1.5X      & 4.00s & 1.1X      & 116.2J & 1.5X      & 29.1W & 1.8X   \\
2.1GHz  & 1.7X      & 4.18s & 1.3X      & 108.0J & 1.7X      & 25.8W & 2X     \\
2.0GHz  & 1.8X      & 4.29s & 1.3X      & 109.8J & 1.6X      & 25.6W & 2X     \\
1.8GHz  & 1.9X      & 4.52s & 1.3X      & 105.0J & 1.7X      & 23.2W & 2.2X   \\
1.6GHz  & 2.2X      & 4.62s & 1.4X      & 95.5J & 1.9X      & 20.7W & 2.5X   \\
\hline
\end{tabular}
\caption[Results from the baseline isosurfacing MPI implementation on the
randomized Enzo data set.]{Experiment results from Phase 3 for
the REnzo-10M data set, which uses MPI and the
BaselineImplementation.}
\label{table:custom_cpu1_mpi_renzo10}
\end{table}

Phase 3 extended Phase 2 by varying over parallel programming model.
%
Figure \ref{fig:phase3-progmodel} shows the overall results for all eight data
sets using MPI; it can be compared with
Figure~\ref{fig:POWERphase2-omp}
of Section~\ref{sec:ch2-results_dataset},
which did the same analysis with OpenMP.
%
Tables \ref{table:custom_cpu1_mpi_enzo10} and
\ref{table:custom_cpu1_mpi_renzo10} show the results using MPI on the
Enzo-10M and REnzo-10M data sets, respectively.
%
Table~\ref{table:custom_cpu1_omp_enzo10} of Section~\ref{sec:ch2-basecase}
and Table~\ref{table:custom_cpu1_omp_renzo10} of
Section~\ref{sec:ch2-results_dataset}
are also useful for comparison, as they showed the
results for these same data sets using OpenMP.

In terms of our three ratios:
%
\begin{itemize}
    \item $F_{rat}$ and $T_{rat}$: The right sub-figure of Figure~\ref{fig:phase3-progmodel} shows two clusters: one grouping (made up of the randomized data sets) slows down only by a factor of
{\textasciitilde}1.4,
while the other grouping (made up of the non-randomized data sets) slows down in near proportion with the clock frequency reduction.
%
This contrasts with the OpenMP tests seen in Figure~\ref{fig:POWERphase2-omp}, which
showed more spread over these two extremes.
%
We conclude that the randomized data sets create significantly more
memory activity for MPI than for OpenMP,
which is supported by our performance measurements.
%
Taking REnzo-80M as an example, the MPI test had over 48,000 L3 cache misses per million
cycles, while the OpenMP test had less than 12,500.
    \item $T_{rat}$ and $E_{rat}$:
Renzo-10M with MPI gave the largest energy savings of any test we ran, going
from 179.5J to 95.5J.
%
That said, its starting point was higher than OpenMP, which went from 142.7J
to 82.1J.
%
Overall, energy savings were harder to predict with MPI, but were generally
better than the savings with OpenMP (again because it was using more energy
to start with).

    \item $T_{rat}$ and $P_{rat}$: the MPI tests used more power, but saw
      greater reduction when dropping the clock frequency.
      For the Enzo-10M data set, the MPI test dropped from 72.2W (3.5GHz)
      to 25.3W (1.6GHz), while OpenMP dropped from 57.4W to 21.4W.
      MPI's increased power usage likely derives from activity with the memory
      system, and increased L3 cache misses.
\end{itemize}

Summarizing, our performance measurements show that the MPI approach uses the
memory infrastructure less efficiently, leading to increased energy and power
usage, but also creating improved propositions for reducing energy and power
when reducing clock frequencies.
