\begin{figure}[ht]
\centering
\begin{subfigure}[t]{0.22\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter3/s1_0_contour.png}
    \caption{Contour}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.22\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter3/s1_0_threshold_adj.png}
    \caption{Threshold}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.22\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter3/s1_0_clip.png}
    \caption{Spherical Clip}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.22\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter3/s1_0_isovol_adj.png}
    \caption{Isovolume}
\end{subfigure}
\\
\begin{subfigure}[t]{0.22\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter3/s1_0_slice.png}
    \caption{Slice}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.22\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter3/particleadvection_bw.png}
    \caption{Particle Advection}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.22\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter3/s1_0_raytrace.png}
    \caption{Ray Tracing}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.22\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter3/s1_0_volren.png}
    \caption{Volume Rendering}
\end{subfigure}
\caption[Renderings of the representative set of visualization algorithms
explored in the thorough study in
Chapter~\ref{ch:ipdps}.]{\label{fig:teasers}Renderings of the
eight visualization algorithms explored in this study.
%
We believe this set of algorithms is representative of the execution behaviors
of the hundreds of existing visualization algorithms.
%
The images show the energy field at the 200th time step of the CloverLeaf
hydrodynamics proxy application.
}
\end{figure}

\section{Related Work}
\label{sec:ch3-relwork}

Prior works at the intersection of power and performance can be seen
in Section~\ref{sec:ch2-relwork}.
%
This chapter builds on the work described in
Chapter~\ref{ch:ldav}~\cite{7348074}, where we studied a single visualization
algorithm (isosurfacing) and considered explicit setting of the CPU frequency
(which is less favorable for managing power usage on exascale systems than more
recent power capping technologies such as Intel's Running Average Power Limit
(RAPL)~\cite{intel2017}, AMD's TDP
PowerCap~\cite{amd2013}, and IBM's
EnergyScale~\cite{ibmenergyscale}).
%
In our current study, we consider eight algorithms --- chosen to be
representative of most visualization algorithms --- and use the more current
technique of power capping.
%
Therefore, while the initial study~\cite{7348074} showed that a visualization
algorithm has unique power and performance tradeoffs, the current study is
considerably more comprehensive and also more relevant to exascale computing
(\ie power capping versus setting CPU frequencies).
%
Further, this study contains a series of findings that allow us to extrapolate
behavior to other visualization algorithms.
