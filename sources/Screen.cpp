#include <fstream>
#include <string>

#include <curses.h>

#include "../headers/Screen.hpp"


namespace iagw
{
//=====================================
//	Screen class implementation
//=====================================
	Screen::Screen():
		RenderTarget(10, 10)
	{
		initScreen();
	}

	Screen::Screen(int32_t x, int32_t y):
		RenderTarget(x, y)
	{

	}

	Screen::~Screen()
	{
		// 	dealocate memory and end ncurses
		//	put terminal back in normal mode
		endwin();
	}


	void 	Screen::printCh(int32_t x, int32_t y, uint8_t b_col, uint8_t f_col, char ch)
	{
		uint8_t temp_col = (b_col * 8) + f_col;

		mvchgat(y, x, 1, NULL, temp_col, NULL);
		m_has_moved = TRUE;
	}

	void 	Screen::show()
	{ refresh(); }

	void 	Screen::clear()
	{ erase(); m_has_moved = TRUE; }

	void 	Screen::initScreen()
	{
		// initialize the screen, set up memory
		if(initscr() == NULL)
		{
			fprintf(stderr, "Error initialising ncurses.\n");
			exit(EXIT_FAILURE);
		}
		//	disable buffering of typed chars by the TTY driver
		cbreak();
		//	suppress automatic echoing of typed characters
		noecho();
		//	capture special keystrokes like Delete and the arrow keys
		keypad(stdscr, TRUE);
		//	Set the cursor to invisible
		curs_set(0);

//		m_window = create_newwin(size_x, size_y, 0, 0);
		getmaxyx(stdscr, size_y, size_x);

		printw("this screen is: %d x %d", size_x, size_y);
		show();

		initColors();
	}

	void 	Screen::initColors()
	{
		if((m_has_colors = has_colors()) == FALSE)
			printw("you terminal does not support color!\n");
		else
		{
			start_color();
			//	color_pair 0 is initialized before color
			//	cannot be modified by the program
			for(int i = 0; i < 8; i++)
			{
				for(int j = 0; j < 8; j++)
				{
					if((i != 0) || (j != 0))
						init_pair(((i * 8) + j), j, i);
				}
			}
		}
	}
}
