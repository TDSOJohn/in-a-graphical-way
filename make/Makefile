CC      	:= gcc
CXX     	:= g++
CPPFLAGS	:= --std=c++2a
LDLIBS		:= -lncurses -pthread


objects 	= 	RenderTarget.o \
				Screen.o \
				Transformable.o \
				Texture.o \
				Transform.o \
				VertexArray.o \
				Sprite.o

iagw_core	= 	../headers/V2d.hpp \
				../headers/Rect.hpp \
				../headers/Transform.hpp ../sources/Transform.cpp \
				../headers/RenderTarget.hpp ../sources/RenderTarget.cpp \


libcg: $(objects)
	ar rcs libiagw.a $(objects)

RenderTarget.o: $(iagw_core) ../headers/RenderTarget.hpp ../sources/RenderTarget.cpp
	g++ $(CPPFLAGS) -c ../sources/RenderTarget.cpp

Screen.o: $(iagw_core) ../headers/Screen.hpp ../sources/Screen.cpp
	g++ $(CPPFLAGS) -c ../sources/Screen.cpp

Transform.o: 	../headers/V2d.hpp \
				../headers/Transform.hpp ../sources/Transform.cpp
	g++ $(CPPFLAGS) -c ../sources/Transform.cpp

Transformable.o: $(iagw_core) 	../headers/Transform.hpp ../sources/Transform.cpp \
								../headers/Transformable.hpp ../sources/Transformable.cpp
	g++ $(CPPFLAGS) -c ../sources/Transformable.cpp

Texture.o: $(iagw_core) ../headers/Texture.hpp ../sources/Texture.cpp
	g++ $(CPPFLAGS) -c ../sources/Texture.cpp

VertexArray.o: $(aigw_core) ../headers/Transformable.hpp ../sources/Transformable.cpp \
							../headers/Drawable.hpp \
							../headers/VertexArray.hpp ../sources/VertexArray.cpp
	g++ $(CPPFLAGS) -c ../sources/VertexArray.cpp

Event.o: $(iagw_core) ../headers/Event.hpp ../sources/Event.cpp
	g++ $(CPPFLAGS) -c ../sources/Event.cpp

Sprite.o: $(iagw_core) 	../headers/Transformable.hpp ../sources/Transformable.cpp \
						../headers/Drawable.hpp \
						../headers/Texture.hpp ../sources/Texture.cpp
	g++ $(CPPFLAGS) -c ../sources/Sprite.cpp


clean:
	-rm $(objects)
