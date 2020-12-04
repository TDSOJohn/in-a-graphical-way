#include <cmath>
#include <curses.h>

#include "../headers/VertexArray.hpp"


namespace iagw
{
    VertexArray::VertexArray():
        Shape(2)
    {
        arr_nodes[0].pos = { 30, 30 };
        arr_nodes[1].pos = { rand()%20, rand()%20 };

        setLocalBounds();
    }

    VertexArray::VertexArray(int32_t vertex_count):
        Shape(vertex_count)
    {
        setLocalBounds();
    }

    VertexArray::VertexArray(const vf2d* coordinates, int size):
        Shape(std::max(0, size))
    {
        if(size > 0)
        {
            for(int i = 0; i < size; i++)
                arr_nodes[i].pos = { coordinates[i].x, coordinates[i].y };
        }
        setLocalBounds();
    }

    //  Lines' drawing implemented using Digital Differential Analyzer algorithm
    void VertexArray::drawYourself()
    {
        if(transf_need_update)
        {
            updateTransform();
        }

        for(int i = 0; i < m_nodes - 1; i++)
        {
            float   dx  = arr_nodes[i+1].pos.x - arr_nodes[i].pos.x;
            float   dy  = arr_nodes[i+1].pos.y - arr_nodes[i].pos.y;

            float   m   = dx/dy;
            float   step, x, y;

            if(std::abs(dx) >= std::abs(dy))
                step = std::abs(dx);
            else
                step = std::abs(dy);

            dx = dx / step;
            dy = dy / step;

            x = arr_nodes[i].pos.x;
            y = arr_nodes[i].pos.y;

            attron(COLOR_PAIR(m_color));

            for(int j = 0; j < step; j++)
            {
                mvaddch(std::round(y),
                        std::round(x),
                        ' ');
                x = x + dx;
                y = y + dy;
            }

            attroff(COLOR_PAIR(m_color));
        }
    }
}
