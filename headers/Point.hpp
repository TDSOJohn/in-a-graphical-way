#ifndef point_hpp
#define point_hpp

#include <cmath>


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

        bool    operator ==(const Point& p) const
        {	return ((color == p.color) && (ch == p.ch));	}

        bool    operator !=(const Point& p) const
        {	return ((color != p.color) || (ch != p.ch));	}

        Point   operator + (const Point& p) { return Point(this->color + p.color, this->ch); }

        Point   operator - (const Point& p) { return Point(this->color - p.color, this->ch); }
    };
}

#endif //point_hpp
