#ifndef screen_hpp
#define screen_hpp

#include <ncurses.h>

#include "V2d.hpp"
#include "Point.hpp"


//  Rules concerning coordinates:
//  table[x][y]
//  Every function has (x, y) input
//  This hides the (y, x) way of handling coordinates by ncurses.h

namespace cg
{
//===============================================================================
//  Simple Screen class
//  Never call more than 1, it automatically starts a lncurses window
//  Never use std::cout and std::cin when using core_graphics
//===============================================================================
    class Screen
    {
    public:
                    Screen();
                    ~Screen();

        void        printCh(const Point& p, int32_t x, int32_t y);
        void        printCh(int32_t x, int32_t y, uint8_t cs = 7, char ch = '.');

        vi2d        returnSize() { return (vi2d(size_x, size_y)); }

        void        show();
        void        clear();

    private:
        void        initScreen();

    private:
        uint32_t    size_x,
                    size_y;

        bool        has_moved;
    };
}

#endif // screen_hpp
