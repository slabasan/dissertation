In the following subsections, we discuss the study overview and methodology for
our experiments.

\subsection{Software Framework}

Our software infrastructure included VTK-m and Ascent.
%
VTK-m~\cite{vtkm} is an open-source library of scientific visualization
algorithms designed for shared-memory parallelism.
%
Its algorithms are implemented using a layer of abstraction enabling portable
performance across different architectures.
%
It is an extension of the Visualization ToolKit
(VTK)~\cite{VTK}, a well-established open-source
library of visualization algorithms that form the basis of VisIt~\cite{HPV:VisIt}
and ParaView~\cite{Ahrens+Geveci+Law2005}.
%
For this study, we configured VTK-m with Intel's Thread Building
Blocks (TBB)~\cite{ReindersTBB} for thread-level parallelism.

The Ascent~\cite{Larsen:2017:ASI:3144769.3144778,larsen2015strawman} in situ
framework is part of the multi-institutional project known as ALPINE.
%
Ascent is a flyweight, open-source in situ visualization framework designed to support
VisIt's LibSim~\cite{Whitlock:2011:PSC:2386230.2386245} and ParaView's
Catalyst~\cite{6092322}.
%
Of the three included multi-physics proxy applications, we used
CloverLeaf~\cite{cloverleaf,mallinson2013cloverleaf}, a hydrodynamics
simulation, tightly coupled with the visualization.
%
That is to say, the simulation and visualization alternate while
using the same resources.


\subsection{Hardware Architecture}
We used the \emph{RZTopaz} supercomputer at Lawrence Livermore National
Laboratory to conduct our experiments.
%
Each node contains 128 GB of memory and two Intel Xeon E5-2695 v4 dual-socket
processors executing at a base clock frequency of 2.1 GHz (120W thermal design
power, or TDP).
%
The Turbo Boost clock frequencies range from 2.6 GHz to 3.3 GHz.
%
Each hyper-threaded processor has 18 physical cores.

On LLNL systems, the \verb|msr-safe|~\cite{msrsafe} driver provides an
interface for sampling and controlling processor power usage, among other
performance counters, via 64-bit model-specific registers.
%
On this Broadwell processor, the power can be capped from 120W
(TDP) down to 40W using Intel's Running Average Power Limit technology
(RAPL)~\cite{intel2017}.
%
Then, the processor adjusts the operating frequency to guarantee the desired
power cap.

\subsection{Study Factors}
\label{sec:ch3-factors}

Our study consisted of three phases and 288 total test configurations.
%
Each test was launched using a single node and a single MPI process for maximum
memory allocation.
%
Shared-memory parallelism was enabled with VTK-m.
%
We varied the following parameters for this study:
%
\begin{itemize}
\item \textbf{Processor power cap} (9 options): Enforce a processor-level
(cores, cache) power cap ranging from 120W (TDP) down to 40W in increments
of 10W using Intel's RAPL.
%
\item \textbf{Visualization algorithm} (8 options): The representative set of
algorithms explored are contour, threshold, spherical clip, isovolume, slice,
particle advection, ray tracing, and volume rendering.
%
\item \textbf{Data set size} (4 options): The CloverLeaf data set sizes used
per node are $32^3$, $64^3$, $128^3$, and $256^3$.
%
The total number of cells ranged from $32,768$ to $16,777,216$.
%
\end{itemize}
