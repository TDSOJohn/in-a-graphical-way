#ifndef vertex_array_hpp
#define vertex_array_hpp

#include "Shape.hpp"


namespace iagw
{
    class VertexArray : public Shape
    {
    public:
        VertexArray();
        VertexArray(int32_t vertex_count);
        VertexArray(const vf2d* coordinates, int size);

        void drawYourself() const;
    };
}

#endif //vertex_array_hpp
