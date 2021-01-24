A simple abstraction layer for ncurses

Includes 2D vectors, 3x3 transformation matrixes as utilities (implementations are inspired by OneLoneCoder's PixelGameEengine and SFML source codes)

Includes Rectangle and Texture classes (Texture loads any .txt ASCII art), derived from virtual Shape class

Create static library with makefile, compile your project using

	g++ --std=c++11 your_file.cpp -L. -liagw -lncurses


Dependencies:
	libpng (see http://www.libpng.org/pub/png/libpng.html ), used to import .png images from file (used in Texture.cpp)

Known errors:

- Event is not working yet. Using it will cause your program to crash!
- Some glitches are happening when rotating lines


Yes, I love Tony Williams

Yes, I love In a Silent Way
