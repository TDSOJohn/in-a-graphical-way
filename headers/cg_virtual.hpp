#ifndef cg_virtual_hpp
#define cg_virtual_hpp

#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <curses.h>


namespace cg
{
//===============================================================================
//  Generic 2d vector class
//===============================================================================
    template <class T>
    struct v2d_generic
    {
        T x = 0;
        T y = 0;
        v2d_generic(): x(0), y(0) {}
        v2d_generic(T _x, T _y): x(_x), y(_y) {}
        v2d_generic(const T& v): x(v.x), y(v.y) {}
        template <class U>
        v2d_generic(U _x, U _y): x(static_cast<T>(_x)), y(static_cast<T>(_y)) {}

        v2d_generic& operator=  (const v2d_generic& v) = default;
        T mag()                 const { return T(std::sqrt(x * x + y * y)); }
        v2d_generic norm()      const {  T r = 1 / mag(); return v2d_generic(x*r, y*r); }
        v2d_generic operator +  (const v2d_generic& rhs) const { return v2d_generic(this->x + rhs.x, this->y + rhs.y); }
        v2d_generic operator -  (const v2d_generic& rhs) const { return v2d_generic(this->x - rhs.x, this->y - rhs.y); }
        v2d_generic operator *  (const T& rhs) const { return v2d_generic(this->x * rhs, this->y * rhs); }
        v2d_generic operator *  (const v2d_generic& rhs) const { return v2d_generic(this->x * rhs.x, this->y * rhs.y); }
        v2d_generic operator /  (const T& rhs) const { return v2d_generic(this->x / rhs, this->y / rhs); }
        v2d_generic operator /  (const v2d_generic& rhs) const { return v2d_generic(this->x / rhs.x, this->y / rhs.y); }
        v2d_generic& operator +=(const v2d_generic& rhs) { this->x += rhs.x; this->y += rhs.y; return *this; }
		v2d_generic& operator -=(const v2d_generic& rhs) { this->x -= rhs.x; this->y -= rhs.y; return *this; }
		v2d_generic& operator *=(const T& rhs) { this->x *= rhs; this->y *= rhs; return *this; }
		v2d_generic& operator /=(const T& rhs) { this->x /= rhs; this->y /= rhs; return *this; }
		v2d_generic operator +  () const { return { +x, +y }; }
		v2d_generic operator -  () const { return { -x, -y }; }
		bool operator ==        (const v2d_generic& rhs) const { return (this->x == rhs.x && this->y == rhs.y); }
		bool operator !=        (const v2d_generic& rhs) const { return (this->x != rhs.x || this->y != rhs.y); }
		const std::string str() const { return std::string("(") + std::to_string(this->x) + "," + std::to_string(this->y) + ")"; }
    };

    typedef v2d_generic<int32_t>    vi2d;
    typedef v2d_generic<uint32_t>   vu2d;
    typedef v2d_generic<float>      vf2d;

    //  Forward declaration
    struct Shape;

    // light-weight Node Structure
    struct Node
    {
        Shape   *parent;
        vi2d    pos;
    };


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
                return TRUE;
            else
                return FALSE;
        }
    };

    typedef Rect<int32_t>       Recti;
    typedef Rect<uint32_t>      Rectu;
    typedef Rect<float>         Rectf;


//===============================================================================
//  Generic virtual Shape struct
//===============================================================================
    struct Shape
    {
        Node            *arrNodes;
        vf2d            center;
        uint32_t        nNodes = 0;
        uint8_t         color = 7;

        Recti           localBounds;

        //  static share of world transformation
        static float    fWorldScale;
        static vi2d     vWorldOffset;
        bool            hasMoved;

                        Shape();
                        Shape(uint8_t nodes);

        virtual void    drawYourself() const = 0;
        void            worldToScreen();

        vi2d            returnPosition() { return arrNodes[0].pos; }
        Recti           getLocalBounds() { return localBounds; }
        Recti           getGlobalBounds() { return (localBounds + arrNodes[0].pos); }

        void            setPosition(const vi2d& new_pos) {}
        void            move(int32_t x, int32_t y);

        void            move(const vi2d& moveVec);

    protected:
        //  Generates localBound Rect. Not called in virtual Shape class,
        //  needs to be called by derived class at construction, after arrNodes is populated
        void            setLocalBounds();
    };

}


#endif //cg_virtual_hpp
