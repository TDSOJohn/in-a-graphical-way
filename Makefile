CC      	:= gcc
CXX     	:= g++
CPPFLAGS	:= --std=c++2a
LDLIBS		:= -lncurses -pthread


objects 	= rendertarget.o screen.o shape.o rectangle.o texture.o transform.o vertexarray.o

iagw_core	= 	headers/V2d.hpp headers/Rect.hpp headers/Pixel.hpp headers/Transform.hpp sources/Transform.cpp headers/RenderTarget.hpp sources/RenderTarget.cpp


libcg: $(objects)
	ar rcs libiagw.a $(objects)

rendertarget.o: $(iagw_core)
	g++ $(CPPFLAGS) -c sources/RenderTarget.cpp

screen.o: $(iagw_core) headers/Screen.hpp sources/Screen.cpp
	g++ $(CPPFLAGS) -c sources/Screen.cpp

transform.o: headers/V2d.hpp headers/Transform.hpp sources/Transform.cpp
	g++ $(CPPFLAGS) -c sources/Transform.cpp

shape.o: $(iagw_core) headers/Transform.hpp sources/Transform.cpp headers/Shape.hpp sources/Shape.cpp
	g++ $(CPPFLAGS) -c sources/Shape.cpp

texture.o: $(iagw_core) headers/Shape.hpp sources/Shape.cpp headers/Texture.hpp sources/Texture.cpp
	g++ $(CPPFLAGS) -c sources/Texture.cpp

rectangle.o: $(iagw_core) headers/Shape.hpp sources/Shape.cpp headers/Rectangle.hpp sources/Rectangle.cpp
	g++ $(CPPFLAGS) -c sources/Rectangle.cpp

vertexarray.o: $(aigw_core) headers/Shape.hpp sources/Shape.cpp headers/VertexArray.hpp sources/VertexArray.cpp
	g++ $(CPPFLAGS) -c sources/VertexArray.cpp

event.o: $(iagw_core) headers/Event.hpp sources/Event.cpp
	g++ $(CPPFLAGS) -c sources/Event.cpp

clean:
	rm $(objects)
