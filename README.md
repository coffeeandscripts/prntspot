# prntspot
## description
C++ library to handle printing anywhere on a single line.

Using simple standard library commands, this library allows for a program to print to anywhere on the same line of a console screen. This allows for interactive and variable displays. Included are colors and styles. Examples of usage are below:

~~~
prntspot printer; 					// initializes the printing engine
printer.set_left_buffer("Loading: ["); 			// sets text from left
printer.set_right_buffer("]"); 				// sets text from right
printer.print_buffer(); 				// prints to console
for (int x=0; x < (printer.max_width() - 11); x++) { 	// compares to width of console
	printer.set_point_buffer("#", 34, 1, 10+x); 	// sets text anywhere in buffer, blue and bold
	usleep(500000); 				// wait from unistd.h
	printer.print_buffer();
}
printer.new_line(); 					// prints a new line

~~~

## license
prntspot - C++ library to handle printing anywhere on a single line

Copyright (c) 2017 coffeeandscripts

coffeeandscripts.github.io

This program is free software: you can redistribute it and/or modigy it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.
