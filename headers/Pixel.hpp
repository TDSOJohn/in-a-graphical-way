#ifndef point_hpp
#define point_hpp

#include <cmath>


namespace iagw
{
//////////////////////////////////////////////////////////////////////////////////
///  Simple Point entity class with 0-7 color coordinate and char to be printed
//////////////////////////////////////////////////////////////////////////////////
    struct Pixel
    {
        /// Foreground and Background colors pair (0, ..., max_pairs)
        uint8_t color;
        ///  char to print in the Pixel
        char    ch;

        /// Default constructor has: color_pair 0 (default terminal color_pair) and space ch
        Pixel():
            color(0), ch(' ')
        {}

        /// copy constructor copies color and ch
        Pixel(const Pixel& p_in):
            color(p_in.color), ch(p_in.ch)
        {}

        /// pass separate 0, ..., 7 background and foreground color coordinates, char in
        Pixel(uint8_t b_col_in, uint8_t f_col_in, char ch_in = ' '):
            ch(ch_in%256)
		{
            uint8_t temp_color = (b_col_in * f_col_in) + f_col_in;
            if((temp_color >= 0) && (temp_color <= 62))
                color = temp_color;
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
