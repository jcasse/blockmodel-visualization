## Synopsis

[//]: # (At the top of the file there should be a short introduction and/ or overview that explains **what** the project is. This description should match descriptions added for package managers (Gemspec, package.json, etc.))

Interactive GUI application that helps the user to visualize a 3-way clustering
of data arranged in a 3-dimensional array by displaying a cube-like
representation of it and allowing the user to rotate the cube on a
3-dimensional Cartesian plane.

The program uses block model data: a) parition sizes and b) block densities.
With this information, the program determines how many blocks there are and
computes their centers and their dimensions. The centers are computed relative
to the origin---bottom left front corner. The block densities are used to
determine the block's shade of grey.

The program should be run locally. If run while remotely connected to another
machine, the graphics will be very slow due to the graphics card residing
locally and having to get the data remotely.

## Code Example

[//]: # (Show what the library does as concisely as possible, developers should be able to figure out **how** your project solves their problem by looking at the code example. Make sure the API you are showing off is obvious, and that your code is short and concise.)

type at command line: ./main dir

main: the name of the executable
dir: the folder (absolute) where the input data resides

To quit: press 'esc' key

Example:

main ~/Research/datasets/multi/binary_3d/multi-clustering/multi-clustering_20120901090553/

## Motivation

[//]: # (A short description of the motivation behind the creation and maintenance of the project. This should explain **why** the project exists.)

To help in my research.

## Installation

[//]: # (Provide code examples and explanations of how to get the project.)

TODO

## API Reference

[//]: # (Depending on the size of the project, if it is small and simple enough the reference docs can be added to the README. For medium size to larger projects it is important to at least provide a link to where the API reference docs live.)

TODO

## Tests

[//]: # (Describe and show how to run the tests with code examples.)

TODO

## Contributors

[//]: # (Let people know how they can dive into the project, include important links to things like issue trackers, irc, twitter accounts if applicable.)

TODO

## License

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

