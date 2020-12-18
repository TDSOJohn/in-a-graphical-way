#ifndef vertex_array_hpp
#define vertex_array_hpp

#include "Drawable.hpp"
#include "Transformable.hpp"


namespace iagw
{
//////////////////////////////////////////////////////////////////////////////////
/// VertexArray class\n
/// stores array of vf2d as vertexes and draws segments between n and (n + 1) nodes\n
/// for every node in the array
//////////////////////////////////////////////////////////////////////////////////
    class VertexArray : public Transformable, public Drawable
    {
    public:
        VertexArray();
        VertexArray(int32_t vertex_count);
        VertexArray(const vf2d* coordinates, int size);

        void            setColor(uint8_t b_col_in, uint8_t f_col_in);

        void            drawYourself();

    protected:
        Node            *arr_nodes;

        uint32_t        m_nodes;
        uint8_t         m_color;

    protected:
        void            setLocalBounds();
    };
}

#endif //vertex_array_hpp
