#include <curses.h>

#include "../headers/Rectangle.hpp"


namespace iagw
{
//=====================================
//	Rectangle class
//=====================================
	Rectangle::Rectangle(): Shape()
	{
		//	find better way to initialize
		arr_nodes[0] = {this, {0,0}};
		arr_nodes[1] = {this, {20,0}};
		arr_nodes[2] = {this, {20,10}};
		arr_nodes[3] = {this, {0,10}};
		transf_need_update = true;

		setLocalBounds();
	}

	Rectangle::Rectangle(float x1, float y1, float x2, float y2): Shape()
	{
		//	find better way to initialize
		arr_nodes[0] = {this, {x1,y1}};
		arr_nodes[1] = {this, {x2,y1}};
		arr_nodes[2] = {this, {x2,y2}};
		arr_nodes[3] = {this, {x1,y2}};
		transf_need_update = true;

		setLocalBounds();
	}

	void Rectangle::drawYourself() const
	{
		mvhline(arr_nodes[0].pos.y, arr_nodes[0].pos.x, 0, arr_nodes[2].pos.x - arr_nodes[0].pos.x);
		mvhline(arr_nodes[2].pos.y, arr_nodes[0].pos.x, 0, arr_nodes[2].pos.x - arr_nodes[0].pos.x);
		mvvline(arr_nodes[0].pos.y, arr_nodes[0].pos.x, 0, arr_nodes[2].pos.y - arr_nodes[0].pos.y);
		mvvline(arr_nodes[0].pos.y, arr_nodes[2].pos.x, 0, arr_nodes[2].pos.y - arr_nodes[0].pos.y);
		mvaddch(arr_nodes[0].pos.y, arr_nodes[0].pos.x, ACS_ULCORNER);
		mvaddch(arr_nodes[2].pos.y, arr_nodes[0].pos.x, ACS_LLCORNER);
		mvaddch(arr_nodes[0].pos.y, arr_nodes[2].pos.x, ACS_URCORNER);
		mvaddch(arr_nodes[2].pos.y, arr_nodes[2].pos.x, ACS_LRCORNER);
	}
}
