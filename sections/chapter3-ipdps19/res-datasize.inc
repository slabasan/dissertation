\begin{table*}[]
\centering
\begin{tabular}{||c|c|c|c|c|c|c|c|c|c|c||}
\hline
                           & $P$         & 120W  & 110W  & 100W  & 90W   & 80W   & 70W   & 60W   & 50W   & 40W  \\
                           & $P_{rat}$ & 1X  & 1.1X  & 1.2X  & 1.3X  & 1.5X  & 1.7X  & 2X  & 2.4X  & 3X \\
\hline
\multirow{2}{*}{Contour}            & $T_{rat}$ & 1X & 1X & 1X & 1X & 1X & 1X & 1.05X & \fix{1.19X} & 1.71X \\
                                    & $F_{rat}$ & 1X & 1X & 1X & 1X & 1.01X & 0.99X & 1.07X & \fix{1.18X} & 1.52X \\
\hline
\multirow{2}{*}{\begin{tabular}[l]{@{}l@{}}Spherical\\Clip\end{tabular}} & $T_{rat}$ & 1X & 1.01X & 1.01X & 1.05X & 1.01X & \fix{1.10X} & 1.16X & 1.41X & 2.13X \\
                                    & $F_{rat}$ & 1X & 1X & 1X & 1X & 1.01X & 1.05X & \fix{1.17X} & 1.42X & 1.95X \\
\hline
\multirow{2}{*}{Isovolume}          & $T_{rat}$ & 1X & 0.98X & 0.97X & 1.01X & 1.01X & 1.01X & \fix{1.17X} & 1.33X & 1.76X \\
                                    & $F_{rat}$ & 1X & 1X & 0.97X & 1X & 1X & 1.05X & \fix{1.11X} & 1.32X & 1.79X \\
\hline
\multirow{2}{*}{Threshold}          & $T_{rat}$ & 1X & 1.02X & 0.99X & 0.99X & 0.98X & 1.09X & \fix{1.16X} & 1.30X & 1.53X \\
                                    & $F_{rat}$ & 1X & 1.01X & 1.02X & 1.02X & 1.02X & 1.05X & \fix{1.17X} & 1.38X & 1.66X \\
\hline
\multirow{2}{*}{Slice}              & $T_{rat}$ & 1X & 1X & 0.99X & 0.99X & 1X & 1X & 0.99X & \fix{1.33X} & 1.69X \\
                                    & $F_{rat}$ & 1X & 0.98X & 1.01X & 0.93X & 1.01X & 0.98X & 1.01X & \fix{1.24X} & 1.44X \\
\hline
\multirow{2}{*}{\begin{tabular}[l]{@{}l@{}}Ray\\Tracing\end{tabular}} & $T_{rat}$ & 1X & 1X & 1X & 1.01X & 1X & 1.02X & \fix{1.10X} & 1.28X & 2X \\
                                    & $F_{rat}$ & 1X & 1X & 1X & 1X & 1X & 1.01X & \fix{1.10X} & 1.29X & 2.05X \\
\hline
\multirow{2}{*}{\begin{tabular}[l]{@{}l@{}}Particle\\Advection\end{tabular}} & $T_{rat}$ & 1X & 1X & 1.03X & 1.07X & \fix{1.14X} & 1.39X & 1.64X & 2.13X & 2.67X \\
                                    & $F_{rat}$ & 1X & 1X & 1.02X & 1.06X & \fix{1.13X} & 1.35X & 1.57X & 2.05X & 2.56X \\
\hline
\multirow{2}{*}{\begin{tabular}[l]{@{}l@{}}Volume\\Rendering\end{tabular}} & $T_{rat}$ & 1X & 1X & 1X & 1X & 1.06X & \fix{1.13X} & 1.24X & 1.45X & 1.81X \\
                                    & $F_{rat}$ & 1X & 1X & 1X & 1X & 1.06X & \fix{1.13X} & 1.23X & 1.45X & 1.82X \\
\hline
\end{tabular}
\caption[Performance of all algorithms explored in Chapter~\ref{ch:ipdps} using
a data set size of $256^3$ and reduced power limits.]{\label{table:algs-256-deck2}Slowdown factor for all algorithms with a
data set size of  $256^3$.
%
Slowdown is calculated by dividing execution time at 40W by execution time at
120W.
%
Numbers highlighted in red indicate the first time a 10\% slowdown in execution
time or frequency occurs due to the processor power cap $P$.}
\end{table*}

\subsection{Phase 3: Data Set Size}
\label{sec:ch3-res-datasize}

Phase 3 extended Phase 2 by varying over data set size.
%
Table~\ref{table:algs-256-deck2} shows the results for all algorithms using a
data set size of $256^3$.
%
This table can be compared to Table~\ref{table:algs-128-deck2} in
Section~\ref{sec:ch3-res-algs}.

As the data set size is increased from $128^3$ in
Table~\ref{table:algs-128-deck2} to $256^3$ in
Table~\ref{table:algs-256-deck2}, $T_{ratio}$ changes across algorithms.
%
For the power opportunity algorithms identified in Phase 2, $T_{ratio}$
exceeds 1.1X at higher power caps with larger data set sizes.
%
As an example, spherical clip did not have significant slowdowns until 50W with a
data set size of $128^3$, but now has similar slowdowns at 70W.
%
Other algorithms in this category, such as contour, threshold, slice, and
ray tracing, now slowdown at 60W and 50W with a data set size of $256^3$ instead
of slowing down at 40W with a data set size of $128^3$.

\begin{figure}
\centering
%\includegraphics[width=2.7in]{images/ipc_slice_deck2.pdf}
\includegraphics[width=0.6\columnwidth]{images/chapter3/oct15_ipc_slice_deck2.pdf}
\caption[Algorithms that increase in instructions per cycle with increasing
data set size: slice, contour, isovolume, threshold, and spherical
clip.]{\label{fig:ipc-datasize-slice}This category of algorithms sees an
increase in IPC as the data set size increases.
%
Algorithms that fall into this category are slice, contour, isovolume,
threshold, and spherical clip.
}
\end{figure}

\begin{figure}
\centering
\includegraphics[width=0.6\columnwidth]{images/chapter3/oct15_ipc_volren_deck2.pdf}
\caption[Algorithms that increase in instructions per cycle with decreasing
data set size: volume rendering.]{\label{fig:ipc-datasize-volren}This category
of algorithms sees an
increase in IPC as the data set size decreases.
%
Volume rendering is the only algorithm exhibiting this behavior.
}
\end{figure}

\begin{figure}
\centering
\includegraphics[width=0.6\columnwidth]{images/chapter3/oct15_ipc_particleadvection_deck2.pdf}
\caption[Algorithms that have no change in instructions per cycle with changes
in data set size: particle advection and ray
tracing.]{\label{fig:ipc-datasize-padvect}This category of algorithms see no
change in IPC as the data set size changes.
%
Algorithms exhibiting this behavior are particle advection and ray tracing.
}
\end{figure}

Depending on the algorithm, the IPC may increase or decrease as the data set
size is increased.
%
Figure~\ref{fig:ipc-datasize-slice}, Figure~\ref{fig:ipc-datasize-volren}, and
Figure~\ref{fig:ipc-datasize-padvect} show the IPC for three different
algorithms over all power caps and data set sizes.
%
The IPC of the three different algorithms shown in the figures represent
three categories.

The first category consists of slice, contour, isovolume, threshold, and
spherical clip.
%
As the data set size increases, the IPC also increases for these algorithms as
shown in Figure~\ref{fig:ipc-datasize-slice}.
%
Particularly for slice and spherical clip, the number of instructions increases with
a larger number of elements (\ie bigger data set size) because for each cell, the
algorithm computes the signed distance.
%
The other algorithms in this category --- contour, isovolume, and threshold ---
iterate over each cell, so the number of comparisons will also increase (\ie
for threshold, keep this cell if it meets some criteria, else discard).
%
Algorithms in this category tend to have lower IPC values.
%
These algorithms contain simple computations, so the loads and stores of the
data (\ie memory instructions) dominate the execution time.

The second category contains volume rendering, which shows an inverse
relationship between data set size and IPC as shown in
Figure~\ref{fig:ipc-datasize-volren}.
%
Here, the IPC increases as the data set size decreases.
%
As an example, as the data set size increases from $128^3$ to $256^3$ (8X
bigger), the IPC only drops by $20\%$ going from 2.5 down to 2.
%
On average, the IPC of volume rendering is higher than any of the other
algorithms explored in this chapter.
%
Volume rendering is an image-order algorithm and has a high number of floating
point instructions resulting in high power and high IPC.

The third category consists of algorithms whose IPC does not change with
increases in data set sizes as illustrated in
Figure~\ref{fig:ipc-datasize-padvect}.
%
The algorithms identified here are particle advection and ray tracing.
%
For particle advection, we held the following constant regardless of the data
set size: the same number of seed particles, step length, and number of steps.
%
Because we chose to keep these parameters consistent, particles may get
displaced outside the bounding box depending on the data set size.
%
When particles are displaced outside the bounding box, they terminate, and
there is no more work to do for that particle.

Particle advection has a high IPC value, and a high power consumption.
%
The advection implementation uses the Runge-Kutta, which is the 4th order
method to solve ordinary differential equations.
%
This method is computationally very efficient and has a large number of high
power instructions.

The ray tracing algorithm consists of three steps: building a spatial
acceleration structure, triangulation, and tracing the rays.
%
The amount of computation does not scale at the same rate as the data set size.
%
An increase in the data set size by a factor of 8 (going from $128^3$ to
$256^3$) results in only a 4X increase in the number of faces encountered.
