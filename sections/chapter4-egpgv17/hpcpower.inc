Current cluster designs assume sufficient power will be available to
simultaneously run all compute nodes at their maximum thermal design point
(TDP).
%
Said another way, TDP is the maximum power a given node will ever consume.
%
As power requirements for clusters move into the range of dozens of MegaWatts,
the strategy of allocating power for all nodes to run at TDP becomes untenable.
%
Very few applications run at TDP, and provisioning very large
systems as if most did both wastes power capacity and unnecessarily
constrains the size of the cluster.

Overprovisioning~\cite{Patki:2013:EHO:2464996.2465009}, short for hardware
overprovisioning, is one solution to improve power utilization.
%
In such a design, we increase the compute capacity (\ie number of nodes) of the
system, but,
in order to not exceed the system power allocation,
not every node will be able to run at TDP simultaneously.
%
For example, the Vulcan supercomputer at Lawrence Livermore National Laboratory
was allocated for 2.4 MW at TDP, but the vast majority of
applications that run
on that machine did not exceed 60\% of the allocated power (1.47 MW average
power consumption).
%
Thus, the strategy of allocating TDP to every node fails to take advantage of
nearly 1 MW of power on average.
An overprovisioned approach would use 40\% more nodes, consuming all
allocated power and reducing trapped capacity~\cite{7016386}.

For overprovisioning to be successful, it must be complemented with a scheme to
limit nodes' power usage, to ensure the total allocated power is never
exceeded.
%
One way to accomplish this is to uniformly cap the power available to each
node, \eg each node can use only up to $60\%$ of its TDP.
%
The result of applying such a power cap is that the processor operating
frequency is reduced.
%
The effect of reduced CPU frequency is variable; programs dominated by compute
will slow down proportionally, while programs dominated by memory accesses may
be unaffected altogether.
%
Despite the slowdown in execution time for individual jobs, this strategy
would lead to better power utilization and greater overall throughput.

The strategy of allocating power uniformly across nodes, however, is
sub-optimal.
%
This is because the runtime behaviors of distributed applications can be
highly variable across nodes.
%
The nodes assigned the largest amount of work become a bottleneck and determine
the overall performance of the application.
%
On the other hand, nodes that are assigned the smallest amount of work finish
quickly and sit idle until the other nodes have completed execution.

A better strategy is to actively assign power to where it will do the most good.
%
This is the direction we pursue with this study.
%
In an ideal scenario, we can assign the power such that all nodes finish
executing at the same time despite varying workloads.

Overprovisioned systems lend themselves to multiple levels of
optimization.
%
At the job scheduling level, per job power bounds are allocated to optimize
throughput and/or turn-around time~\cite{Patki:2015:PRM:2749246.2749262}.
%
Alternatively, there are dynamic optimizations to individual jobs that may be
realized by rebalancing power and changing node configuration at
runtime~\cite{geopm,10.1007/978-3-319-58667-0_21,Marathe2015}.
%
While our work fits into this runtime level, our primary contribution is
demonstrating that additional performance may be realized by giving the runtime
system deeper knowledge of the unique execution behaviors for visualization
routines.
%
Specifically, we use a performance model for volume rendering to better
estimate the runtime behaviors,
and show that we can improve performance on less predictable workloads.
