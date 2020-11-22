#ifndef screen_hpp
#define screen_hpp

#include <ncurses.h>

#include "V2d.hpp"
#include "Pixel.hpp"


//  Rules concerning coordinates:
//  table[x][y]
//  Every function has (x, y) input
//  This hides the (y, x) way of handling coordinates by ncurses.h

namespace iagw
{
//===============================================================================
//  Simple Screen class
//  Never call more than 1, it automatically starts a ncurses window
//  Never use std::cout and std::cin when using core_graphics
//===============================================================================
    class Screen
    {
    public:
                    Screen();
                    ~Screen();

//        void        printCh(const Pixel& p, int32_t x, int32_t y);
        void        printCh(int32_t x, int32_t y, uint8_t cs = 0, char ch = '.');

        vi2d        returnSize() { return (vi2d(size_x, size_y)); }

        void        show();
        void        clear();

    private:
        void        initScreen();
        void        initColors();

    private:
        uint32_t    size_x,
                    size_y;

        bool        m_has_moved;
        bool        m_has_colors;
    };
}

#endif // screen_hpp
