#include <fstream>
#include <string>

#include "../headers/core_graphics.hpp"


namespace cg
{
	//	initialization of static constants
	vi2d Screen::vWorldOffset;
	float Screen::fWorldScale;


//=====================================
//	Point class implementation
//=====================================
	bool    Point::operator==(const Point& p) const
	{	return ((color == p.color) && (ch == p.ch));	}

	bool    Point::operator!=(const Point& p) const
	{	return ((color != p.color) || (ch != p.ch));	}


//=====================================
//	Screen class implementation
//=====================================
	Screen::Screen()
	{
		vWorldOffset = { 0, 0 };
		has_moved = FALSE;

		initScreen();
	}

	Screen::~Screen()
	{
		// dealocate memory and end ncurses
		endwin();
	}

	void    Screen::printCh(const Point& p, int32_t x, int32_t y)
	{
		x = x%size_x;
		y = y%size_y;

		mvaddch(y, x, p.ch);
		mvchgat(y, x, 1, NULL, p.color, NULL);

		has_moved = TRUE;
	}

	void 	Screen::printCh(int32_t x, int32_t y, uint8_t cs, char ch)
	{
		x = x%size_x;
		y = y%size_y;

		mvaddch(y, x, ch);
		mvchgat(y, x, 1, NULL, 0, NULL);

		has_moved = TRUE;
	}

	void 	Screen::move(vi2d move_vec)
	{
		vWorldOffset.x += move_vec.x;
		vWorldOffset.x = (vWorldOffset.x%size_x);
		vWorldOffset.y += move_vec.y;
		vWorldOffset.y = (vWorldOffset.y%size_y);
	}

	void 	Screen::show()
	{ refresh(); }

	void 	Screen::clear()
	{ erase(); has_moved = TRUE; }

	void 	Screen::initScreen()
	{
		// initialize the screen, set up memory, start color mode
		if(initscr() == NULL)
		{
			fprintf(stderr, "Error initialising ncurses.\n");
			exit(EXIT_FAILURE);
		}
		if(has_colors() == FALSE)
		{
			endwin();
			printf("you terminal does not support color!\n");
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

		getmaxyx(stdscr, size_y, size_x);
		start_color();

		for(int i = 0; i < 8; i++)
			init_pair(i, i, 0);

		printw("this screen is: %d x %d", size_x, size_y);
		show();
	}
}


/*
//	Negative screen::move() fucks up everything
void 	Screen::printBackground()
{
	if(changes_ready)
	{
		for(int i = 0; i < size_x; i++)
		{
			for(int j = 0; j < size_y; j++)
			{
				printPoint( background_table[i][j],
							(i + vWorldOffset.x)%size_x,
							(j + vWorldOffset.y)%size_y);
			}
		}
	}
}
*/
