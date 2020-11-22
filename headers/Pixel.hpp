#ifndef point_hpp
#define point_hpp

#include <cmath>


namespace iagw
{
//===============================================================================
//  Simple Point entity class with 0-7 color coordinate and char to be printed
//===============================================================================
    struct Pixel
    {
        //  Foreground and Background colors pair (0, ..., max_pairs)
        uint8_t color;
        char    ch;
        bool    alpha;

        Pixel():
            color(0), ch(' '), alpha(false)
        {}

        Pixel(const Pixel& p_in):
            color(p_in.color), ch(p_in.ch), alpha(p_in.alpha)
        {}

        Pixel(uint8_t col_in, char ch_in = ' ', bool a_in = false):
            ch(ch_in%256), alpha(a_in)
		{
            if((col_in >= 0) && (col_in <= 62))
                color = col_in;
            else
                color = 0;
        }


        Pixel&  operator = (const Pixel& v) = default;

        bool    operator ==(const Pixel& p) const
        {	return ((color == p.color) && (ch == p.ch));	}

        bool    operator !=(const Pixel& p) const
        {	return ((color != p.color) || (ch != p.ch));	}

        //  does not make any sense
        Pixel   operator + (const Pixel& p)
        { return Pixel(this->color + p.color, this->ch); }

        //  does not make any sense
        Pixel   operator - (const Pixel& p)
        { return Pixel(this->color - p.color, this->ch); }
    };
}

#endif //point_hpp
