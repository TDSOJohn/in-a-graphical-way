#include <fstream>

#include "../headers/cg_drawables.hpp"


namespace cg
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
		hasMoved = TRUE;

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
		hasMoved = TRUE;

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


//=====================================
//	Texture class
//=====================================
	Texture::Texture(): Shape::Shape()
	{}

	Texture::Texture(int32_t x, int32_t y, const std::string& file_name): Shape::Shape()
	{
		loadFromFile(file_name);
		move(x, y);
	}

	Texture::Texture(const std::string& file_name): Shape::Shape()
	{ loadFromFile(file_name); }

	void  	Texture::loadFromFile(const std::string& file_name)
	{
		std::ifstream file_in;
		file_in.open(file_name, std::ios::in);

		//	first scan to get row_len e col_len
		std::string line;
		int32_t row_len = 0;
		int32_t col_len = 0;
		if(file_in.is_open())
		{
			while(std::getline(file_in, line))
			{
				col_len++;
				if(line.size() > row_len)
					row_len = line.size();
			}
		}
		text_table = new char*[col_len];

		//  eof flag is set, to seekg alone won't work
		file_in.clear();
		file_in.seekg(0);
		for(int i = 0; i < col_len; i++)
	    {
	        text_table[i] = new char[row_len + 1];
	        file_in.getline(text_table[i], row_len + 1);
	        for(int j = 0; j < row_len; j++)
	        {
	            if(text_table[i][j] == 0)
	                text_table[i][j] = ' ';
	        }
	    }
		arrNodes[0] = {this, vi2d{0,0}};
		arrNodes[1] = {this, vi2d{row_len,0}};
		arrNodes[2] = {this, vi2d{row_len,col_len}};
		arrNodes[3] = {this, vi2d{0,col_len}};
		setLocalBounds();
	}

	void 	Texture::drawYourself() const
	{
		for(int i = 0; i < (arrNodes[2].pos.x - arrNodes[0].pos.x); i++)
		{
			for(int j = 0; j < (arrNodes[2].pos.y - arrNodes[0].pos.y); j++)
			{
				mvaddch(j + arrNodes[0].pos.y,
						i + arrNodes[0].pos.x,
						text_table[j][i]);
			}
		}
	}

	Texture::~Texture()
	{
		delete text_table;
	}
}
