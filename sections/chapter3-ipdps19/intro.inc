Power is one of the major challenges in reaching the next generation of
supercomputers.
%
Scaling current technologies to exascale may result in untenable power costs.
%
Thus, the entire HPC ecosystem, including hardware and software, is being
re-designed with power efficiency in mind.

The premise of this research is that simulations and visualization routines
(and other components of the HPC ecosystem) will operate in a
power-limited environment.
%
The Tokyo Institute of Technology in Japan is one example of a facility that
has deployed power-limited production systems~\cite{8425478}.
%
Two of their systems --- TSUBAME2 and TSUBAME3 --- must share the
facility-level power budget (\ie inter-system power capping).
%
Additionally, due to extreme heat during the summer months, the resource manager
may dynamically turn off nodes to stay under a specified power cap.

At exascale, it is expected that visualization routines will need to be
run simultaneously with simulations (\ie \emph{in situ} processing), due to
decreasing I/O performance relative to floating point operations.
%
Further, power-limited environments will greatly impact the overall
time-to-solution.
%
Efforts to optimize performance under a power bound has typically focused on
traditional HPC workloads rather than visualization, which can be a significant
portion of the overall execution time.
%
Furter, visualization applications are more data intensive than
traditional HPC workloads.

For any simulation, the amount of time dedicated to in situ visualization can
vary.
%
It is dependent on a myriad of factors including the type of analysis to be
completed and the number of operations in the visualization pipeline.
%
From experience, visualization may account for 10\%--20\% of the overall
execution time spent running the simulation and the visualization.

The main contribution of this work is providing the foundation for future
research in this area, which has very few efforts exploring the performance
behaviors of visualization algorithms in a power-limited environment.
%
We believe a study focusing on visualization applications is needed for three
main reasons.
%
First, visualization is a key phase in the scientific discovery process,
transforming abstract data into a comprehensible image useful for
communication and exploration.
%
Second, the time to do visualization is often a significant portion of
the overall execution time.
%
Third, visualization algorithms are more data intensive than HPC applications.

We selected eight common visualization algorithms, which we believe are
representative of the execution behaviors of the hundreds of existing
visualization algorithms.
%
We also selected four data set sizes and varied the processor-level power cap
to understand how the changes affect power and performance properties.

The results of this study identify two classes of algorithms.
%
The first class contains compute-bound algorithms (\textbf{power sensitive}).
%
The performance of these algorithms is sensitive to the processor-level power
cap, so limiting its available power significantly degrades the
performance.
%
The second class contains memory-bound algorithms, which provide a unique
opportunity for power savings without sacrificing execution time (\textbf{power
opportunity}).
%
Our findings may be integrated into a runtime system that assigns power between
a simulation and visualization application running concurrently under a power
budget, such that overall performance is maximized.

The rest of this chapter is organized as follows.
%
Section~\ref{sec:ch3-relwork} discusses previous work.
%
Section~\ref{sec:ch3-motivation} provides an overview of power in HPC and the
algorithms explored.
%
The details of the experimental setup and methodology are presented in
Section~\ref{sec:ch3-study}.
%
We define the metrics and variables used in Section~\ref{sec:ch3-metrics}.
%
Results are discussed in Section~\ref{sec:ch3-results}.
%
We summarize our findings in Section~\ref{sec:ch3-summary} and identify ideas for
future work in
Section~\ref{sec:ch3-concl}.
