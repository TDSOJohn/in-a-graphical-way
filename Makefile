.PHONY : all

library	= make/libiagw.a

objects = a.out

all : $(library) $(objects)

make/libiagw.a :
	$(MAKE) -C make/

a.out : $(library) examples/shape_rotation.cpp
	cd make && g++ --std=c++11 ../examples/shape_rotation.cpp -L. -liagw -lncurses

.PHONY: $(library)

clean:
	$(MAKE) -C make/ clean
	-rm a.out
