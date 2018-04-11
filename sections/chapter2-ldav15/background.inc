One goal for this study is to identify situations where the clock frequency
can be reduced, but the execution time does not increase proportionally.
%
In such cases, energy savings are possible.
%
However, we should only expect the execution time to be maintained if the
computation is data-bound.
%
This situation occurs when data load and store requests exceed what the memory
infrastructure can deliver.

To get a sense of when programs are data-bound and when they are compute-bound,
we created four micro-benchmarks.
%
These benchmarks will also inform the spectrum of outcomes we can expect.
%
The benchmarks are:
%
\begin{itemize}
%
\item \emph{computeBound}: A compute-bound workload performing several
multiplication operations on one variable.
%
\item \emph{computeBoundILP}: The above compute-bound benchmark with
instruction-level parallelism.
%
This enables pipelining of multiple instructions.
%
\item \emph{memoryBound}: A memory-bound benchmark that accesses an element
in an array and then writes it to another array based on an index.
%
\item \emph{memoryBoundCacheThrash}: The above memory-bound benchmark, but the
indices that map the output value have been randomized, removing any benefit of
locality.
%
\end{itemize}

Figure \ref{fig:benchmark} shows the performance results of our
micro-benchmarks with varying CPU clock frequencies.
%
Our original hypothesis was that the \emph{computeBound} workload would
double in execution time if run at half the speed, the
\emph{memoryBoundCacheThrash} application would have the most consistent
runtime across all frequencies, and
the \emph{computeBoundILP} and \emph{memoryBound} workloads
would have changes in runtime that fall between the two extremes.
%
From the figure, we find that the \emph{computeBound} workload follows our
initial premise.
%
The \emph{memoryBoundCacheThrash} workload stays relatively consistent, but
there is a slight increase in runtime when run at the lowest frequency.
%
Even with a synthetic data-bound workload, we are not able to achieve perfect
consistency in runtime over varying frequencies.
%
This means that we should not expect visualization workloads to achieve perfect
consistency in runtime, since they have significantly more computations
than the synthetic workload, and since they  use cache in a more coherent way.

\begin{figure}[t]
\centering
\includegraphics[width=0.7\columnwidth]{images/chapter2/legend-benchmarks/ch2-benchmarks-horiz.pdf}
\includegraphics[width=2.5in]{images/chapter2/sept5_ldav_benchmarks.pdf}
\caption[Performance results for compute-bound and memory-bound micro-benchmarks
under reduced CPU clock frequencies.]{\label{fig:benchmark}Performance results
of our micro-benchmarks with
varying frequencies. The \emph{computeBound} workload is directly
proportional to the clock speed, while the \emph{memoryBoundCacheThrash} is
independent of the change in clock frequency.}
\end{figure}

\begin{table}[h]
\centering
\begin{tabular}{||l|c|c|c||}
\hline
\multirow{2}{*}{Benchmark} & \multicolumn{2}{c|}{Time} & \multirow{2}{*}{Ratio} \\ \cline{2-3}
& 2.4 GHz & 1.2 GHz & \\
\hline
\emph{computeBound} & 24.59s & 49.17s & 2X \\
\emph{computeBoundILP} & 1.32s & 2.58s & 2X \\
\emph{memoryBound} & 5.25s & 7.63s & 1.4X \\
\emph{memoryBoundCacheThrash} & 79.78s & 84.22s & 1.1X \\
\hline
\end{tabular}
\caption[Performance slowdown for compute-bound and memory-bound micro-benchmarks as
the CPU clock frequency is reduced.]{Increase in runtime for the four
micro-benchmarks when slowing down the clock frequency by a factor of 2X.
Though \emph{memoryBoundCacheThrash} is synthetically designed to be the most
data-intensive workload, it still does not hold constant in runtime across
frequencies, \ie achieve a ratio of exactly 1X.}
\label{table:benchmark}
\end{table}
