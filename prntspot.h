// prntspot.cpp
// desc: prntspot engine with functions and variables
// vers: 0.01

#define BLACK_F 30
#define RED_F 31
#define GREEN_F 32
#define YELLOW_F 33
#define BLUE_F 34
#define MAGENTA_F 35
#define CYAN_F 36
#define WHITE_F 37

#define BLACK_B 40
#define RED_B 41
#define GREEN_B 42
#define YELLOW_B 43
#define BLUE_B 44
#define MAGENTA_B 45
#define CYAN_B 46
#define WHITE_B 47

#define BOLD 1
#define BRIGHT 1
#define UNDERLINE 4
#define INVERSE 7

class bufferCh {
	public:
	bufferCh();
	~bufferCh();
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
	~prntspot();
	void print_buffer();
	void new_line();
	int max_height();
	int max_width();
	void set_left_buffer(std::string);
	void append_buffer(std::string);
	void set_right_buffer(std::string);
	void set_point_buffer(std::string,int);
	void set_left_buffer(std::string,int,int);
	void append_buffer(std::string,int,int);
	void set_right_buffer(std::string,int,int);
	void set_point_buffer(std::string,int,int,int);
	private:
	int window_width;
	int window_height;
	int buffer_len;
	void extend_buffer();
	bufferCh* first_ch;
	void set_window_size();
	void throw_error(int);
};
