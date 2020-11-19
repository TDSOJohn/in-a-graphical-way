#ifndef shape_hpp
#define shape_hpp

#include <cmath>
#include <algorithm>

#include <curses.h>


#include "V2d.hpp"
#include "Matrix.hpp"
#include "Rect.hpp"

namespace cg
{
    //  Forward declaration
    struct Shape;

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

        virtual void    drawYourself() const = 0;

        vi2d            returnPosition() { return arrNodes[0].pos; }

        Recti           getLocalBounds() { return localBounds; }
        Recti           getGlobalBounds() { return (localBounds + arrNodes[0].pos); }

        void            setPosition(const vi2d& new_pos) {}

        void            move(int32_t x, int32_t y);
        void            move(const vi2d& moveVec);

    protected:
        Node            *arrNodes;
        vf2d            center;
        uint32_t        nNodes = 0;
        uint8_t         color = 7;

        Recti           localBounds;
        fMatrix         transformation;

        bool            hasMoved;

    protected:
        //  Generates localBound Rect. Not called in virtual Shape class,
        //  needs to be called by derived class at construction, after arrNodes is populated
        void            setLocalBounds();
    };

}


#endif //shape_hpp
