
#include "../headers/Transform.hpp"

namespace iagw
{
    Transform::Transform():
                table  {1, 0, 0,
                        0, 1, 0,
                        0, 0, 1}
                {}

    Transform::Transform(
                float f00, float f10, float f20,
                float f01, float f11, float f21,
                float f02, float f12, float f22):
                table  {f00,f10,f20,
                        f01,f11,f21,
                        f02,f12,f22}
                {}

    Transform::Transform(float val):
                table   {val, val, val,
                         val, val, val,
                         val, val, val}
                {}

    Transform::Transform(const Transform& tr_in):
                table   {tr_in[0], tr_in[1], tr_in[2],
                         tr_in[3], tr_in[4], tr_in[5],
                         tr_in[6], tr_in[7], tr_in[8]}

                {}

    float Transform::det() const
    {
        if(table[1] == table[2] == 0)
            return (table[4]*table[8] - table[5]*table[7]);
        else
            return (table[0]*table[4]*table[8]+
                    table[1]*table[5]*table[6]+
                    table[2]*table[3]*table[7]-
                    table[2]*table[4]*table[6]-
                    table[0]*table[5]*table[7]-
                    table[1]*table[3]*table[8]);
    }

    Transform Transform::operator + (const Transform& rhs) const
    {
        return Transform(   table[0]+rhs[0], table[1]+rhs[1], table[2]+rhs[2],
                            table[3]+rhs[3], table[4]+rhs[4], table[5]+rhs[5],
                            table[6]+rhs[6], table[7]+rhs[7], table[8]+rhs[8]);
    }

    Transform Transform::operator - (const Transform& rhs) const
    {
        return Transform(   table[0]-rhs[0], table[1]-rhs[1], table[2]-rhs[2],
                            table[3]-rhs[3], table[4]-rhs[4], table[5]-rhs[5],
                            table[6]-rhs[6], table[7]-rhs[7], table[8]-rhs[8]);
    }

    const float& Transform::operator[](int i) const
    {
        if((i >= 0) && (i <= 8))
            return table[i];
        else
            return table[0];
    }

    Transform& Transform::combine(const Transform& rhs)
    {
        const float* a = table;
        const float* b = rhs.getMatrix();

        *this = Transform(  table[0]*rhs[0] + table[1]*rhs[3] + table[2]*rhs[6],
                            table[0]*rhs[1] + table[1]*rhs[4] + table[2]*rhs[7],
                            table[0]*rhs[2] + table[1]*rhs[5] + table[2]*rhs[8],
                            table[3]*rhs[0] + table[4]*rhs[3] + table[5]*rhs[6],
                            table[3]*rhs[1] + table[4]*rhs[4] + table[5]*rhs[7],
                            table[3]*rhs[2] + table[4]*rhs[5] + table[5]*rhs[8],
                            table[6]*rhs[0] + table[7]*rhs[3] + table[8]*rhs[6],
                            table[6]*rhs[1] + table[7]*rhs[4] + table[8]*rhs[7],
                            table[6]*rhs[2] + table[7]*rhs[5] + table[8]*rhs[8]);
        return *this;
    }


    //  lhs not usable inside a class or struct
    //  best way seems to be declaring external operator overloading as friend
    Transform operator *    (const Transform& lhs, const Transform& rhs)
    {
        return(Transform(lhs).combine(rhs));
    }

    vf2d operator *         (const Transform& lhs, const vf2d& rhs)
    {
        const float* a = lhs.getMatrix();

        return vf2d(rhs.x * a[4] + rhs.y * a[5],
                    rhs.x * a[7] + rhs.y * a[8]);
    }

    Transform& operator *=  (Transform& lhs, const Transform& rhs)
    {
        return lhs.combine(rhs);
    }

    bool operator ==        (const Transform& lhs, const Transform& rhs)
    {
        const float* a = lhs.getMatrix();
        const float* b = rhs.getMatrix();

        return( (a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]) &&
                (a[3] == b[3]) && (a[4] == b[4]) && (a[5] == b[5]) &&
                (a[6] == b[6]) && (a[7] == b[7]) && (a[8] == b[8]));
    }
}
