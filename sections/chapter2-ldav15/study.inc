The following section details the various parameters in our experiments.

\subsection{Factors Studied}
\label{sec:ch2-factors}

We considered the following factors:
%
\begin{itemize}
\item \textbf{Hardware architecture.}
%
Architecture is important, since each architecture has different power
requirements at varying clock frequencies, and also different caching
characteristics.
%
\item \textbf{CPU clock frequency.}
%
As the clock speed slows down, the data-intensive workloads
may not slow down proportionally,
creating opportunities for power savings.
%
\item \textbf{Data set.}
%
Data set dictates how the algorithm must traverse memory.
%
While structured data accesses memory in a regular pattern, unstructured data
may have more random arrangements in memory, increasing the data intensity.
%
\item \textbf{Parallel programming model.}
%
The programming model affects how multi-core nodes access data and the
necessary memory bandwidth for the algorithm.
%
Specifically, coordinated accesses across cores can reduce cache thrashing,
while uncoordinated accesses can increase cache thrashing.
%
\item \textbf{Concurrency.}
%
Concurrency affects the demands placed on the cache: more cores are more likely
to hit the memory infrastructure's bandwidth limit, while fewer cores are less
likely.
%
\item \textbf{Algorithm implementation.}
%
The algorithm implementation dictates the balance of computations and data
loads and stores.
%
Across implementations, the total number of instructions and the ratios of
instruction types will change, which in turn could affect
power-performance tradeoffs.
%
\end{itemize}

\subsection{Configurations}
Our study consisted of six phases and 277 total tests.
%
It varied six factors:
\begin{itemize}
%
\item Hardware architecture: 2 options
%
\item CPU clock frequency: 7 or 11 options, depending on hardware architecture
%
\item Data set: 8 options
%
\item Parallel programming model (OpenMP vs. MPI): 2 options
%
\item Concurrency: 4 options
%
\item Algorithm implementation: 2 options
%
\end{itemize}

\subsubsection{Hardware Architecture}
%
We studied two architectures:
%
\begin{itemize}
%
\item \textbf{CPU1}: A Haswell Intel i7 4770K with 4 hyper-threaded cores
running at 3.5 GHz, and 32 GB of memory operating
at 1600 MHz.
%
Each core has a private L1 and L2 cache running with a
bandwidth of 25.6 Gbytes/s.
%
\item \textbf{CPU2}: A single node of NERSC's Edison machine.
%
Each node contains two Intel Ivy Bridge processors, and each processor contains
12 cores, running at 2.4 GHz.
%
Each node contains 64 GB of memory operating at 1866 MHz.
%
Each core has a private L1 and L2 cache, with 64 KB and 256 KB, respectively.
%
A 30 MB L3 cache is shared between the 12 cores.
%
The cache bandwidth for L1/L2/L3 is 100/40/23 Gbytes/s.
%
\end{itemize}
%
Both CPUs enable users to set a fixed CPU clock frequency as part of launching
the application.
%
CPU1 uses the Linux \verb|cpufreq-utils| tool, while CPU2 uses an
\verb|aprun| command line argument to specify the frequency of a submitted job.
%
Both CPUs are also capable of reporting total energy usage and power consumed
(see Section \ref{sec:ch2-perfmeasures}).

Finally, it is important to note that Intel Haswell processors (\ie CPU1) do
not tie cache speeds to clock frequency, but Intel Ivy Bridge processors (\ie
CPU2) do force their caches
to match clock frequency, and thus their caches slow down when clock frequency is reduced.

\subsubsection{CPU Clock Frequency}

For CPU1, we were able to set the clock frequency at 11 different options, from
1.6 GHz to 3.5 GHz (nominal frequency).
For CPU2, the hardware controls only allowed for 7 options, from 1.2 GHz to 2.6 GHz
(nominal frequency).

\subsubsection{Data Set}
\label{sec:ch2-datasets}

In this study, we consider only unstructured meshes, although we consider different
sizes, and different cache coherency characteristics.
%
Our study used the following eight data sets:
%
\begin{itemize}
%
\item \textbf{Enzo-1M}: a cosmology data set from the Enzo~\cite{Enzo}
simulation code originally mapped on a rectilinear grid.
%
We decomposed the data set into 1.13 million tetrahedrons.
%
\item \textbf{Enzo-10M}: a 10.5 million tetrahedron version of Enzo-1M.
%
\item \textbf{Enzo-80M}: an 83.9 million tetrahedron version of Enzo-1M.
%
\item \textbf{Nek5000}: a 50 million tetrahedron unstructured mesh from a
Nek5000~\cite{nek5000-web-page} thermal hydraulics simulation.
%
Nek5000's native mesh is unstructured, but composed of hexahedrons.
%
For this study, we divided these hexahedrons into tetrahedrons.
%
\item \textbf{REnzo-1M, REnzo-10M, REnzo-80M, RNek5000}: Altered versions of
the above data sets.
%
We randomize the point indices such that accesses are irregular and locality is
not maintained.
%
\end{itemize}

We selected an isovalue of 170 for the Enzo data sets, and 0.3 for Nek5000.
%
While ``isovalue" could have served as another parameter for our study, we
found that varying it did not significantly affect results.

\begin{figure}[h!]
\centering
\includegraphics[width=0.3\textwidth]{images/chapter2/enzo.png}
\hspace{0.2cm}
\includegraphics[width=0.3\textwidth]{images/chapter2/nek5000.png}
\caption[Images of the Enzo and Nek5000 data sets used in the initial variation
study in Chapter~\ref{ch:ldav}.]{\label{fig:datasets}Visualizations of the two
data sets used in this study.
%
The Enzo data set is on the left and Nek5000 is on the right.}
\end{figure}

\subsubsection{Parallel Programming Model}

We implemented our algorithms using both the
OpenMP~\cite{Chandra:2000} and MPI~\cite{MPI:1998} parallelism approaches within a node.

With the OpenMP approach,
all cores operated on a common data set,
meaning that cache accesses can be done in a coordinated
way.
%
Our OpenMP implementation used default thread scheduling.
%
With this method, the chunk size is determined by the number of iterations in
the loop divided by the number of OpenMP threads.
%
That said, we experimented with many chunking strategies and were not able to
locate any that significantly outperformed the default.

With the MPI approach,
each core operated on an exact local copy of the data in its own space.
%
As a result, the cores were operating independently, creating uncoordinated cache
accesses.

Whatever the parallel programming model, the tests operated on the same data
size.
%
Given $C$ cores and $N$ cells total, the OpenMP approach would have all
cores operate on the $N$ cells together, and perform the operation $C$ times,
while the MPI approach would have each core operate on $N*C$ cells.
%
Further, in order to obtain reliable measurements, we had each algorithm
execute ten times, and the reported measurements are for all ten executions.

\subsubsection{Concurrency}

For CPU1, we ran tests using 1, 2, 3, and 4 cores.
%
For CPU2, no tests of this nature were run.

\subsubsection{Algorithm Implementation}

We implemented two different versions of isosurfacing for our study:
%
\begin{itemize}
%
\item \textbf{BaselineImplementation}: We implemented our own isosurfacing algorithm.
%
This algorithm could only perform tetrahedral Marching Cubes (Marching Tets),
and so it was efficient for that purpose, especially in terms of minimal
numbers of instructions.
%
We implemented versions of our code to work with both MPI and OpenMP.
%
\item \textbf{GeneralImplementation}: Isosurface implemented using a general-purpose
visualization software library (VTK), specifically the vtkContourFilter.
%
Generalized frameworks like VTK sacrifice performance to ensure that their code works
on a wide variety of configurations and data types.
%
As a result, the performance characteristics of such a framework are different
(specifically having an increased number of instructions), and thus the
opportunities for power-performance tradeoffs may also be different.
%
The vtkContourFilter does not work with OpenMP, so our only supported
programming model for this implementation was with MPI (via our own custom MPI
program that incorporated this module).
%
\end{itemize}

\subsection{Performance Measurements}
\label{sec:ch2-perfmeasures}

We enabled PAPI~\cite{Mucci99papi:a} performance counters to gather
measurements for each phase of the algorithm.
%
Specifically, we capture \verb|PAPI_TOT_INS|, \verb|PAPI_TOT_CYC|,
\verb|PAPI_L3_TCM|, \verb|PAPI_L3_TCA|, and \verb|PAPI_STL_ICY|.
%
(Note that \verb|PAPI_TOT_CYC| counts all instructions executed, which can
vary from run to run due to CPU branch speculation.
Unfortunately, we were not able to
count instructions retired, which
would be consistent across runs.)

We then derive additional metrics from the PAPI counters:
%
\begin{itemize}
%
\item instructions executed per cycle (IPC) = \verb|PAPI_TOT_INS| / \verb|PAPI_TOT_CYC|
\item L3 cache miss rate = \verb|PAPI_L3_TCM| / \verb|PAPI_TOT_CYC|
\end{itemize}

On CPU1, we used Intel's Running Average Power Limit (RAPL)~\cite{intel2017} to
obtain access to energy measurements.
%
This instrumentation provides a per socket measurement, aggregating across cores.
%
On CPU2, we took power and energy measurements using the Cray XC30 power
management system~\cite{martin2014cray}.
%
This instrumentation provides a per node measurement, again aggregating across cores.

\subsection{Methodology}
\label{sec:ch2-methodology}
%
Our study consisted of six phases.
%
The first phase studied a base case, and
the subsequent phases varied additional dimensions from our test factors, and analyzed the
impacts of those factors.

\subsubsection{Phase 1: Base Case}
\label{sec:ch2-phase1}
Our base case varied the CPU clock frequency.
%
It held the remaining factors constant:
CPU1, Enzo-10M, four cores (maximum concurrency available on
CPU1), the BaselineImplementation, and the OpenMP parallel programming model.
%
The motivation for this phase was
to build a baseline understanding of performance.

\textbf{Configuration:}
(CPU1, 4 cores, Enzo-10M, BaselineImplementation, OpenMP) $\times$ 11 CPU clock frequencies

\subsubsection{Phase 2: Data Set}
In this phase, we continued varying clock frequency and added
variation in data set.
%
It consisted of 88 tests, of which 11 were studied in Phase 1
(the 11 tests for Enzo-10M).

\textbf{Configuration:}
(CPU1, 4 cores, BaselineImplementation, OpenMP) $\times$ 11 CPU clock frequencies $\times$ 8 data sets

\subsubsection{Phase 3: Parallel Programming Models}
In this phase, we continued varying clock frequency and data set
and added variation in parallel programming model.
%
It consisted of 176 tests, of which 88 were studied in Phase 2 (the OpenMP tests).

\textbf{Configuration:}
(CPU1, 4 cores, BaselineImplementation) $\times$ 11 CPU clock frequencies $\times$ 8 data sets
$\times$ 2 parallel programming models

\subsubsection{Phase 4: Concurrency}
In this phase, we went back to the Phase 1 configuration, and added variation
in concurrency and programming model.
%
It consisted of 88 tests, of which 11 were studied in Phase 1 (the OpenMP configurations using all
4 cores) and 11 were studied in Phase 3 (the MPI configurations using all 4 cores).

\textbf{Configuration:}
(CPU1, Enzo-10M, BaselineImplementation) $\times$ 11 CPU clock frequencies
$\times$ 4 concurrency levels
$\times$ 2 parallel programming models


\subsubsection{Phase 5: Algorithm Implementation}
In this phase, we studied variation in algorithm implementation.
%
Since the GeneralImplementation was only available with the MPI parallel programming
model, we could not go back to Phase 1.
%
Instead, we compared 11 new tests with 11 tests first performed in Phase 3.

\textbf{Configuration:}
(CPU1, 4 cores, Enzo-10M, MPI) $\times$ 11 CPU clock frequencies
$\times$ 2 algorithm implementations

\subsubsection{Phase 6: Hardware Architecture}

With this test, we went to a new hardware architecture, CPU2.
%
We kept many factors constant --- BaselineImplementation, Enzo-10M, 24 cores ---
and varied CPU clock frequency and parallel programming model.
%
All 14 tests for this phase were new.

\textbf{Configuration:}
(CPU2, 24 cores, Enzo-10M, BaselineImplementation) $\times$ 7 CPU clock frequencies
$\times$ 2 parallel programming models
