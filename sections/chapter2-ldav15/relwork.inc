\subsection{Power}
%
Power is widely viewed as the central challenge for exascale computing,
and that challenge is expected to impact exascale software~\cite{IESP}, including
visualization software~\cite{ExascaleAnalysis}.
%
Outside of visualization, many HPC researchers have looked at how to reduce
energy usage at different levels ranging from the processor to the full system,
including tradeoffs between power and performance.
%
Porterfield et al.~\cite{Porterfield:2013:OMA:2536430.2536437} looked into the
variability in the performance to energy usage at the processor level using OpenMP
and MPI.
%
Other research has been dedicated to reduce the total power usage of the
system~\cite{Freeh:2008:JDV:1403197.1403270,Freeh:2005:UME:1065944.1065967,Laurenzano:2011:REU:2033345.2033356,Porterfield:2013:OMA:2536430.2536437}.
%
Ge et al.~\cite{Ge:2005:IPE:1053738.1054684}
developed compute-bound and
memory-bound synthetic workload
to demonstrate that power-performance
characteristics are determined by various characteristics in the application.
%

The study closest to the one described in this chapter was by Gamell et
al.~\cite{Gamell:2013:EPB:2503210.2503303}.
%
In this work, they investigated the power-performance relationship for visualization
workloads.
%
However, our studies are complementary, as they looked at behaviors across nodes and
we aim to illuminate the behavior within a node.
%
A second noteworthy study was by Johnsson et al.~\cite{johnsson2012power}.
%
In this study, the authors studied power usage on a GPU when different rendering features
were enabled and disabled.
%
Our study is different in nature, as we are studying a visualization algorithm, and also
we are studying impacts of programming model, data set, and architectural features,
rather than changing the (OpenGL) rendering algorithm itself.

\subsection{Visualization}
%
Our study focuses on a traditional isosurfacing algorithm using Marching
Cubes~\cite{Lorensen:1987:MCH:37401.37422}.
%
While our study does not preclude using an acceleration structure to quickly
identify only the cells that contain the isosurface~\cite{cignoni1997speeding},
we did not employ this optimization since we wanted the data loads and stores
to follow a more controlled pattern.

Most of our experiments were run using our own implementation of an isosurface
algorithm.
%
However, some experiments were run using the isosurfacing algorithm in the
Visualization ToolKit (VTK)~\cite{VTK}.
%
Further, we believe that the corresponding results
are representative of the
class of general frameworks, \eg OpenDX~\cite{OpenDX} and
AVS~\cite{AVS}, and of the end-user tools built on top of such frameworks
(\ie VTK-based ParaView~\cite{Ahrens+Geveci+Law2005} and VisIt~\cite{HPV:VisIt}).
