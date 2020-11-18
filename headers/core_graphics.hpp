#ifndef core_graphics_hpp
#define core_graphics_hpp

#include "cg_virtual.hpp"

//  Rules concerning coordinates:
//  table[x][y]
//  Every function has (x, y) input

namespace cg
{
//===============================================================================
//  Simple Point entity class with 0-7 color coordinate and char to be printed
//===============================================================================
    struct Point
    {
        uint8_t color;
        char    ch;

        Point() { color = 7; ch = ' '; }
        Point(uint8_t col_in, char ch_in): ch(ch_in%256)
    		{ color = std::max(uint8_t(0), std::min(uint8_t(7), col_in)); }

        Point&  operator = (const Point& v) = default;
        bool    operator ==(const Point& p) const;
        bool    operator !=(const Point& p) const;
        Point   operator + (const Point& p) { return Point(this->color + p.color, this->ch); }
        Point   operator - (const Point& p) { return Point(this->color - p.color, this->ch); }
    };

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

        void        move(vi2d move_vec);

        vi2d        returnSize() { return (vi2d(size_x, size_y)); }

        void        show();
        void        clear();

    private:
        void        initScreen();

    private:
        uint32_t    size_x,
                    size_y;

        //  static share of world transformation
        static float    fWorldScale;
        static vi2d     vWorldOffset;

        bool        has_moved;
    };
}

#endif // core_graphics_hpp
