Power is a central issue for achieving future
breakthroughs in high performance computing (HPC).
%
As today's leading edge supercomputers require between 5 and 18 MegaWatts
to power, and
as the cost of one MegaWatt-year is approximately one million US dollars,
supercomputing centers regularly spend over five million US dollars per year,
and sometimes exceed ten million US dollars per year.
%
Worse, power usage is proportional to the size of the machine;
scaling up to even larger machines will cause power usage (and associated
costs) to grow even larger.
%
Applying today's designs to exascale computing would cost hundreds of millions
of US dollars to power.
%
As a result, the HPC community has made power efficiency a central issue,
and all parts of the HPC ecosystem are being re-evaluated in the search
for power savings.

Supercomputers require a varying amount of power.
%
When running programs that stay within the machine's
normal operating limits, the amount of power
often matches the usage for when the machine is idle.
%
However,
programs that engage more of the hardware --- whether it is caches, additional
floating point units, etc. --- use more power.
%
HPL (High Performance Linpack), a benchmark
program that is computationally intensive,
has been known to triple power usage,
since HPL has been highly optimized and makes intense use of the hardware.
%
However, many visualization programs
have not undergone the same level of optimization,
and thus only require power near the machine's idle rate.
That said, alternate approaches exist
that do create opportunities for data-intensive programs --- \ie visualization programs --- to achieve
energy savings.

As power usage is highly dependent on clock frequency,
reductions in frequency can lead to significant power
savings.
%
On the face of it, reducing the clock frequency seems like, at best,
a break-even
strategy --- \ie running at half the speed should take twice
as long to execute.
%
However, visualization programs are different than traditional HPC workloads,
since many visualization algorithms are data-intensive.
%
So, while HPC workloads engage floating point units (and thus drive up power),
visualization workloads make heavier use of cache.

The data-intensive nature of visualization algorithms creates an
opportunity: newer architectures have controls for slowing down the clock
frequency, but keeping the cache operating at a normal speed.
%
In this case, power is being devoted to the cache at the same rate
(which is good because cache is often a bottleneck), but power is
devoted to the CPU at a lower rate (which is also good because the CPU
is being under-utilized).
%
As the extreme outcome, then, it is conceivable that
slowing down the clock frequency (and keeping the caches operating
at full speed) could lead to a scenario where the execution time
is the same (since the cache performance dominates), but the power usage drops.

With this study, we explore the efficacy of varying clock speed to
achieve energy savings.
%
The achieved effects vary based on myriad factors, and we endeavor to understand
those factors and their impacts.
%
Our study focuses on a representative visualization algorithm (isosurfacing),
and looks at how that algorithm performs under a variety of configurations
seen in HPC settings.
%
We find that these configurations have real impacts on power-performance tradeoffs,
and that some approaches lend themselves to better energy efficiency than others.
