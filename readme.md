A simple abstraction layer for ncurses

Includes 2D vectors, 3x3 transformation matrixes as utilities (implementations are inspired by OneLoneCoder's PixelGameEengine and SFML source codes)

Includes Rectangle and Texture classes (Texture loads any .txt ASCII art), derived from virtual Shape class

Create static library with makefile, compile your project using

	g++ --std=c++11 your_file.cpp -L. -lcg -lncurses


Known errors:

- Event is not working yet. Using it will cause your program to crash!
- Matrix is incomplete => transformation matrixes are not currently implemented


Yes, I love Tony Williams
Yes, I love In a Silent Way
