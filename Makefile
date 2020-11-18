CC      	:= gcc
CXX     	:= g++
CPPFLAGS	:= --std=c++2a
LDLIBS		:= -lncurses -pthread


objects 	= core_graphics.o cg_virtual.o cg_drawables.o cg_event.o
cg_core_src = sources/core_graphics.cpp sources/cg_virtual.cpp
cg_core_head= headers/core_graphics.hpp headers/cg_virtual.hpp
cg_sources	= sources/core_graphics.cpp sources/cg_virtual.cpp sources/cg_drawables.cpp sources/cg_event.cpp
cg_headers 	= headers/core_graphics.hpp headers/cg_virtual.hpp headers/cg_matrix.hpp headers/cg_drawables.hpp headers/cg_event.hpp


libcg: $(objects)
	ar rcs libcg.a $(objects)

cg_virtual.o: headers/cg_virtual.hpp sources/cg_virtual.cpp
	g++ $(CPPFLAGS) -c sources/cg_virtual.cpp

core_graphics.o: $(cg_core_src) $(cg_core_head)
	g++ $(CPPFLAGS) -c sources/core_graphics.cpp

cg_drawables.o: $(cg_core_src) $(cg_core_head)
	g++ $(CPPFLAGS) -c sources/cg_drawables.cpp

cg_event.o: $(cg_core_src) $(cg_core_head) headers/cg_event.hpp sources/cg_event.cpp
	g++ $(CPPFLAGS) -c sources/cg_event.cpp

clean:
	rm $(objects)
