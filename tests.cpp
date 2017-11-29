// tests.cpp
// desc: main function to run tests for prntspot
// vers: 0.02

#include <iostream>
#include <string>
#include <unistd.h>

#include "prntspot.h"

using prntspot::Foreground;
using prntspot::Background;
using prntspot::Style;

int main()
{
	prntspot::prntspot printer;

	printer.set_left_buffer("Loading:", Foreground::Red, Background::Default, Style::Bold);
	printer.append_buffer(" [", Foreground::Yellow, Background::Default, Style::Bold);
	printer.set_right_buffer("]", Foreground::Yellow, Background::Default, Style::Bold);
	std::cout << printer << std::endl;

	for (int x = 0; x < (printer.max_width() - 11); x++)
	{
		printer.set_point_buffer("#", Foreground::Blue, Background::Default, Style::Bold, 10 + x);
		usleep(100000);
		std::cout << printer;
	}

	return 0;
}
