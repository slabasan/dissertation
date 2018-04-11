In the following subsections, we survey related work.

\subsection{Volume Rendering}
Volume rendering is an important set of rendering algorithms that enables
visualization of an entire three dimensional scalar field, and  volume
rendering is widely used because it is capable of analyzing a large amount of
data from many scientific disciplines.
%
Volumetric ray casting~\cite{levoy1990efficient} traces rays from the camera
through a scalar field, sampling the volume at regular intervals, and
accumulating color and opacity via a transfer function.
%
This algorithm is embarrassingly parallel and is used in community driven
visualization tools (\eg VisIt~\cite{HPV:VisIt} and
ParaView~\cite{Ahrens+Geveci+Law2005}) and packages from hardware vendors (\eg
Intel's OSPRay~\cite{wald2017ospray} and NVIDIA's IndeX~\cite{IndeX}).
%
For our study, we chose volumetric ray casting because of its widespread use,
and also because of its existing performance model~\cite{Larsen:SC16}.

\subsection{Power}
Some of the earliest solutions in addressing energy use in HPC were CPU
MISER~\cite{4343825}, Jitter~\cite{Freeh:2008:JDV:1403197.1403270}, and
Adagio~\cite{Rountree:2009:AMD:1542275.1542340}.
%
These approaches used dynamic voltage and frequency scaling (DVFS) to make
decisions between performance and energy at varying
granularities.
%
All three approaches were aimed at minimizing
energy use with varying tolerances for increases in runtime.
%
CPU MISER made CPU frequency decisions based on time intervals, and
did not perform well when application behavior was less predictable.
%
Jitter used iterations to identify the processor with the most work in order to
slow down remaining processors,
and this led to
sub-optimal performance on applications where the critical path moved across
processors within an iteration.
%
Adagio's solution used task-based granularity to identify the critical path,
thus minimizing performance degradation.
%
For our study, we focus on the rendering work prior to MPI (\ie prior to
compositing), so we make decisions at an iteration-based granularity.

Processor manufacturer technologies for enforcing power caps (Intel's Running
Average Power Limit (RAPL)~\cite{intel2017}, AMD TDP
PowerCap~\cite{amd2013},
and IBM EnergyScale~\cite{ibmenergyscale}) enable more recent efforts to focus
on optimizing performance under a power bound.
%
Conductor~\cite{Marathe2015} used initial iterations to determine an ideal
schedule of per-node power caps, thread concurrency, and per-core operating
frequency.
%
GEOPM~\cite{geopm,10.1007/978-3-319-58667-0_21} is a
production-grade runtime framework for optimizing performance under resource
constraints.
%that drew from both Conductor and Adagio.
GEOPM, Conductor, and Adagio share similar goals and are collaborating to
integrate technologies.
%
GEOPM supports manual application markup as well as automated phase detection to
dynamically reallocate power.
%
Its architecture supports multiple plugins, but currently it does not
support any particular policy targeted at in situ visualization.

Neither Conductor nor GEOPM can use application inputs to optimize
performance.
%
To the best of our knowledge, PaViz is the first runtime system
to use visualization workloads, which behave differently than typical
benchmarks than those used by Conductor and GEOPM.
%
Specifically, we use rendering workload parameters --- number of active pixels,
camera position, image resolution --- to predict execution time and optimize
performance under a power bound.

\subsection{Scientific Visualization and Power}
Due to the I/O bandwidth limitations at exascale, visualization
is moving away from a traditional post-processing method to in situ.
%
In the post-processing method, the simulation writes out data to disk at
regular time steps.
%
Once the simulation has completed, the data is read back from disk for
post-processing analysis and visualization using tools, such as
VisIt~\cite{HPV:VisIt} or ParaView~\cite{Ahrens+Geveci+Law2005}.
%
As simulations increase in complexity, the amount of data they can write out
increases exponentially, making it unsustainable to write out data with high
temporal frequency.
%
The critical challenge is saving enough data from the simulation without
impacting fidelity or losing notable areas of interest.

In the in situ model, visualization and analysis occur alongside the
simulation to mitigate the impacts of reduced I/O bandwidth.
%
The data from the simulation is analyzed and visualized and the resulting
images are written to disk, vastly reducing the total amount of data written to
disk.
%
Since power is a critical challenge to reaching the next generation of
computing, research efforts have been dedicated to understanding the power
profiles of this new
analysis strategy, particularly with respect to how data is moved through the
storage hierarchy~\cite{7284404,7515682}.
%
These works compared the power profiles of each pipeline, concluding that in
situ drastically reduces energy usage by reducing the total runtime to complete
the simulation and analysis.

Labasan et al.~\cite{7348074} provided an initial exploration of the various
factors that may impact power and performance trade-offs for an isosurfacing
algorithm implemented in two frameworks.
%
This work studied the performance impacts of various parameters as the CPU
operating frequency was gradually reduced.
%
Similarly, work by Gamell et al.~\cite{Gamell:2013:EPB:2503210.2503303} also
looked at the power-performance trade-offs of various parameters at scale.
