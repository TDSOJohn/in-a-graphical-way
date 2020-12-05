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
        void            printData();

                        //  initializes a rectangle at (0,0)
                        Shape();
                        //  !!!all nodes are at (0,0)
                        Shape(uint8_t nodes);
                        Shape(uint8_t nodes, uint8_t b_col_in, uint8_t f_col_in);

        virtual void    drawYourself() = 0;

        void            setColor(uint8_t b_col_in, uint8_t f_col_in);

        //  !!!add setPosition function
        vi2d            getPosition() { return arr_nodes[0].pos; }
        void            setPosition(const vi2d& new_pos) {}

        Rectf           getLocalBounds() { return local_bounds; }
        //  !!!arr_nodes[0] might not be at (min(x), min(y))
        Rectf           getGlobalBounds() { return (local_bounds + arr_nodes[0].pos); }

        const Transform& getTransform();

        void            move(int32_t x, int32_t y);
        void            move(const vi2d& move_vec);

        void            rotate(float r);
        void            setRotation(float r);
        float           getRotation() const;

    protected:
        Node            *arr_nodes;
        uint32_t        m_nodes;
        uint8_t         m_color;

        float           m_rotation;
        vi2d            m_origin;
        vi2d            m_position;
        Rectf           local_bounds;
        Transform       m_transform;

        bool            transf_need_update;

    protected:
        //  Generates localBound Rect. Not called in virtual Shape class,
        //  needs to be called by derived class at construction, after arr_nodes is populated
        void            setLocalBounds();

        //  Update transformation matrix
        void            updateTransform();

        //  Update every node in node_arr
        void            updateNodes();
    };

}

//T x (1, x, y) per ogni node
#endif //shape_hpp
