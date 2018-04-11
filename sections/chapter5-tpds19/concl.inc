In this chapter, we compared the effectiveness of two different approaches in
dynamically scheduling power to improve the performance of scientific
visualization workloads in a power-limited environment.
%
Specifically, we considered an adaptive and predictive approach and focused on
parallel ray tracing, which is a highly variable workload.
%
Like other HPC research on overprovisioning, both strategies determine per-node
power caps in an effort to allocate power to the nodes that needed it
most.
%
The adaptive method is online and adapts power based on current workload
execution behaviors.
%
This method can be well-suited for predictable workloads whose iterations are
regular from one to the next.
%
The predictive method introduced in Chapter~\ref{ch:egpgv} uses an existing
performance model to assign power based on a prediction of execution time.
%
While this method is well-suited for irregular workloads (\eg visualization),
there is a high overhead cost (\ie human time) to create the performance
models.
%
The resulting study demonstrated that the predictive approach is beneficial for
irregular visualization workloads, with results as much as 27\% faster than an
adaptive strategy.

In terms of future work, we would like to understand which scenarios are
beneficial for prediction and which scenarios are beneficial for adaptation.
%
One of the downsides of using prediction is the effort in creating and
validating accurate performance models.
%
On the other hand, one of the downsides of using adaptation is needing time at
the beginning of the routine to identify the most and least efficient nodes.
%
We want to explore if prediction is possible with minimal overhead costs, and
identify cost effective scenarios for using adaptation.
