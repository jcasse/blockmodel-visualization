[//]: # (Markdown: dillinger.io/ shows a nice example of Markdown commands with a viewer.)
[//]: # (Comments in Markdown: http://stackoverflow.com/questions/4823468/comments-in-markdown)
[//]: # (C++ Project Structure: http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/)
[//]: # (C++ Library Creation: http://www.adp-gmbh.ch/cpp/gcc/create_lib.html)

# Blockmodel Visualization

Interactive GUI application that helps the user to visualize a 3-way clustering
of data arranged in a 3-dimensional array by displaying a cube-like
representation of it and allowing the user to rotate the cube on a
3-dimensional Cartesian plane.

The program uses block model data: a) partition sizes and b) block densities.
With this information, the program determines how many blocks there are and
computes their centers and their dimensions. The centers are computed relative
to the origin---bottom left front corner. The block densities are used to
determine the block's shade of gray.

The program should be run locally. If run while remotely connected to another
machine, the graphics will be very slow due to the graphics card residing
locally and having to get the data remotely.

### Installation

```sh
$ git clone <git-repo-url>
$ cd blockmodel-visualization
$ make
```
### Usage

```sh
$ bin/blockmodel-visualization <input dir>
To quit: press 'esc' key

Example:

main ~/Research/datasets/multi/binary_3d/multi-clustering/multi-clustering_20120901090553/
```

License
----

[//]: # (A short snippet describing the license (MIT, Apache, etc.))

[//]: # (http://choosealicense.com/)

Copyright (C) 2016 Juan Casse

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
