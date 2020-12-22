#ifndef transform_hpp
#define transform_hpp

#include "V2d.hpp"
#include "Rect.hpp"


namespace iagw
{
//////////////////////////////////////////////////////////////////////////////////
///  Generic 3x3 transformation matrix (2D) class
//////////////////////////////////////////////////////////////////////////////////
    class Transform
    {
    public:
        /// initializes identity matrix
        Transform();
        /// pass 9 floats
        Transform(  float f00, float f10, float f20,
                    float f01, float f11, float f21,
                    float f02, float f12, float f22);
        /// a single value is copied to every entry of the transform
        Transform(float val);
        /// the transform tr_in is copied in (this)
        Transform(const Transform& tr_in);

        Transform&                      operator = (const Transform& t) = default;

        float                           det() const;

        Transform                       operator + (const Transform& rhs) const;
        Transform                       operator + (const vf2d& rhs) const;

        Transform                       operator - (const Transform& rhs) const;
        Transform                       operator - (const vf2d& rhs) const;

        friend Transform                operator * (const Transform& lhs, const Transform& rhs);
        friend vf2d                     operator * (const Transform& lhs, const vf2d& rhs);

        friend Transform&               operator *= (Transform& lhs, const Transform& rhs);

        friend bool operator ==         (const Transform& lhs, const Transform& rhs);

        const float                     &operator[](int i) const;

        Transform&                      combine(const Transform& rhs);

        Transform&                      translate(float x, float y);
        Transform&                      translate(const vf2d& offset);

        Transform&                      rotate(float angle, float centerX, float centerY);
        Transform&                      rotate(float angle, const vf2d& center);

        vf2d                            transformPoint(float x, float y) const;
        vf2d                            transformPoint(const vf2d& v_in) const;

        Rectf                           transformRect(const Rectf& rect_in) const;

        const float*                    getMatrix() const { return table; }

    private:
        float table[9];
    };
}

#endif //transform_hpp
