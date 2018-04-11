The following subsections detail the two different power scheduling strategies
being evaluated in this paper.
%
The strategies are implemented in two runtime systems, known as GEOPM and
PaViz, which we explain here.
%
Both share a common goal to improve performance in a power-limited
environment, but do so in their own ways.

In an overprovisioned system, not all nodes can run at full power
simultaneously.
%
In order to run all nodes at the same time, a uniform power cap is
applied at a reduced limit.
%
In a load imbalanced workload, like visualization, this strategy is a
suboptimal choice, since the performance is ultimately determined by the
last processor to finish its work.
%
A more performant strategy is to assign power to where it is needed (\eg the
critical path), speeding up the processors that are behind and slowing down the
processors that are further ahead.

The other key challenge for these runtime systems to be successful is to
redistribute the power, such that the systemwide power limit is not exceeded.
%
Exceeding the given power limit will cause electrical issues at the system
level, which may cause failures or breakage.

\subsection{GEOPM: Adaptive Runtime System}
GEOPM~\cite{geopm,10.1007/978-3-319-58667-0_21} is an open-source framework for
power and energy research on future HPC systems.
%
GEOPM is a collaborative project, started and supported by Intel.
%
It is designed to target Intel platforms, but can be extended to support other
hardware platforms that provide power management capabilities.
%
It leverages a tree design to be portable at high concurrencies.
%
GEOPM is also designed to support the different power and energy management
requirements across computing facilities through an agent plugin architecture.

The GEOPM runtime system analyzes execution behaviors within the application,
then optimizes performance by coordinating decisions to hardware or software
control knobs across compute nodes.
%
Some control knobs are per-core clock frequencies and processor-level power
limits.
%
By tuning control knobs during an application's execution, GEOPM may improve
performance despite workload imbalances and manufacturing variations across
nodes.

GEOPM's runtime system uses a balanced tree to provide hierarchical feedback
about the application's performance.
%
There is a controller running on a single thread per node to handle different
roles and tasks.
%
One of the controllers is the root node, and will make the final decision based
on feedback from the leaf nodes.
%
This hierarchical design allows GEOPM to be performant at high levels of
concurrency.
%
For this study, we use the Power Balancer plugin, which is discussed in
Section~\ref{sec:ch5-study}.

\subsection{PaViz: Predictive Runtime System}
PaViz~\cite{pgv.20171088} uses prediction to dynamically allocate power across
nodes in a job.
%
For our approach, we incorporate an existing rendering performance
model~\cite{Larsen:SC16} into our runtime system.
%
If the performance model predicts a long rendering time due to a high volume of
work, then we allocate more power to that node.
%
Alternatively, we allocate less power if the performance model predicts a short
rendering time due to less work being assigned.

Larsen et. al~\cite{Larsen:SC16} created and validated performance models for
scientific visualization workloads.
%
The performance model makes a prediction based on camera position and data set
size.
%
These performance models have easily calculable inputs.
%
The performance models are semi-empirical, meaning that they are both based on
algorithmic characteristics and observed execution behaviors on specific
hardware architectures.
%
In order to leverage these models, the models must be fitted to a particular
hardware architecture.

When it comes to deciding how much power should be allocated to each node, we
implemented multiple power scheduling strategies and previously evaluated
them~\cite{pgv.20171088}.
%
The best scheduling strategy is most aggressive in assigning power caps to the
longest and shortest running nodes.

Specifically for rendering, the amount of work per rank is highly variable from
one timestep to another depending many factors, such as the visualization
operation and resulting output.
%
Being able to predict the amount of work before execution is ideal in this case
since you cannot assume behavior will be constant between timesteps.
