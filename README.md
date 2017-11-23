# prntspot
## description
C++ library to handle printing anywhere on a single line.

Using simple standard library commands, this library allows for a program to print to anywhere on the same line of a console screen. This allows for interactive and variable displays. Included are colors and styles. Examples of usage are below:

~~~
#include <iostream>
#include <string>
#include <unistd.h>

#include "prntspot.h" 							// imports

int main() {
	prntspot printer; 						// initialization
	printer.set_left_buffer("Loading:", RED_F, BOLD); 		// sets left side
	printer.append_buffer(" [", YELLOW_F, BOLD); 			// adds to content
	printer.set_right_buffer("]", YELLOW_F, BOLD); 			// sets right side
	printer.print_buffer(); 					// prints to console
	for (int x=0; x < (printer.max_width() - 11); x++) {
		printer.set_point_buffer("#", BLUE_F, BOLD, 10+x); 	// adjusts single points
		usleep(100000);
		printer.print_buffer();
	}
	printer.new_line(); 						// ends line and resets bufer
	printer.set_left_buffer("New line here");
	printer.print_buffer();
	printer.new_line();
}
~~~
This will show the following result:

<img src="https://raw.githubusercontent.com/coffeeandscripts/prntspot/master/example.gif" width="800px">

The library includes the following public functions:
~~~
prntspot(); 						// constructor
~prntspot(); 						// destructor
void print_buffer(); 					// prints line
void new_line(); 					// ends line and resets buffer
int max_height(); 					// returns height of window as int
int max_width(); 					// returns width of window as int
void set_left_buffer(std::string); 			// sets buffer from left
void append_buffer(std::string); 			// adds to the buffer
void set_right_buffer(std::string); 			// sets buffer from right
void set_point_buffer(std::string,int); 		// sets buffer at any points
void set_left_buffer(std::string,int,int); 		// includes color and styles
void append_buffer(std::string,int,int);
void set_right_buffer(std::string,int,int);
void set_point_buffer(std::string,int,int,int);
void reset_buffer(); 					// clears the buffer

~~~
The library includes the following colors and styles:
~~~
// FOREGROUND COLORS
#define BLACK_F 30
#define RED_F 31
#define GREEN_F 32
#define YELLOW_F 33
#define BLUE_F 34
#define MAGENTA_F 35
#define CYAN_F 36
#define WHITE_F 37

// BACKGROUND COLORS
#define BLACK_B 40
#define RED_B 41
#define GREEN_B 42
#define YELLOW_B 43
#define BLUE_B 44
#define MAGENTA_B 45
#define CYAN_B 46
#define WHITE_B 47

// STYLES
#define BOLD 1
#define BRIGHT 1
#define UNDERLINE 4
#define INVERSE 7

~~~

## license
prntspot - C++ library to handle printing anywhere on a single line

Copyright (c) 2017 coffeeandscripts

coffeeandscripts.github.io

This program is free software: you can redistribute it and/or modigy it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.
