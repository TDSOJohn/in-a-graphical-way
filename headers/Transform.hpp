#ifndef transform_hpp
#define transform_hpp

#include "V2d.hpp"


namespace iagw
{
//===============================================================================
//  Generic 3x3 transformation matrix (2D) class
//===============================================================================
    class Transform
    {
    public:
        Transform();

        Transform(  float f00, float f10, float f20,
                    float f01, float f11, float f21,
                    float f02, float f12, float f22);

        Transform(float val);

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

        const float*                    getMatrix() const { return table; }

    private:
        float table[9];
    };
}

#endif //transform_hpp
