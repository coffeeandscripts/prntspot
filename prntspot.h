// prntspot.cpp
// desc: prntspot engine with functions and variables
// vers: 0.01

class bufferCh {
	public:
	bufferCh();
	void set_ch(char);
	void set_ch(char,int,int);
	void set_next_ch(bufferCh*);
	bufferCh* return_next_ch();
	char return_ch();
	void print_ch();
	private:
	bufferCh* next_ch;
	char ch;
	int color;
	int style;
};

class prntspot {
	public:
	prntspot();
	void print_buffer();
	void new_line();
	int max_height();
	int max_width();
	int set_left_buffer(std::string);
	int set_right_buffer(std::string);
	int set_point_buffer(std::string,int);
	int set_left_buffer(std::string,int,int);
	int set_right_buffer(std::string,int,int);
	int set_point_buffer(std::string,int,int,int);
	private:
	int window_width;
	int window_height;
	int buffer_len;
	void extend_buffer();
	bufferCh* first_ch;
	void set_window_size();
};
