\section{Overview of Visualization Algorithms}

We explored eight algorithms for this study.
%
We believe this set of algorithms is representative of the behaviors and
characteristics commonly found across all visualization algorithms.
%
We provide a brief description of each of the eight algorithms in the following
subsections (see Figure~\ref{fig:teasers} for a rendered image of each algorithm).

\subsection{Contour}
%
For a three-dimensional scalar volume, the output of a contour is a surface
representing points of a constant value (\ie isovalue).
%
For this study, the data set consisted of hexahedrons and the algorithm used
was Marching Cubes~\cite{Lorensen:1987:MCH:37401.37422}.
%
The contour algorithm iterates over each cell in the data set, identifying
cells that contain the constant value.
%
The algorithm uses pre-computed lookup tables in combination with interpolation
to generate triangles that represent the surface, and the resulting geometry is
combined into the output data set.
%
We used 10 different isovalues for a single visualization cycle.

\subsection{Threshold}
%
The threshold algorithm iterates over every cell in the data set and compares
it to a specified value or range of values.
%
Cells containing the value are included in the output data set, while cells not
containing the value are removed.

\subsection{Spherical Clip}
%
Spherical clip culls geometry within a sphere specified by an origin and a
radius.
%
The algorithm iterates over each cell and finds the distance of that cell from
the center of the sphere.
%
Cells completely inside the sphere are omitted from the output data set, while
cells completely outside the sphere are retained in entirety, and passed
directly to the output.
%
If the cell contains the surface of the sphere, then the cell is subdivided
into two parts, with one part inside the sphere and the other part outside the
sphere, and each part is handled as before.

\subsection{Isovolume}
%
Isovolume and clip are similar algorithms.
%
Instead of an implicit function (\eg sphere), an isovolume evaluates each cell
within a scalar range.
%
Cells completely inside the scalar range are passed directly
to the output, and cells completely outside the scalar range are removed from
the output.
%
If the cell lies partially inside and outside the scalar range, the cell is
subdivided and the part outside the range is removed.

\subsection{Slice}
%
A slice cuts the data set on a plane, resulting in a two-dimensional data set.
%
In order to create the slice, a new field is created on the data set
representing the signed distance field from the plane (\eg if the signed
distance is 0, then the point is on the plane).
%
Then, the contour algorithm evaluates the field at an isovalue of 0, resulting
in a topologically two-dimensional plane.
%
In this study, we evaluated three slices on the $x$-$y$, $y$-$z$, and $x$-$z$ planes,
resulting in a three-dimensional data set.

\subsection{Particle Advection}
%
The particle advection algorithm advects massless particles through a vector
field.
%
Particles are seeded throughout the data set, and advected for a user-specified
number of steps.
%
For this study, we advected the particles through a steady state (\ie a single
time step).
%
The algorithm outputs a data set representing the path of each particle through
the number of steps in the form of lines (\ie streamlines).

\subsection{Ray Tracing}
%
Ray tracing is a rendering method that iterates over pixels in the image.
%
Rays are intersected with the data set to find the nearest intersection.
%
Ray tracing uses a spatial acceleration structure to minimize the amount of
intersection tests that are performed on the data set.
%
If an intersection is found, then a color is determined by the scalar field.
%
The output of the ray tracing algorithm is an image.
%
For this study, we created an image database consisting of 50 images per
visualization cycle generated from
different camera positions around the data set.

\subsection{Volume Rendering}
%
Volume rendering is another rendering method that iterates over pixels in
the image.
%
Rays step through the volume and sample scalar values at regular
intervals.
%
Each sample is mapped to a color containing a transparency component, and all
samples along the ray are blended together to form the final color.
%
For this study, we created an image database consisting of 50 images per
visualization cycle generated from different camera positions around the data set.
