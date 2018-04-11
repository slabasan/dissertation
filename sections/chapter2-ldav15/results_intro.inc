In this section, we describe results from the six phases
detailed in Section~\ref{sec:ch2-methodology}.
%
Before doing so, we consider an abstract case, as the
analysis of this abstract case is common to the analysis of each phase.
%
We also define terms that we use throughout this section.

Assume a visualization algorithm,
when running at the default clock frequency of $F_D$,
takes time $T_D$ seconds to run,
consumes a total energy of $E_D$ Joules, and
requires an average power of $P_D$ Watts
(with $P_D = E_D / T_D$).
%
Further assume that same visualization algorithm,
when reducing the clock frequency to $F_R$,
takes $T_R$ seconds,
consumes a total of $E_R$ Joules,
and requires an average of $P_R$ Watts
(once again with $P_R = E_R / T_R$).
%
We then define the following terms:
%
\begin{itemize}
\item $F_{rat} = F_D / F_R$.  This is the ratio of the clock frequencies.
If the clock frequency was slowed down by a factor of two, then $F_{rat} = 2$.
%
\item $T_{rat} = T_R / T_D$.  This is the ratio of elapsed time.
If the algorithm runs twice as slow, then $T_{rat} = 2$.
%
\item $E_{rat} = E_D / E_R$.  This is the ratio of energy consumed.
If the energy consumed is reduced by a factor of two, then $E_{rat} = 2$.
%
\item $P_{rat} = P_D / P_R$.  This is the ratio of power usage.
If the power usage is reduced by a factor of two, then $P_{rat} = 2$.
\end{itemize}

Note that three of the terms have the value for the
default clock frequency in the
numerator and the value for the reduced clock frequency in the denominator,
but that $T_{rat}$ flips them.
%
This flip simplifies comparison across terms, since it makes all ratios be greater than 1.

We then find these three pairs of terms noteworthy:
\begin{itemize}
\item $F_{rat}$ and $T_{rat}$: When $T_{rat}$ is less than $F_{rat}$,
the data-intensive nature of the visualization algorithm enabled the program to slow
down at a rate less than the reduction in clock frequency.
\item $T_{rat}$ and $E_{rat}$: This pair represents a proposition for
visualization consumers (\ie visualization scientists
or simulation scientists who use visualization software):
``if you are willing to run the visualization ($T_{rat}$) times slower, then
you can use ($E_{rat}$) times less energy."
\item $T_{rat}$ and $P_{rat}$: This pair represents a related proposition for
visualization consumers:
``if you are willing to run the visualization ($T_{rat}$) times slower, then
you can use ($P_{rat}$) times less power when doing so."
%
This power proposition would be
useful for those that want to run a computing cluster at a fixed power rate.
\end{itemize}

\input{sections/chapter2-ldav15/results_BaseCase.inc}
\input{sections/chapter2-ldav15/results_DataSet.inc}
\input{sections/chapter2-ldav15/results_ProgModel.inc}
\input{sections/chapter2-ldav15/results_Concurrency.inc}
\input{sections/chapter2-ldav15/results_Implement.inc}
\input{sections/chapter2-ldav15/results_Arch.inc}
