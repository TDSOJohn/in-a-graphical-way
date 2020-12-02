#include <iostream>
#include <curses.h>
#include <thread>
#include <chrono>
#include <algorithm>

#include "../headers/Screen.hpp"
#include "../headers/Rectangle.hpp"

// Works with classes which implement getGlobalBounds()
template <class T>
void checkCollisions(T shape_in[], int arr_size, iagw::vi2d move_vec[], const iagw::vi2d& screenSize)
{
	iagw::vi2d vec_temp;
	for(int i = 0; i < arr_size; i++)
	{
		//	Check for collisions between Textures and borders
		if(shape_in[i].returnPosition().x > (screenSize.x - shape_in[i].getLocalBounds().width - 1))
			move_vec[i].x = (std::abs(move_vec[i].x) * -1);
		if(shape_in[i].returnPosition().x < 0)
			move_vec[i].x = std::abs(move_vec[i].x);
		if(shape_in[i].returnPosition().y > (screenSize.y - shape_in[i].getLocalBounds().height - 1))
			move_vec[i].y = (std::abs(move_vec[i].y) * -1);
		if(shape_in[i].returnPosition().y < 0)
			move_vec[i].y = std::abs(move_vec[i].y);
		//	Check for collisions between Textures
		for(int j = i; j < arr_size; j++)
		{
			if((j != i) && shape_in[i].getGlobalBounds().intersects(shape_in[j].getGlobalBounds()))
			{
				vec_temp = move_vec[j];
				move_vec[j] = move_vec[i];
				move_vec[i] = vec_temp;
			}
		}
	}
}


int main()
{
	srand(time(NULL));

	int mtime_per_frame = 50;

	//	Create new screen and return size as 2d vector
	iagw::Screen scrn;
	iagw::vi2d screenSize = scrn.returnSize();

	iagw::vi2d vec_temp;

	//	create 5 cg::Rectangle shapes
	iagw::Rectangle rects[5];
	iagw::vi2d rectMove[5]= {{1,1},{2,1},{-1,-1},{2,-1},{-2,1}};

	for(int i = 0; i < 5; i++)
	{
		rects[i].move(i * 22, i * 11);
	}
	//	endless loop, quit with < ctrl + c >
	while(true)
	{
		checkCollisions<iagw::Rectangle>(rects, 5, rectMove, screenSize);
		//	Draw every rectangle
		for(int i = 0; i < 5; i++)
		{
			rects[i].move(rectMove[i]);
			rects[i].drawYourself();
		}
		//	Show the updated frame
		scrn.show();
		//	Wait some time before next frame
		std::this_thread::sleep_for(std::chrono::milliseconds(mtime_per_frame));
		scrn.clear();
	}

	//  Delete the screen and give back the usual CLI
	scrn.Screen::~Screen();
	return 0;
}
