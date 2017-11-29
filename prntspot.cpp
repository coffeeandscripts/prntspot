// prntspot.cpp
// desc: class function definitions for bufferCh and prntspot engine
// vers: 0.02

#include <exception>
#include <iostream>
#include <sys/ioctl.h>
#include "prntspot.h"

namespace prntspot
{
	// ------------------------
	// bufferCh implementation.
	// ------------------------

	bufferCh::bufferCh() {
		next_ch = nullptr;
		ch = '\0';
		fg_color = Foreground::Default;
		bg_color = Background::Default;
		style = Style::Default;
	}

	void bufferCh::set_ch(char tmp_ch) {
		ch = tmp_ch;
	}

	void bufferCh::set_ch(char tmp_ch, Foreground tmp_fg, Background tmp_bg, Style tmp_style) {
		ch = tmp_ch;
		fg_color = tmp_fg;
		bg_color = tmp_bg;
		style = tmp_style;
	}

	char bufferCh::return_ch() {
		return ch;
	}

	void bufferCh::set_next_ch(bufferCh * pCh) {
		next_ch = pCh;
	}

	bufferCh * bufferCh::return_next_ch() {
		return next_ch;
	}

	std::ostream & operator<< (std::ostream & stream, const bufferCh & character)
	{
		stream << "\033[";
		stream << static_cast<int>(character.style) << ";" << static_cast<int>(character.fg_color) << ";" << static_cast<int>(character.bg_color);
		stream << "m" << character.ch << "\033[0m";
		return stream;
	}

	// ------------------------
	// prntspot implementation.
	// ------------------------

	prntspot::prntspot() {
		set_window_size();
		first_ch = new bufferCh;
	}

	std::ostream & operator<< (std::ostream & stream, const prntspot & line)
	{
		stream << '\r';

		bufferCh * ch = line.first_ch;
		while (ch->return_ch() != '\0')
		{
			stream << *ch;
			ch = ch->return_next_ch();
		}

		stream << std::flush;
		return stream;
	}

	void prntspot::new_line() {
		std::cout << '\n';
		reset_buffer();
	}

	int prntspot::max_height() {
		return window_height;
	}

	int prntspot::max_width() {
		return window_width;
	}

	void prntspot::set_left_buffer(const std::string & str)
	{
		this->set_left_buffer(str, Foreground::Default, Background::Default, Style::Default);
	}

	void prntspot::set_left_buffer(const std::string & str, Foreground fg_color, Background bg_color, Style style)
	{
		if (str.size() <= max_width())
		{
			bufferCh* ch = first_ch;
			buffer_len = str.size();
			for (int i = 0; i < buffer_len; i++)
			{
				ch->set_ch(str[i], fg_color, bg_color, style);
				ch->set_next_ch(new bufferCh);
				ch = ch->return_next_ch();
			}

			ch->set_ch('\0');
		}
		else
		{
			throw std::length_error("[set_left_buffer] Buffer exceeds maximum bounds.");
		}
	}

	void prntspot::append_buffer(const std::string & str)
	{
		this->append_buffer(str, Foreground::Default, Background::Default, Style::Default);
	}

	void prntspot::append_buffer(const std::string & str, Foreground fg_color, Background bg_color, Style style)
	{
		if (buffer_len + str.size() <= max_width())
		{
			bufferCh* ch = first_ch;
			while (ch->return_ch() != '\0')
			{
				ch = ch->return_next_ch();
			}

			for (int i = 0; i < str.size(); i++)
			{
				ch->set_ch(str[i], fg_color, bg_color, style);
				ch->set_next_ch(new bufferCh);
				ch = ch->return_next_ch();
			}
			ch->set_ch('\0');
			buffer_len = buffer_len + str.size();
		}
		else 
		{
			throw std::length_error("[append_buffer] Buffer exceeds maximum bounds.");
		}
	}

	void prntspot::extend_buffer()
	{
		bufferCh* ch = first_ch;
		while (ch->return_ch() != '\0')
		{
			ch = ch->return_next_ch();
		}

		for (int i = 0; i < (window_width - buffer_len); i++)
		{
			ch->set_ch(' ');
			ch->set_next_ch(new bufferCh);
			ch = ch->return_next_ch();
		}

		ch->set_ch('\0');
		buffer_len = window_width;
	}

	void prntspot::set_right_buffer(const std::string & str)
	{
		this->set_right_buffer(str, Foreground::Default, Background::Default, Style::Default);
	}

	void prntspot::set_right_buffer(const std::string & str, Foreground fg_color, Background bg_color, Style style)
	{
		if (str.size() <= max_width())
		{
			extend_buffer();
			bufferCh* ch = first_ch;

			for (int n = 0; n < (buffer_len - str.size()); n++)
			{
				ch = ch->return_next_ch();
			}

			for (int i = 0; i < str.size(); i++)
			{
				ch->set_ch(str[i], fg_color, bg_color, style);
				ch = ch->return_next_ch();
			}
		}
		else
		{
			throw std::length_error("[set_right_buffer] Buffer exceeds maximum bounds.");
		}
	}

	void prntspot::set_point_buffer(const std::string & str, int offset)
	{
		this->set_point_buffer(str, Foreground::Default, Background::Default, Style::Default, offset);
	}

	void prntspot::set_point_buffer(const std::string & str, Foreground fg_color, Background bg_color, Style style, int offset)
	{
		if (offset + str.size() <= max_width())
		{
			extend_buffer();
			bufferCh* ch = first_ch;

			for (int n = 0; n < offset; n++)
			{
				ch = ch->return_next_ch();
			}

			for (int i = 0; i < str.size(); i++)
			{
				ch->set_ch(str[i], fg_color, bg_color, style);
				ch = ch->return_next_ch();
			}
		}
		else
		{
			throw std::length_error("[set_point_buffer] Buffer exceeds maximum bounds.");
		}
	}

	void prntspot::reset_buffer() {
		bufferCh* ch = first_ch;
		first_ch = new bufferCh;
		first_ch->set_ch('\0');
	}

	void prntspot::set_window_size()
	{
		winsize w;
		ioctl(0, TIOCGWINSZ, &w);
		window_width = w.ws_col;
		window_height = w.ws_row;
	}
}
