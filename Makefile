CC      	:= gcc
CXX     	:= g++
CPPFLAGS	:= --std=c++2a
LDLIBS		:= -lncurses -pthread


objects 	= screen.o shape.o rectangle.o texture.o

iagw_core	= headers/V2d.hpp headers/Rect.hpp headers/Pixel.hpp headers/Matrix.hpp


libcg: $(objects)
	ar rcs libiagw.a $(objects)

screen.o: $(iagw_core) headers/Screen.hpp sources/Screen.cpp
	g++ $(CPPFLAGS) -c sources/Screen.cpp

shape.o: $(iagw_core) headers/Matrix.hpp headers/Shape.hpp sources/Shape.cpp
	g++ $(CPPFLAGS) -c sources/Shape.cpp

texture.o: $(iagw_core) headers/Shape.hpp sources/Shape.cpp headers/Texture.hpp sources/Texture.cpp
	g++ $(CPPFLAGS) -c sources/Texture.cpp

rectangle.o: $(iagw_core) headers/Shape.hpp sources/Shape.cpp headers/Rectangle.hpp sources/Rectangle.cpp
	g++ $(CPPFLAGS) -c sources/Rectangle.cpp

event.o: $(iagw_core) headers/Event.hpp sources/Event.cpp
	g++ $(CPPFLAGS) -c sources/Event.cpp

clean:
	rm $(objects)
