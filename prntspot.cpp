// prntspot.h
// desc: header for functions and classes
// vers: 0.01

#include <sys/ioctl.h>
#include <string>
#include <iostream>

#include "prntspot.h"

bufferCh::bufferCh() {
	next_ch == NULL;
}

void bufferCh::set_ch(char tmp_ch) {
	ch = tmp_ch;
}

char bufferCh::return_ch() {
	return ch;
}

void bufferCh::set_next_ch(bufferCh* pCh) {
	next_ch = pCh;
}

bufferCh* bufferCh::return_next_ch() {
	return next_ch;
}


prntspot::prntspot() {
	set_window_size();
	first_ch = new bufferCh;
}

void prntspot::print_buffer() {
	bufferCh* ch = first_ch;
	while (ch->return_ch() != '\0') {
		std::cout << ch->return_ch();
		ch = ch->return_next_ch();
	}
}

void prntspot::new_line() {
	std::cout << '\n';
}

int prntspot::max_height() {
	return window_height;
}

int prntspot::max_width() {
	return window_width;
}

int prntspot::set_left_buffer(std::string str) {
	bufferCh* ch = first_ch;
	for (int i=0; i < str.size(); i++) {
		ch->set_ch(str[i]);
		ch->set_next_ch(new bufferCh);
		ch = ch->return_next_ch();
	}
	ch->set_ch('\0');
}

int prntspot::set_right_buffer(std::string str) {

}

int prntspot::set_point_buffer(std::string str, int offset) {

}

void prntspot::set_window_size() {
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	window_width = w.ws_row;
	window_height = w.ws_col;
}
