#include <curses.h>

#include "../headers/Rectangle.hpp"


namespace iagw
{
//=====================================
//	Rectangle class
//=====================================
	Rectangle::Rectangle()
	{
		nNodes = 4;
		arrNodes = new Node[4];
		//	find better way to initialize
		arrNodes[0] = {this, {0,0}};
		arrNodes[1] = {this, {20,0}};
		arrNodes[2] = {this, {20,10}};
		arrNodes[3] = {this, {0,10}};
		transfUpdateNeeded = true;

		setLocalBounds();
	}

	Rectangle::Rectangle(float x1, float y1, float x2, float y2)
	{
		nNodes = 4;
		arrNodes = new Node[4];
		//	find better way to initialize
		arrNodes[0] = {this, {x1,y1}};
		arrNodes[1] = {this, {x2,y1}};
		arrNodes[2] = {this, {x2,y2}};
		arrNodes[3] = {this, {x1,y2}};
		transfUpdateNeeded = true;

		setLocalBounds();
	}

	void Rectangle::drawYourself() const
	{
		mvhline(arrNodes[0].pos.y, arrNodes[0].pos.x, 0, arrNodes[2].pos.x - arrNodes[0].pos.x);
		mvhline(arrNodes[2].pos.y, arrNodes[0].pos.x, 0, arrNodes[2].pos.x - arrNodes[0].pos.x);
		mvvline(arrNodes[0].pos.y, arrNodes[0].pos.x, 0, arrNodes[2].pos.y - arrNodes[0].pos.y);
		mvvline(arrNodes[0].pos.y, arrNodes[2].pos.x, 0, arrNodes[2].pos.y - arrNodes[0].pos.y);
		mvaddch(arrNodes[0].pos.y, arrNodes[0].pos.x, ACS_ULCORNER);
		mvaddch(arrNodes[2].pos.y, arrNodes[0].pos.x, ACS_LLCORNER);
		mvaddch(arrNodes[0].pos.y, arrNodes[2].pos.x, ACS_URCORNER);
		mvaddch(arrNodes[2].pos.y, arrNodes[2].pos.x, ACS_LRCORNER);
	}
}
