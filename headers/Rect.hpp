#ifndef rect_hpp
#define rect_hpp

#include <cmath>


namespace iagw
{
//===============================================================================
//  Rectangle Structure, useful for bounding rectangles
//===============================================================================
    template <class T>
    struct Rect
    {
        T x = 0;
        T y = 0;
        T width, height;
        
        Rect(): x(0), y(0), width(0), height(0) {}
        Rect(T x_in, T y_in, T w_in, T h_in):   x(x_in),
                                                y(y_in),
                                                width(w_in),
                                                height(h_in) {}

        Rect(const Rect& rect_in):           x(rect_in.x),
                                                y(rect_in.y),
                                                width(rect_in.width),
                                                height(rect_in.height) {}
        template <class U>
        Rect(const Rect<U>& rect_in):   x(static_cast<T>(rect_in.x)),
                                        y(static_cast<T>(rect_in.y)),
                                        width(static_cast<T>(rect_in.width)),
                                        height(static_cast<T>(rect_in.height)) {}

        Rect& operator= (const Rect& rect) = default;

        template <class U>
        Rect operator + (const v2d_generic<U>& rhs) const { return Rect(this->x + static_cast<T>(rhs.x),
                                                            this->y + static_cast<T>(rhs.y), this->width, this->height); }
        Rect& operator+=(const Rect& rhs) { this->x += rhs.width; this->y += rhs.height; return *this; }

        bool intersects(const Rect& rect_in) {
            if((((rect_in.width + this->width) * 0.5) >=
                std::abs((rect_in.x + (0.5 * rect_in.width)) - (this->x + float(0.5 * this->width))))
                && (((rect_in.height + this->height) * 0.5) >=
                std::abs(((rect_in.y + (0.5 * rect_in.height)) - (this->y + (0.5 * this->height))))))
                return true;
            else
                return false;
        }
    };

    typedef Rect<int32_t>       Recti;
    typedef Rect<uint32_t>      Rectu;
    typedef Rect<float>         Rectf;
}

#endif //rect_hpp
