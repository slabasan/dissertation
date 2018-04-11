\begin{table}[h]
\centering
\begin{tabular}{||c|cccccc||}
\multicolumn{7}{c}{\textbf{PaViz Power Decisions}} \\
\hline
\backslashbox{Rank}{Cycle} & 0 & 1 & 2 & 3 & 4 & 5 \\
\hline
\hline
0 & 70W & 70W & 69W & 63W & 60W & 58W \\
\hline
1 & 58W & 58W & 59W & 58W & 59W & 61W \\
\hline
2 & 52W & 50W & 48W & 40W & 40W & 40W \\
\hline
3 & 76W & 77W & 75W & 70W & 66W & 65W \\
\hline
4 & 58W & 58W & 62W & 66W & 67W & 65W \\
\hline
5 & 61W & 62W & 62W & 58W & 60W & 65W \\
\hline
6 & 40W & 40W & 40W & 58W & 61W & 60W \\
\hline
7 & 65W & 65W & 66W & 68W & 67W & 66W \\
\hline
\hline
\end{tabular}
\caption[Comparing power allocation decisions by the adaptive and predictive
runtime systems for a single rendering workload. The per-node power decisions
assume a
processor power cap of 60W.]{\label{table:powlims-60}Comparing GEOPM and PaViz
specified power
limits for each node across all visualization cycles for Rendering Workload A.
%
The job power limit assumes a processor-level power cap of 60W.
}
\end{table}

We organize the results into several phases.
%
The first phase studies a base case.
%
Subsequent phases varied additional study parameters.
%
In each phase, we vary the processor power cap and analyze its impacts.

To evaluate the power scheduling strategies, we normalize the performance of
our adaptive and predictive strategies to the performance at a uniform power
distribution of 120W per processor, which is the maximum power draw for this
processor architecture.
%
The uniform power allocation strategy is currently used in practice.
%
With the GEOPM and PaViz runtime systems, each node may be assigned a different
power cap, but the sum total of the power caps is less than or equal to the job
power budget.

We focus on the scaled performance at the power caps in the region of interest.
%
Power caps towards the low-end of the range are limited power scenarios and
power caps towards the high-end are the unconstrained power consumption of the
application.

\begin{figure*}
\centering
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-speedup-configA-newbase.pdf}
    \caption{Scaled Performance}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-catwhisker-A.pdf}
    \caption{Workload Distribution}
\end{subfigure}
\caption[Comparing the performance of adaptive and predictive power scheduling
strategies for Workload A defined in
Chapter~\ref{ch:tpds}.]{\label{fig:suconfigA}The left figure shows the scaled
performance of the adaptive strategy in GEOPM's Power Balancer
and the predictive strategy in
PaViz to the Baseline for Rendering Workload A.
%
We normalize the performance to that of the Baseline, which applies a uniform
power cap of 120W, which is 3X higher than the lowest power cap of 40W.
%
The second y-axis shows the raw rendering times at each power cap, since the
scaled performance value does not provide this context.
%
The right figure shows the distribution in rendering execution times (\ie work)
per rank at each visualization cycle.
%
The input data at each cycle impacts the amount of time spent rendering by each
rank, as well as the execution time at each cycle.
}
\end{figure*}

\subsection{Base Case}
\label{sec:base}

In this phase, we focus on Rendering Workload A running on 8 nodes.
%
We sweep over all processor power caps, ranging from 120W down to 40W, and
compare the performance of the adaptive and predictive strategies.
%
The left figure in Figure~\ref{fig:suconfigA} shows the scaled performance for
the adaptive strategy in GEOPM's Power Balancer and the predictive strategy in
PaViz.
%
The performance of the scheduling strategies is compared to the Baseline
performance at a uniform power cap of 120W per processor.
%
The right figure shows the imbalanced rendering execution times per
visualization cycle across all ranks.
%
As the simulation iterates across time steps, the rendering time increases and
the work per rank varies.

At higher power caps, the Baseline, adaptive strategy, and predictive strategy
have the same performance because there is unlimited power, and not much room
for improvement by shifting power.
%
Similarly at a severe power cap of 40W, all three configurations have the same
performance because there is a minimum power cap and CPU frequency for safe and
reliable operation of the processor.

At power caps ranging between 80W and 50W, we start to see the differences in
using adaptation versus prediction on the highly irregular visualization
workload.
%
This is the range where the application is consuming all the available power
and benefits from shifting power intelligently.

At a processor power cap of 60W, we compare the power decisions made by the
adaptive and predictive strategy across all visualization cycles in
Table~\ref{table:powlims-60}.
%
For the first few cycles, GEOPM keeps all ranks at this power cap, since it
uses the first few iterations to identify the most and least effective nodes.
%
In the first cycle, the predictive strategy identifies rank 6 with having no
work to do, and reduces the power cap to the minimum for reliable operation.
%
At later visualization cycles, the adaptive strategy has identified the least
efficient ranks, and shifts power such that these nodes receive more power.

The distribution of render times in
Figure~\ref{fig:rendertimeperrank} shows rank 3 being assigned the most work, so
it is expected that both strategies will assign it the highest power cap.
%
In doing so, the adaptive and predictive strategies reduce overall execution
time and perform better than the baseline.

\subsection{Vary Workload Configuration}

In this set of tests, we vary across the remaining three rendering workload
configurations outlined in Table~\ref{table:renderconfigs}, using the same
number of nodes as in Section~\ref{sec:base}.
%
The goal of this study is to demonstrate how rendering parameters may impact
the potential for performance improvements.
%
If the visualization operation results in a high variance in the number of
active pixels to be rendered by each rank, there is more room to exploit the
imbalance by shifting power.
%
On the other hand, if there is an evenly distributed number of active pixels to
be rendered by each rank, this may inhibit the benefits of shifting power to
improve performance.

Figure~\ref{fig:suconfigB}, Figure~\ref{fig:suconfigC}, and
Figure~\ref{fig:suconfigD} compare the results of the adaptive strategy and
predictive strategy to the Baseline as well as the distribution of predicted
execution times over all visualization cycles.
%
These figures can be compared with Figure~\ref{fig:suconfigA}, which did the same
analysis for Rendering Workload A.
%
Compared to the previous Rendering Configuration A, the distribution of
execution times are more evenly balanced.

For these workload configurations, using prediction sees more benefit than
using adaptation in a similar range of power caps as before.
%
The prediction model identifies which ranks will have no work to do before the
visualization occurs.
%
Reducing the power of those ranks to the minimum enables more power to be given
to the ranks with lots of work to.
%
This allows them to run faster, complete their work in less time, and reduce
overall performance.
%
An adaptive strategy will also identify which ranks have less work to do, but
spends the first set of iterations performing the necessary analysis.

\begin{figure*}
\centering
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-speedup-configB-newbase.pdf}
    \caption{Scaled Performance}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-catwhisker-B.pdf}
    \caption{Workload Distribution}
\end{subfigure}
\caption[Comparing the performance of adaptive and predictive power scheduling
strategies for Workload B defined in
Chapter~\ref{ch:tpds}.]{\label{fig:suconfigB}The left figure shows the scaled
performance of the adaptive strategy in GEOPM's Power Balancer and the
predictive strategy in
PaViz to the Baseline for Rendering Workload B.
%
We normalize the performance to that of the Baseline, which applies a uniform
power cap of 120W, which is 3X higher than the lowest power cap of 40W.
%
The second y-axis shows the raw rendering times at each power cap, since the
scaled performance value does not provide this context.
%
The right figure shows the distribution in rendering execution times (\ie work)
per rank at each visualization cycle.
%
The input data at each cycle impacts the amount of time spent rendering by each
rank, as well as the execution time at each cycle.
}
\end{figure*}

\begin{figure*}
\centering
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-speedup-configC-newbase.pdf}
    \caption{Scaled Performance}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-catwhisker-C.pdf}
    \caption{Workload Distribution}
\end{subfigure}
\caption[Comparing the performance of adaptive and predictive power scheduling
strategies for Workload C defined in Chapter~\ref{ch:tpds}.]{\label{fig:suconfigC}The left figure shows the scaled performance of
the adaptive strategy in GEOPM's Power Balancer and the predictive strategy in
PaViz to the Baseline for Rendering Workload C.
%
We normalize the performance to that of the Baseline, which applies a uniform
power cap of 120W, which is 3X higher than the lowest power cap of 40W.
%
The second y-axis shows the raw rendering times at each power cap, since the
scaled performance value does not provide this context.
%
The right figure shows the distribution in rendering execution times (\ie work)
per rank at each visualization cycle.
%
The input data at each cycle impacts the amount of time spent rendering by each
rank, as well as the execution time at each cycle.
}
\end{figure*}

\begin{figure*}
\centering
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-speedup-configD-newbase.pdf}
    \caption{Scaled Performance}
\end{subfigure}
\hfill
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/feb17-catwhisker-D.pdf}
    \caption{Workload Distribution}
\end{subfigure}
\caption[Comparing the performance of adaptive and predictive power scheduling
strategies for Workload D defined in Chapter~\ref{ch:tpds}.]{\label{fig:suconfigD}The left figure shows the scaled
performance of the adaptive strategy in GEOPM's Power Balancer and the
predictive strategy in
PaViz to the Baseline for Rendering Workload D.
%
We normalize the performance to that of the Baseline, which applies a uniform
power cap of 120W, which is 3X higher than the lowest power cap of 40W.
%
The second y-axis shows the raw rendering times at each power cap, since the
scaled performance value does not provide this context.
%
The right figure shows the distribution in rendering execution times (\ie work)
per rank at each visualization cycle.
%
The input data at each cycle impacts the amount of time spent rendering by each
rank, as well as the execution time at each cycle.
}
\end{figure*}

\subsection{Vary Concurrency}

In this phase, we vary the node concurrency to compare the impacts of using
adaptation and prediction at scale.
%
The intuition is that at higher concurrency, there is a bigger work imbalance
per node as well as a larger job level power budget that can be reallocated
between nodes.
%
This phase focuses on Rendering Workload C, which is defined in
Table~\ref{table:renderconfigs}.
%
We sweep over processor power caps ranging between 50W and 70W, since previous
phases identified this range as the region of interest.
%
We weak scale the data size to maintain the same work per node.
%
Figure~\ref{fig:suconfigC-scale} shows the scaled performance for the adaptive
strategy in GEOPM and the predictive strategy in PaViz at different levels of
concurrency.

\begin{figure*}
\centering
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/125nodes-feb17-speedup-configC-newbase.pdf}
    \caption{125 Nodes}
\end{subfigure}
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/216nodes-feb17-speedup-configC-newbase.pdf}
    \caption{216 Nodes}
\end{subfigure}
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/343nodes-feb17-speedup-configC-newbase.pdf}
    \caption{343 Nodes}
\end{subfigure}
\begin{subfigure}[t]{0.45\columnwidth}
    \includegraphics[width=1\linewidth]{images/chapter5/512nodes-feb17-speedup-configC-newbase.pdf}
    \caption{512 Nodes}
\end{subfigure}
\caption[Comparing the performance of adaptive and predictive power scheduling
strategies for a single workload at high concurrencies.]
{\label{fig:suconfigC-scale}The scaled performance of the adaptive
strategy in GEOPM's Power Balancer and the predictive strategy in
PaViz to the Baseline for Rendering Workload C at higher levels of concurrency.
%
We normalize the performance to that of the Baseline, which applies a uniform
power cap of 120W.
%
The second y-axis shows the raw rendering times at each power cap, since the
scaled performance value does not provide this context.
}
\end{figure*}

For this rendering configuration, using a predictive strategy results in 27\%
improvement over an adaptive strategy.
%
As the concurrency increases, an increasing percentage of the nodes have very
little, or even no, geometry to render.
%
Figure~\ref{fig:speedup-diff} shows the difference in scaled performance between
PaViz and GEOPM.
%
The smallest differences in speedups occur at the highest processor power cap
of 120W, since power is unlimited (\ie the application is not consuming this
amount of power).
%
The difference is inversely related to the processor power cap.
%
That is to say, the difference grows as the power cap is reduced.
%
This is a result of efficiently reallocating the limited power to the nodes
that need it most.

The highest concurrency of 512 nodes shows the largest difference of 28\% at
the lowest node power cap of 100W (\ie 50W per processor).
%
The predictive strategy identifies the nodes with no work to do, setting the
lowest power cap, enabling some nodes with lots of work to do to run at 200W.
%
The adaptation strategy is not able to fully exploit the level of imbalance
across the nodes.

\begin{figure}
\centering
\includegraphics[width=3.3in]{images/chapter5/speedupdiff_concurrency.pdf}
\caption[Difference in performance between the predictive and adaptive power
scheduling strategies at varying power limits and concurrencies.]{\label{fig:speedup-diff}Difference in speedup between the adaptive and
predictive strategies at different levels of node concurrency.
}
\end{figure}
