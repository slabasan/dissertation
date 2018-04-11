\subsection{Phase 1: Base Case}
\label{sec:ch2-basecase}

Phase 1 fixed all factors except clock frequency, to provide a baseline for
future phases.
%
The factors held constant were: BaselineImplementation, OpenMP, 4 cores on
CPU1, and the Enzo-10M data set.
%
Table~\ref{table:custom_cpu1_omp_enzo10} contains the results.

In terms of our three ratios:
\begin{itemize}
%
\item $F_{rat}$ and $T_{rat}$: At the slowest clock speed (1.6 GHz),
$F_{rat}$ was 2.2X, but $T_{rat}$ was 1.84X, meaning that the program
was not slowing down proportionally.
%
A purely compute-intensive program that took 1.29s at 3.5 GHz would have
taken 2.82s at 1.6 GHz, while our isosurfacing program took 2.40s (\ie 17\% faster).
%
\item $T_{rat}$ and $E_{rat}$: Energy savings of up to 1.44X can be gained
by accepting slowdowns of up to 1.84X.
%
Clock frequencies in between the extremes offer propositions with
less energy savings, but also less impact on runtime.
%
\item $T_{rat}$ and $P_{rat}$: Power savings of up to 2.7X can be gained
by accepting slowdowns of up to 1.84X.
%
The power savings are greater than the energy savings since the energy
accounts for reduced runtime, while the power only speaks to instantaneous
usage.
%
Regardless, such power savings could be useful when running complex
systems with a fixed power budget.
\end{itemize}
