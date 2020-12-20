#include <fstream>

#include <curses.h>
#include "../bitmap/bitmap_image.hpp"

#include "../headers/Texture.hpp"


namespace iagw
{
	Texture::Texture(const Texture& text_in)
	{

	}

	Texture::Texture(const std::string& file_name)
	{
		loadFromFile(file_name);
	}

	void  	Texture::loadFromFile(const std::string& file_name)
	{

	}

	Texture::~Texture()
	{
		delete text_table;
	}
}

/*
void 	Texture::drawYourself()
{
	for(int i = 0; i < (arr_nodes[2].pos.x - arr_nodes[0].pos.x); i++)
	{
		for(int j = 0; j < (arr_nodes[2].pos.y - arr_nodes[0].pos.y); j++)
		{
			mvaddch(j + m_position.y,
					i + m_position.x,
					text_table[j][i]);
		}
	}
}


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
size = { row_len, col_len };
*/
