// tests.cpp
// desc: main function to run tests for prntspot
// vers: 0.01

#include <iostream>
#include <string>

#include "prntspot.h"

int main() {
	prntspot printer;
	std::cout << "Height: " << printer.max_height() << '\n';
	std::cout << "Width:  " << printer.max_width() << '\n';
	std::string test = "Test string";
	printer.set_left_buffer(test);
	printer.print_buffer();
}
