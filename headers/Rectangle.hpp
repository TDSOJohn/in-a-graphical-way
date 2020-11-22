#ifndef rectangle_hpp
#define rectangle_hpp

#include "Shape.hpp"


namespace iagw
{
    class Rectangle: public Shape
    {
    public:
                    Rectangle();
                    Rectangle(float x1, float y1, float x2, float y2);

        bool        intersects(const Rectangle& rec);
        void        drawYourself() const;
    };
}

#endif //rectangle_hpp
