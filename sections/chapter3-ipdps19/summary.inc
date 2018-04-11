%\newtodo{Redundancy between summary and conclusion?}

One of the key goals of this chapter was to identify the impacts of various
factors on power usage and performance of visualization algorithms in order to
better inform scientists and tool developers.
%
This chapter is an extension of the work in Chapter~\ref{ch:ldav}, which
performed an initial exploration of the feasibility of achieving energy and
power savings with reduced clock frequencies.
%
With this chapter, we performed a more in-depth study of the power and
performance tradeoffs for a representative set of visualization algorithms.
%
Specifically, this chapter identifies the environment in which variation occurs
in visualization.
%
We summarize the findings from the previous sections here.

On varying processor power caps (Section~\ref{sec:ch3-res-powcaps}):
%
\begin{itemize}
%
\item The VTK-m implementation of contour is sufficiently data intensive to
avoid a significant slowdown from reducing the power cap.
%
This extends a previous finding~\cite{7348074} which set CPU frequencies and
used a custom implementation, and is additionally noteworthy since our study
uses a general toolkit designed to support a wide variety of algorithms and
data types.
%
\item The execution time remains unaffected until an extreme power cap of 40W,
creating opportunities for redistributing power throughout the system to
more critical phases or applications.
%
\end{itemize}

On comparing different visualization algorithms (Section~\ref{sec:ch3-res-algs}):
%
\begin{itemize}
\item Most of the visualization algorithms studied in this chapter consume low
amounts of power, so they can be run under a low power cap without
impacting performance.
%
These algorithms have lower IPC values, characteristic of data-bound
workloads.
\item Two of the explored algorithms consume higher power, similar to what we
commonly see of traditional compute-bound benchmarks, such as Linpack.
%
These algorithms will see significant slowdown from being run at a lower power
cap, up to 3.2X.
%
As such, the slowdown begins around 80W, roughly 67\% of TDP.
%
These algorithms have high IPC values, which are characteristic of
compute-bound workloads.
\end{itemize}

On varying the input data set size (Section~\ref{sec:ch3-res-datasize}):
%
\begin{itemize}
\item Larger data set sizes result in poorer tradeoffs for performance.
%
With a higher data set size, these algorithms start to slowdown at higher power
caps.
%
So instead of seeing a 10\% slowdown at 50W with a data set size of $128^3$,
the slowdown begins at 70W for a data set size of $256^3$.
\item For the algorithms that were significantly compute-bound (and consuming
high amounts of power), the change in data set size does not impact the power
usage.
\end{itemize}

These recipes can be applied to two use cases in the context of a
power-constrained environment.
%
First, when doing post hoc visualization and data analysis on a shared cluster,
requesting the lowest amount of power will leave more for other power-hungry
applications.
%
Second, when doing in situ visualization, appropriately provisioning power for
visualization can either leave more power for the simulation or improve
turn-around time for the visualization pipeline.
%
These results can be integrated into a job-level runtime system, like
PaViz~\cite{pgv.20171088} or GEOPM~\cite{geopm,10.1007/978-3-319-58667-0_21},
to dynamically reallocate the power to the various components within the job.
%
By providing more tailored information about the particular visualization
routine, the runtime system may result in better overall performance.
