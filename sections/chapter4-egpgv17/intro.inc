Power is a critical challenge in achieving the next generation of
high performance computing (HPC) systems.
%
Specifically, scaling today's technologies to higher concurrency may lead to
excessive power consumption costs.
%
As a result, the entire HPC environment --- from processors to software
applications to runtime systems --- is being re-evaluated for power
efficiency.

For this research, an important premise is that simulations and visualization
routines need to adapt to a power-limited environment, meaning nodes will have
their power usage capped.
%
Motivation for this premise can be found in Section~\ref{sec:ch4-powhpc}.
%
The main contribution of this chapter is PaViz, a power-adaptive visualization
framework that enables performance improvements when power is a scarce
resource.
%
To understand its efficacy, we ran PaViz on a rendering algorithm that
incorporated runtime predictions based on an accurate performance model.
%
Our study focuses on rendering for two reasons.
%
First, rendering is a ubiquitous operation for visualization.
%
Second, rendering is a particularly interesting algorithm to study, since its
workloads are highly variable depending on input parameters.
%
In terms of findings, we found that, in limited power budget environments,
adapting power based on performance model predictions led to speedups of up to
33\% while using the same power overall.

The rest of this chapter is organized as follows.
%
We present an overview of power with respect to HPC in
Section~\ref{sec:ch4-powhpc}.
%
The related work is detailed in Section~\ref{sec:ch4-relwork}.
%
The contributions of the PaViz framework and power scheduling strategies are
discussed in Section~\ref{sec:ch4-adaptive}.
%
Section~\ref{sec:ch4-parameters} identifies the study parameters.
%
We evaluate the benefits of PaViz in Section~\ref{sec:ch4-results}.
%
In Section~\ref{sec:ch4-concl}, we summarize our findings and present some ideas
for future exploration in this space.
