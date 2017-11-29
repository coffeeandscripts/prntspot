// prntspot.h
// desc: header for prntspot and bufferCh
// vers: 0.02

#ifndef PRNTSPOT_H
#define PRNTSPOT_H

#include <ostream>
#include <string>

namespace prntspot
{
	enum class Foreground
	{
		Black = 30,
		Red = 31,
		Green = 32,
		Yellow = 33,
		Blue = 34,
		Magenta = 35,
		Cyan = 36,
		White = 37,
		Default = 39
	};

	enum class Background
	{
		Black = 40,
		Red = 41,
		Green = 42,
		Yellow = 43,
		Blue = 44,
		Magenta = 45,
		Cyan = 46,
		White = 47,
		Default = 49
	};

	enum class Style
	{
		Default = 0,
		Bold = 1,
		Bright = 1,
		Underline = 4,
		Inverse = 7
	};

	class bufferCh
	{
		public:
			bufferCh();
			void set_ch(char);
			void set_ch(char, Foreground, Background, Style);
			void set_next_ch(bufferCh*);
			bufferCh* return_next_ch();
			char return_ch();

			friend std::ostream & operator<< (std::ostream &, const bufferCh &);

		private:
			bufferCh* next_ch;
			char ch;
			Foreground fg_color;
			Background bg_color;
			Style style;
	};

	class prntspot
	{
		public:
			prntspot();
			void new_line();
			int max_height();
			int max_width();

			void set_left_buffer(const std::string &);
			void set_left_buffer(const std::string &, Foreground, Background, Style);

			void append_buffer(const std::string &);
			void append_buffer(const std::string &, Foreground, Background, Style);

			void set_right_buffer(const std::string &);
			void set_right_buffer(const std::string &, Foreground, Background, Style);

			void set_point_buffer(const std::string &, int);
			void set_point_buffer(const std::string &, Foreground, Background, Style, int);

			void reset_buffer();

			friend std::ostream & operator<< (std::ostream &, const prntspot &);

		private:
			int window_width;
			int window_height;
			int buffer_len;
			void extend_buffer();
			bufferCh* first_ch;
			void set_window_size();
	};

}

#endif // !PRNTSPOT_H