In this chapter, we explored the viability of using prediction to improve the
performance of visualization workloads.
%
Specifically, we considered parallel rendering in the context of
overprovisioned supercomputers.
%
Like other HPC research on overprovisioning, we set per-node power caps in an
effort to allocate power to the nodes that needed it most.
%
However, since visualization workloads are highly variable, they required a new
approach for deciding how to assign power caps.
%
This new approach leverages prediction of execution times.
%
We incorporated an existing performance model, and considered five strategies
that make use of per-node workload estimates.
%
The resulting study demonstrated that our approach is beneficial, with results
as much as 33\% faster than a uniform distribution strategy while using
the same power.
%
In terms of future work, we would like to explore how PaViz can be adapted to
additional predictive models for visualization algorithms.
