// prntspot.h
// desc: header for functions and classes
// vers: 0.01

#include <sys/ioctl.h>

#include "prntspot.h"


prntspot::prntspot() {
	set_window_size();
}

int prntspot::max_height() {
	return window_height;
}

int prntspot::max_width() {
	return window_width;
}

void prntspot::set_window_size() {
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	window_width = w.ws_row;
	window_height = w.ws_col;
}
