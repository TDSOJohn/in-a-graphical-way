#ifndef matrix_hpp
#define matrix_hpp

#include "V2d.hpp"


namespace cg
{
    template <class T>
    class transf_generic
    {
    public:
        transf_generic();
        transf_generic( T f00, T f10, T f20,
                        T f01, T f11, T f21,
                        T f02, T f12, T f22): table{f00,f10,f20,
                                                    f01,f11,f21,
                                                    f02,f12,f22}
                        {}

        transf_generic(T val)
        {
            for(int i = 0; i < 9; i++)
                table[i] = val;
        }

        transf_generic(const transf_generic& tr_in)
        {
            for(int i = 0; i < 9; i++)
                table[i] = static_cast<T>(tr_in[i]);
        }

        transf_generic& operator=   (const transf_generic& t) = default;

        T det()                     const
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

        transf_generic operator +   (const transf_generic& rhs) const {
            return transf_generic(  table[0]+rhs[0], table[1]+rhs[1], table[2]+rhs[2],
                                    table[3]+rhs[3], table[4]+rhs[4], table[5]+rhs[5],
                                    table[6]+rhs[6], table[7]+rhs[7], table[8]+rhs[8]);
            }

        transf_generic operator -   (const transf_generic& rhs) const {
            return transf_generic(  table[0]-rhs[0], table[1]-rhs[1], table[2]-rhs[2],
                                    table[3]-rhs[3], table[4]-rhs[4], table[5]-rhs[5],
                                    table[6]-rhs[6], table[7]-rhs[7], table[8]-rhs[8]);
            }

        transf_generic operator *   (const transf_generic& rhs) const {
            return transf_generic(  table[0]*rhs[0] + table[1]*rhs[3] + table[2]*rhs[6],
                                    table[0]*rhs[1] + table[1]*rhs[4] + table[2]*rhs[7],
                                    table[0]*rhs[2] + table[1]*rhs[5] + table[2]*rhs[8],
                                    table[3]*rhs[0] + table[4]*rhs[3] + table[5]*rhs[6],
                                    table[3]*rhs[1] + table[4]*rhs[4] + table[5]*rhs[7],
                                    table[3]*rhs[2] + table[4]*rhs[5] + table[5]*rhs[8],
                                    table[6]*rhs[0] + table[7]*rhs[3] + table[8]*rhs[6],
                                    table[6]*rhs[1] + table[7]*rhs[4] + table[8]*rhs[7],
                                    table[6]*rhs[2] + table[7]*rhs[5] + table[8]*rhs[8]);
            }

        vf2d operator *             (const vf2d& rhs) const {
            return vf2d(rhs.x * table[4] + rhs.y * table[5],
                        rhs.x * table[7] + rhs.y * table[8]);
        }

        const T &operator[](int i) const
        {
            if((i >= 0) && (i <= 8))
                return table[i];
            else
                return table[0];
        }

        const T* getMtrix() const { return table; }

    private:
        T table[9];
    };

    typedef transf_generic<uint32_t>    uMatrix;
    typedef transf_generic<int32_t>     iMatrix;
    typedef transf_generic<float>       fMatrix;
}

#endif //matrix_hpp
