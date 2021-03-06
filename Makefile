.PHONY : all

library	= make/libiagw.a

objects = a.out

all : $(library) $(objects)

make/libiagw.a :
	$(MAKE) -C make/

a.out : $(library) examples/png_try.cpp
	cd make && g++ --std=c++11 ../examples/shape_rotation.cpp -L. -liagw -lpng -lncurses

.PHONY: $(library)

clean:
	$(MAKE) -C make/ clean
	-rm make/a.out
