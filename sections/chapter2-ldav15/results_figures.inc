\begin{figure*}[htbp]
\centering
\includegraphics[width=0.75\columnwidth]{images/chapter2/legend-datasets/ch2-datasets-horiz.pdf}
\includegraphics[width=.32\columnwidth]{images/chapter2/phase2-energy-omp-aug19.pdf}
\includegraphics[width=.32\columnwidth]{images/chapter2/phase2-time-omp-aug19.pdf}
\includegraphics[width=.32\columnwidth]{images/chapter2/phase3-valueprop-omp.pdf}
\caption[Performance slowdown and energy savings under reduced CPU clock
frequencies for data sets of varying sizes and layouts.]{\label{fig:POWERphase2-omp}
Results from Phase 2, which uses four cores of CPU1 with OpenMP and the BaselineImplementation and varies over data set and clock frequency.
The plots are of energy (left) and runtime (middle), as a function of CPU clock frequency.  The right figure is a scatter plot of the 1.6GHz slowdown factor versus energy savings for the eight data sets.}
\end{figure*}

\begin{figure*}[htbp]
\centering
\includegraphics[width=0.75\columnwidth]{images/chapter2/legend-datasets/ch2-datasets-horiz.pdf}
\includegraphics[width=.32\textwidth]{images/chapter2/phase3-energy-mpi-aug19.pdf}
\includegraphics[width=.32\textwidth]{images/chapter2/phase3-time-mpi-aug19.pdf}
\includegraphics[width=.32\textwidth]{images/chapter2/phase3-valueprop-mpi.pdf}
\caption[Performance slowdown and energy savings under reduced CPU
clock frequencies for the isosurfacing MPI implementation.]{\label{fig:phase3-progmodel} Results from Phase
3, which uses four cores of CPU1 with MPI and the BaselineImplementation and
varies over data set and clock frequency.
The plots are of energy (left) and runtime (middle), as a function of CPU clock frequency.  The right figure is a scatter plot of  the 1.6GHz slowdown factor versus energy savings for the eight data sets.}
\end{figure*}

\begin{figure*}[htpb]
\centering
\includegraphics[width=0.3\columnwidth]{images/chapter2/legend-concurrency/ch2-concurrency-horiz.pdf} \\
\includegraphics[width=.32\textwidth]{images/chapter2/phase4-energy-omp-aug19.pdf}
\includegraphics[width=.32\textwidth]{images/chapter2/phase4-time-omp-aug19.pdf}
\includegraphics[width=.32\textwidth]{images/chapter2/phase4-valueprop-omp.pdf}
\caption[Performance slowdown and energy savings under reduced CPU
clock frequencies for varying levels of OpenMP thread concurrency.]{\label{fig:phase4-omp}
Results from Phase 4's tests with OpenMP, studying Enzo-10M using CPU1 and the BaselineImplementation and varying over clock frequency and concurrency.
The plots are of energy (left) and runtime (middle), as a function of CPU clock frequency.  The right figure is a scatter plot of the 1.6GHz slowdown factor versus energy savings for the four concurrencies.}
\end{figure*}

\begin{figure*}[htbp]
\centering
\includegraphics[width=0.3\columnwidth]{images/chapter2/legend-concurrency/ch2-concurrency-horiz.pdf} \\
\includegraphics[width=.32\textwidth]{images/chapter2/phase4-energy-mpi-aug19.pdf}
\includegraphics[width=.32\textwidth]{images/chapter2/phase4-time-mpi-aug19.pdf}
\includegraphics[width=.32\textwidth]{images/chapter2/phase4-valueprop-mpi.pdf}
\caption[Performance slowdown and energy savings under reduced CPU
clock frequencies for varying levels of MPI task concurrency.]{\label{fig:phase4-mpi}
Results from Phase 4's tests with MPI, studying Enzo-10M using CPU1 and the BaselineImplementation and varying over clock frequency and concurrency.
The plots are of energy (left) and runtime (middle), as a function of CPU clock frequency.  The right figure is a scatter plot of the 1.6GHz slowdown factor versus energy savings for the four concurrencies.}
\end{figure*}
