#include <fstream>

#include <stdlib.h>
#include <png.h>
#include <curses.h>

#include "../headers/Texture.hpp"


namespace iagw
{
	Texture::Texture(const std::string& file_name)
	{
		loadFromFile(file_name);
	}

	//	giving a file_name to non-existing file gives a beautiful Segmentation Fault
	void  	Texture::loadFromFile(const std::string& file_name)
	{
		//	convert std::string file_name to char* C-style string
		const char *c_file_name = file_name.c_str();

		int width, height;
		png_byte color_type;
		png_byte bit_depth;

		png_structp png_ptr;
		png_infop info_ptr;
		int number_of_passes;
		png_bytep *row_pointers;

		unsigned char header[8];

		bool has_alpha = false;

		FILE *fp = fopen(c_file_name, "rb");
		if(fp == NULL)
		{
			printw("File %s could not be found!\n", c_file_name);
			return;
		}

		fread(header, 1, 8, fp);

		if(png_sig_cmp(header, 0, 8))
		{
			printw("File %s is not recognized!\n", c_file_name);
			return;
		}

		png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
		if(!png_ptr)
		{
			printw("png_create_read_struct failed!\n");
			return;
		}

		info_ptr = png_create_info_struct(png_ptr);
		if(!info_ptr)
		{
			printw("png_create_info_struct failed!\n");
			return;
		}

		if(setjmp(png_jmpbuf(png_ptr)))
		{
			printw("Error during init_io\n");
			return;
		}

		png_init_io(png_ptr, fp);
		png_set_sig_bytes(png_ptr, 8);

		png_read_info(png_ptr, info_ptr);

		width 		= png_get_image_width(png_ptr, info_ptr);
		height 		= png_get_image_height(png_ptr, info_ptr);
		color_type 	= png_get_color_type(png_ptr, info_ptr);
		bit_depth 	= png_get_bit_depth(png_ptr, info_ptr);

		number_of_passes = png_set_interlace_handling(png_ptr);
		png_read_update_info(png_ptr, info_ptr);

		if(setjmp(png_jmpbuf(png_ptr)))
		{
			printw("Error reading file %s\n", c_file_name);
			return;
		}

		data_table = (png_bytep*) malloc(sizeof(png_bytep) * height);
		for(int y = 0; y < height; y++)
			data_table[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr, info_ptr));

		png_read_image(png_ptr, data_table);

		fclose(fp);

		printw("the file is: %d by %d\n", width, height);

		if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGB)
			printw("input file is RGB\n\n");
		else if(png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_RGBA)
		{
			printw("input file is RGBA\n\n");
			has_alpha = true;
		}

		short pixel_size = (4 * has_alpha) + (3 * !has_alpha);

		for(int y = 0; y < height; y++)
		{
			png_byte *row = data_table[y];
			for(int x = 0; x < width; x++)
			{
				png_byte* ptr = &(row[x*pixel_size]);
				printw("pixel %d, %d is %d, %d, %d, %d\t", x, y, ptr[0],
																 ptr[1],
																 ptr[2],
																 ptr[3]);
			}
			printw("\n");
		}
	}

	Texture::~Texture()
	{
		delete data_table;
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
