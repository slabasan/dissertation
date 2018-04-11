Our study explored the impacts of power constraints on scientific visualization
algorithms.
%
We considered a set of eight representative algorithms, nine different
processor-level power caps, and four data set sizes, totaling 288 total test
configurations.
%
We believe the results of the study provide insights on the behavior of
visualization algorithms on future exascale supercomputers.
%
In particular, this study showed that visualization algorithms use little
power, so applying an extremely low power cap will not impact the performance.
%
(Refer back to Section~\ref{sec:ch3-summary} for specific findings.)
%
We believe these findings can be used to dynamically reallocate power between
competing applications (\ie simulation and visualization) when operating under
a power budget.
%
The runtime system would identify visualization workflows that are compute- or
data-bound and allocate power accordingly, such that the scarce power is used
wisely.

This study suggests several interesting directions for future work.
%
Our results identified two different classes of algorithms.
%
These findings can be applied to other visualization algorithms in making informed
decisions about how to allocate power for visualization workflows.
%
While most of the algorithms explored in this chapter consumed low power and were
data-bound, we did find two algorithms (particle advection and volume
rendering) that did not fall into this category.
%
This indicates there may be other visualization algorithms that might fall into
the category of high power usage and compute intensity.
%
Another extension of this work is to explore how the power and performance
tradeoffs for visualization algorithms compare across other architectures that
provide power capping mechanisms.
%
Other architectures may exhibit different responses to power limits, and so it is
unclear how the underlying architecture will affect the algorithms.
