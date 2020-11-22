#ifndef v2d_hpp
#define v2d_hpp

#include <cmath>
#include <string>


namespace iagw
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
}

#endif //v2d_hpp
