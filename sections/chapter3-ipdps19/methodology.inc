This study consisted of three phases.
%
Phase 1 studied a base case, and subsequent phases studied the impacts of
varying one of the study factors listed in Subsection~\ref{sec:ch3-factors}.

\subsubsection{Phase 1: Processor-Level Power Cap}
Phase 1 varied the processor-level power caps and studied the behavior of the
contour algorithm implemented in VTK-m.
%
With this phase, we extended a previous finding~\cite{7348074}, which
determined baseline performance for isosurfacing by explicitly setting CPU
frequencies.
%
This phase consisted of nine tests.

\noindent{\textbf{\emph{Test Configuration}}: (Contour algorithm, $128^3$ data set size)
$\times$ 9 processor power caps}

\subsubsection{Phase 2: Visualization Algorithm}
In this phase, we continued varying processor-level power caps, and added
variation in visualization algorithm.
%
It consisted of 72 tests, nine of which were studied in Phase 1.

\noindent{\textbf{\emph{Test Configuration}}: ($128^3$ data set size)
$\times$ 9 processor power caps $\times$ 8 visualization
algorithms}

\subsubsection{Phase 3: Data Set Size}
In this phase, we add variation in data set size.
%
It consisted of 288 tests, of which nine were studied in Phase 1 and 63 were
studied in Phase 2.

\noindent{\textbf{\emph{Test Configuration}}: 9 processor power caps $\times$ 8
visualization algorithms $\times$ 4 data set sizes}
