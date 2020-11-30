#ifndef shape_hpp
#define shape_hpp

#include <cmath>
#include <algorithm>

#include "V2d.hpp"
#include "Transform.hpp"
#include "Rect.hpp"


namespace iagw
{
    //  Forward declaration
    class Shape;

    // light-weight Node Structure
    struct Node
    {
        Shape   *parent;
        vi2d    pos;
    };


//===============================================================================
//  Generic virtual Shape class
//===============================================================================
    class Shape
    {
    public:
                        Shape();
                        Shape(uint8_t nodes);
                        Shape(uint8_t nodes, uint8_t b_col_in, uint8_t f_col_in);

        virtual void    drawYourself() const = 0;

        vi2d            returnPosition() { return arr_nodes[0].pos; }

        Recti           getLocalBounds() { return local_bounds; }
        //  !!!arr_nodes[0] might not be at (min(x), min(y))
        Recti           getGlobalBounds() { return (local_bounds + arr_nodes[0].pos); }

        const Transform& getTransform();

        //  !!!add setPosition function
        void            setPosition(const vi2d& new_pos) {}
        void            setColor(uint8_t b_col_in, uint8_t f_col_in);

        void            move(int32_t x, int32_t y);
        void            move(const vi2d& move_vec);

    protected:
        Node            *arr_nodes;
        vi2d            origin;
        uint32_t        n_nodes;
        uint8_t         color;

        Recti           local_bounds;
        Transform       m_transform;

        bool            transf_need_update;

    protected:
        //  Generates localBound Rect. Not called in virtual Shape class,
        //  needs to be called by derived class at construction, after arr_nodes is populated
        void            setLocalBounds();

        //  Update transformation matrix
        void            updateTransform();
    };

}


#endif //shape_hpp
