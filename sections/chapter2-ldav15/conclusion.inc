We conducted a study exploring the tradeoffs between power and performance when
reducing clock frequencies.
%
As a result of this initial study, we identified that favorable power and
performance tradeoffs are possible for a common visualization algorithm when
the CPU clock frequency is reduced.
%
More specifically, the isosurfacing algorithm exposes variation, and can be
sufficiently data intensive to avoid a performance slowdown with energy
savings.
%
We summarize the results of our findings by phase:
%
\begin{itemize}
%
\item Phase 1 confirmed our basic hypotheses about reducing clock frequencies:
%
(i) Isosurfacing is sufficiently data-intensive to slow the impact from reduced
clock frequencies.
%
(ii) Clock frequency reductions can create options for visualization consumers
to choose between finishing an algorithm quickly using more energy, or slowly
using less energy.
%
(iii) Clock frequency reductions decrease power usage, creating options for
visualization consumers wanting to balance system-wide power usage.
%
\item Phase 2 showed that the tradeoffs between energy and runtime get
increasingly favorable as data complexity goes up (either due to size of
increased irregularity in data access).
%
\item Phase 3 showed that MPI's less coordinated memory accesses affect energy
and power tradeoffs compared to OpenMP.
%
\item Phase 4 showed that the tradeoffs between execution time and energy are
most favorable when the memory infrastructure is being stressed, and that this
scenario exists at higher concurrencies (or, alternatively, is less likely to
exist when some of a node's cores are not being used).
%
\item Phase 5 showed that general-purpose implementations of visualization
algorithms shift the instruction mix such that the tradeoffs between execution
time and energy are less favorable.
%
\item Phase 6 showed the importance of having an architecture where the memory
infrastructure can be controlled separately from the CPU.
%
\end{itemize}

In terms of future work, we want to explore the variation in a wider set of
visualization workloads.
%
While we feel isosurfacing is representative of many visualization algorithms ---
\ie those characterized by iterating on cells one-by-one and producing a new output ---
other algorithms have different properties.
%
In particular, particle advection problems perform data-dependent memory
accesses, which may produce even more favorable propositions for energy and
power savings.
%
Further, algorithms like volume rendering require both significant computation
and irregular memory accesses (especially for unstructured grids), making it unclear
how it would be affected by changes in clock frequency.
%
We investigate the power and performance tradeoffs of other visualization
workloads in Chapter~\ref{ch:ipdps}.
