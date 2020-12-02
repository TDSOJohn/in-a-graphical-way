CC      	:= gcc
CXX     	:= g++
CPPFLAGS	:= --std=c++2a
LDLIBS		:= -lncurses -pthread


objects 	= RenderTarget.o Screen.o Shape.o Rectangle.o Texture.o Transform.o VertexArray.o

iagw_core	= 	headers/V2d.hpp headers/Rect.hpp headers/Pixel.hpp headers/Transform.hpp sources/Transform.cpp headers/RenderTarget.hpp sources/RenderTarget.cpp


libcg: $(objects)
	ar rcs libiagw.a $(objects)

RenderTarget.o: $(iagw_core)
	g++ $(CPPFLAGS) -c sources/RenderTarget.cpp

Screen.o: $(iagw_core) headers/Screen.hpp sources/Screen.cpp
	g++ $(CPPFLAGS) -c sources/Screen.cpp

Transform.o: headers/V2d.hpp headers/Transform.hpp sources/Transform.cpp
	g++ $(CPPFLAGS) -c sources/Transform.cpp

Shape.o: $(iagw_core) headers/Transform.hpp sources/Transform.cpp headers/Shape.hpp sources/Shape.cpp
	g++ $(CPPFLAGS) -c sources/Shape.cpp

Texture.o: $(iagw_core) headers/Shape.hpp sources/Shape.cpp headers/Texture.hpp sources/Texture.cpp
	g++ $(CPPFLAGS) -c sources/Texture.cpp

Rectangle.o: $(iagw_core) headers/Shape.hpp sources/Shape.cpp headers/Rectangle.hpp sources/Rectangle.cpp
	g++ $(CPPFLAGS) -c sources/Rectangle.cpp

VertexArray.o: $(aigw_core) headers/Shape.hpp sources/Shape.cpp headers/VertexArray.hpp sources/VertexArray.cpp
	g++ $(CPPFLAGS) -c sources/VertexArray.cpp

Event.o: $(iagw_core) headers/Event.hpp sources/Event.cpp
	g++ $(CPPFLAGS) -c sources/Event.cpp

clean:
	rm $(objects)
