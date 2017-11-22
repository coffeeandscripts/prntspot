// tests.cpp
// desc: main function to run tests for prntspot
// vers: 0.01

#include <iostream>
#include <string>
#include <unistd.h>

#include "prntspot.h"

int main() {
	prntspot printer;
	printer.set_left_buffer("Loading: [");
	printer.set_right_buffer("]");
	printer.print_buffer();
	for (int x=0; x < (printer.max_width() - 11); x++) {
		printer.set_point_buffer("#", 10+x);
		usleep(500000);
		printer.print_buffer();
	}
	printer.new_line();
}
