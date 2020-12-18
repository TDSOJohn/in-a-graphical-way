#ifndef screen_hpp
#define screen_hpp

#include "V2d.hpp"
#include "Pixel.hpp"
#include "RenderTarget.hpp"


namespace iagw
{
//////////////////////////////////////////////////////////////////////////////////
///  Simple Screen class\n
///  Never call more than 1, it automatically starts a ncurses window\n
///  Never use std::cout and std::cin when using core_graphics\n
///  Rules concerning coordinates:\n
///  table[x][y]\n
///  Every function has (x, y) input\n
///  This hides the (y, x) way of handling coordinates by ncurses.h\n
//////////////////////////////////////////////////////////////////////////////////
    class Screen : public RenderTarget
    {
    public:
                    Screen();
                    Screen(int32_t x, int32_t y);
                    ~Screen();

        void        printCh(const Pixel& p, int32_t x, int32_t y);
        void        printCh(int32_t x, int32_t y, uint8_t b_col, uint8_t f_col, char ch = '.');

        void        show();
        void        clear();

        vi2d        returnSize() { return (vi2d(size_x, size_y)); }

    private:
        /// initialize screen, set up memory, cbreak, noecho, ...
        void        initScreen();
        /// start color mode, initialize color pairs
        void        initColors();

    private:
        bool        m_has_moved;
//        WINDOW*     m_window;
    };
}

#endif // screen_hpp
