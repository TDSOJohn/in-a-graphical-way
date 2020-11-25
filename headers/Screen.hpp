#ifndef screen_hpp
#define screen_hpp

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

        void        show();
        void        clear();

        vi2d        returnSize() { return (vi2d(size_x, size_y)); }

    private:
        //  initialize screen, set up memory, cbreak, noecho, ...
        void        initScreen();
        //  start color mode, initialize color pairs
        void        initColors();

    private:
        uint32_t    size_x,
                    size_y;

        bool        m_has_moved;
        bool        m_has_colors;
    };
}

#endif // screen_hpp
