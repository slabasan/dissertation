\begin{table}[ht!]
\centering
\begin{tabular}{||c|c|c|c|c|c|c|c||}
\hline
$F$    & $F_{rat}$ & $T$     & $T_{rat}$ & $E$      & $E_{rat}$ & $P$     & $P_{rat}$ \\
\hline
3.5GHz  & 1X        & 1.29s & 1X        & 74.3J  & 1X        & 57.4W  & 1X      \\
3.3GHz  & 1.1X      & 1.32s & 1X        & 69.4J  & 1.1X      & 52.6W  & 1.1X    \\
3.1GHz  & 1.1X      & 1.38s & 1.1X      & 66.7J  & 1.1X      & 48.2W  & 1.2X    \\
2.9GHz  & 1.2X      & 1.42s & 1.1X      & 63.4J  & 1.2X      & 44.8W  & 1.3X    \\
2.7GHz  & 1.3X      & 1.50s & 1.2X      & 61.5J  & 1.2X      & 40.9W  & 1.4X    \\
2.5GHz  & 1.4X      & 1.62s & 1.3X      & 60.9J  & 1.2X      & 37.5W  & 1.6X    \\
2.3GHz  & 1.5X      & 1.78s & 1.4X      & 53.7J  & 1.4X      & 30.1W & 1.9X    \\
2.1GHz  & 1.7X      & 1.93s & 1.5X      & 53.8J  & 1.4X      & 27.9W  & 2.1X    \\
2.0GHz  & 1.8X      & 1.95s & 1.5X      & 52.1J  & 1.4X      & 26.8W  & 2.2X    \\
1.8GHz  & 1.9X      & 2.13s & 1.7X      & 51.1J  & 1.4X      & 24.1W  & 2.4X    \\
1.6GHz  & 2.2X      & 2.40s & 1.9X      & 51.4J  & 1.4X      & 21.4W  & 2.7X    \\
\hline
\end{tabular}
\caption[Results for the baseline isosurfacing OpenMP implementation on the Enzo
data set as the CPU clock frequency is reduced.]{Experiment results
for Phase 1,
which uses OpenMP and the BaselineImplementation.}
\label{table:custom_cpu1_omp_enzo10}
\end{table}

\begin{table}[ht!]
\centering
\begin{tabular}{||c|c|c|c|c|c|c|c||}
\hline
$F$   & $F_{rat}$ & $T$     & $T_{rat}$ & $E$      & $E_{rat}$ & $P$ & $P_{rat}$ \\
\hline
3.5GHz & 1X        & 2.95s & 1X        & 142.7J  & 1X        & 48.4W  & 1X        \\
3.3GHz & 1.1X      & 3.05s & 1X        & 134.8J  & 1.1X      & 44.2W  & 1.1X      \\
3.1GHz & 1.1X      & 3.01s & 1X        & 124.3J  & 1.1X      & 41.3W  & 1.2X      \\
2.9GHz & 1.2X      & 3.33s & 1.1X      & 122.3J  & 1.2X      & 36.8W  & 1.3X      \\
2.7GHz & 1.3X      & 3.23s & 1.1X      & 109.3J  & 1.3X      & 33.8W  & 1.4X      \\
2.5GHz & 1.4X      & 3.22s & 1.1X      & 99.6J   & 1.4X      & 30.9W  & 1.6X      \\
2.3GHz & 1.5X      & 3.48s & 1.3X      & 93.4J   & 1.5X      & 26.8W  & 1.8X      \\
2.1GHz & 1.7X      & 3.49s & 1.3X      & 88.0J     & 1.6X      & 25.2W  & 1.9X      \\
2.0GHz & 1.8X      & 3.79s & 1.3X      & 88.3J   & 1.6X      & 23.3W  & 2.1X      \\
1.8GHz & 1.9X      & 3.79s & 1.3X      & 82.2J   & 1.7X      & 21.7W  & 2.2X      \\
1.6GHz & 2.2X      & 4.19s  & 1.4X      & 82.1J   & 1.7X      & 19.6W  & 2.5X      \\
\hline
\end{tabular}
\caption[Results for the baseline isosurfacing OpenMP implementation on the randomized
Enzo data set as the clock frequency is reduced.]{Experiment results for the REnzo-10M data set in Phase 2, which uses
OpenMP and the BaselineImplementation.}
\label{table:custom_cpu1_omp_renzo10}
\end{table}
