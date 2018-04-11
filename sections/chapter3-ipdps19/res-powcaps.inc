\subsection{Phase 1: Processor-Level Power Cap}
\label{sec:ch3-res-powcaps}

\begin{table}[]
\centering
\begin{tabular}{||c|c|c|c|c|c||}
\hline
\multicolumn{6}{||c||}{Contour} \\
\hline
$P$ & $P_{ratio}$ & $T$ & $T_{ratio}$ & $F$ & $F_{ratio}$ \\
\hline
120W & 1.0X & 33.477s & 1.00X & 2.55GHz & 1.00X \\
110W & 1.1X & 33.543s & 1.00X & 2.41GHz & 1.06X \\
100W & 1.2X & 33.579s & 1.00X & 2.55GHz & 1.00X \\
90W  & 1.3X & 33.519s & 1.00X & 2.55GHz & 1.00X \\
80W  & 1.5X & 33.617s & 1.00X & 2.54GHz & 1.01X \\
70W  & 1.7X & 30.371s & 0.91X & 2.54GHz & 1.00X \\
60W  & 2.0X & 30.394s & 0.91X & 2.50GHz & 1.02X \\
50W  & 2.4X & 31.066s & 0.93X & 2.52GHz & 1.01X \\
40W  & 3.0X & 39.198s & \fix{1.17X} & 2.07GHz & \fix{1.23X} \\
\hline
\end{tabular}
\caption[Performance of the VTK-m contour algorithm with a data set size of $128^3$
under reduced processor power limits.]{\label{table:contour_128_2}The slowdown for the contour
algorithm as the processor power cap is reduced.
%
The configuration used for this algorithm is a data set size of $128^3$.
%
$P$ is the enforced processor power cap.
%
$T$ is the total execution time in seconds for the contour algorithm over all
visualization cycles.
%
$F$ is the effective CPU frequency given the power cap $P$.
%
A 10\% slowdown (denoted in red) does not occur for this algorithm until the
lowest power cap.
%
}
\end{table}

In this phase, we fix all study factors while varying the power cap in order to
achieve a baseline performance for subsequent phases.
%
Specifically, we use the following configuration: contour algorithm and a data set
size of $128^3$.
%
We present the results in Table~\ref{table:contour_128_2}.

When the default power cap of 120W is applied to each processor, the simulation
spends a total of 33.477 seconds executing a contour filter and the total
power usage of both processors is 120W (88\% of total node power).
%
As we gradually reduce the processor-level power cap, the execution time
remains constant (\eg $T_{ratio}$ is 1X).
%
Since the algorithm is data intensive, it does not use a lot of power.
%
Applying a more stringent power cap does not affect the overall performance
as it is not using power equivalent to the desired power cap, so the
underlying frequency does not need to slowdown.

Once the power cap is reduced by a factor of 3X (from 120W down to 40W), we see
a change in the execution time and CPU frequency by a factor of 1.17X and
1.23X, respectively.
%
At 40W, the algorithm takes longer to run (since the frequency is also
reduced to maintain the desired power usage), but the algorithm did not
slowdown proportionally to the reduction in power by a factor of 3.
%
This confirms our finding in \cite{7348074}, where we determined that the
contour algorithm was sufficiently data intensive to avoid slowing down
proportional to the CPU clock frequency.

Running with the lowest power cap does not impact the performance for contour.
%
If doing a contour post hoc, the user can request the lowest power, leaving
power for other applications that are competing for the same
compute resources.
%
If doing a contour in situ, the runtime system may leverage the low power
characteristic and dynamically allocate less power to the visualization phase,
allowing more power to be dedicated to the simulation.
