\subsection{Power}
Energy use has been a long-term challenge in HPC.
%
Early solutions used dynamic frequency and voltage scaling (DVFS) to make
tradeoff decisions between performance and energy
savings at varying
granularities~\cite{Freeh:2008:JDV:1403197.1403270,4343825,Rountree:2009:AMD:1542275.1542340}.
%
The common goal of these approaches was to minimize energy usage by incurring a
small performance degradation.

Vendor technologies for applying power caps have enabled more recent research
focusing on performance under a power bound.
%
Some of these technologies include Intel's Running Average Power
Limit~\cite{intel2017}, AMD's Application Power Management~\cite{amd2013}, IBM
EnergyScale~\cite{ibmenergyscale}, NVIDIA's NVML~\cite{nvidia2015}.
%
Conductor~\cite{Marathe2015} used initial iterations to determine an ideal
schedule of per-node power caps, thread concurrency, and per-core operating
frequency.
%
GEOPM~\cite{geopm,10.1007/978-3-319-58667-0_21} is a production-grade runtime
framework for optimizing performance under resource constraints.
%
GEOPM supports manual application markup as well as automated phase detection
to dynamically reallocate power.
%
Its architecture supports multiple plugins, but currently it does not support
any particular policy targeted at in situ visualization.

\subsection{Ray Tracing}
Ray tracing is a common method for rendering images.
%
With ray tracing, rays are traced from the viewpoint through pixels, and
intersect with the geometry to be rendered.
%
The process of tracing rays is embarrassingly parallel, however, scaling the
algorithm to render millions of pixels is challenging.
%
Previous efforts have implemented a parallel ray
tracer~\cite{Bigler:2006:CSV:2384796.2384842,Parker:1998:IRT:288216.288266}.
%
For our study, we chose ray tracing because of its widespread use and because
of its existing performance model~\cite{Larsen:SC16}.

\subsection{Visualization and Power}

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
The data from the simulation is visualized and the resulting images are written
to disk, vastly reducing the total amount of data written out.
%
Since power is a critical challenge to reaching the next generation of
computing, research efforts have been dedicated to understanding the power
profiles of this new
workflow, particularly with respect to how data is moved through the storage
hierarchy~\cite{7284404,7515682}.
%
These works compared the power profiles of each pipeline, concluding that in
situ drastically reduces energy usage by reducing the total runtime to complete
the simulation and analysis.

Labasan et al.~\cite{7348074} provided an initial exploration of the various
factors that may impact power and performance tradeoffs for an isosurfacing
algorithm implemented in two frameworks.
%
This work studied the performance impacts of various parameters as the CPU
operating frequency was gradually reduced.
%
Similarly, work by Gamell et al.~\cite{Gamell:2013:EPB:2503210.2503303} also
looked at the power-performance tradeoffs of various parameters at scale.
