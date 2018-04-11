One of the key challenges in achieving an exascale system is power usage.
%
At the beginning of this decade, scaling current technologies to higher
concurrency would lead to excessive power consumption costs.
%
High power costs are expensive and unsustainable, so the entire HPC
environment, is being re-evaluated with power efficiency in mind.

Due to the imbalance between computational and I/O performance of future
systems, the visualization community is transitioning from post hoc processing to
in situ processing.
%
With the in situ paradigm, visualization and analysis occur while the simulation is
running, making it unnecessary to store the simulation’s state
to disk and read it afterwards.
%
Running the simulation with the visualization means that the overall
time-to-solution will increase by some factor.
%
The magnitude of this factor is dependent on the desired quantity of
visualization.
%
The percentage of time spent doing visualization is highly variable, sometimes
taking as much as 10\% or 20\% of the overall turn-around time.
%
For this study, the visualization component contributes up to 14\% of the
overall time.
%
We assume an in situ workflow for this work and explore two strategies for
optimizing performance of the visualization pipeline, thus reducing the overall
execution time.

Both scientific simulations and visualization routines need to adapt to a
power-limited environment, meaning compute nodes will have their power usage
capped.
%
Based on current practices, a lower power cap would uniformly be applied across
all compute nodes in the system.
%
However, a uniform power cap is a sub-optimal strategy since the runtime
behaviors of distributed applications can be highly variable across nodes.
%
The nodes assigned the largest amount of work become a bottleneck and determine
the overall performance of the application.
%
On the other hand, nodes that are assigned the smallest amount of work finish
quickly and wait until the other nodes have finished execution.
%
A more intelligent strategy is to assign power to where it will result in the
most benefit.
%
Ideally, we can assign the power such that all nodes finish executing at the
same time despite varying workloads.

The main contribution of this paper is an evaluation that compares adaptive and
predictive power management schemes for visualization workloads.
%
As part of this research, we used two existing power-aware runtime systems,
GEOPM and PaViz, on a ray tracing workload.
%
GEOPM leveraged an online method of adapting to current execution behaviors,
while PaViz incorporated runtime predictions based on an accurate performance
model.
%
In terms of findings, we found that, in limited power budget environments,
using a power-aware runtime system with performance model predictions led to
better speedups than an adaptive model.

The rest of this chapter is organized as follows.
%
The related work is detailed in Section~\ref{sec:ch5-relwork}.
%
An overview of the GEOPM and PaViz runtime systems and their respective
adaptive and predictive power scheduling strategies are discussed in
Section~\ref{sec:ch5-runtimesys}.
%
Section~\ref{sec:ch5-study} identifies the study parameters.
%
We evaluate the effectiveness of adaptive and predictive scheduling strategies
in Section~\ref{sec:ch5-results}.
%
Lastly, Section~\ref{sec:ch5-concl} summarizes our findings and presents some ideas
for future research.
