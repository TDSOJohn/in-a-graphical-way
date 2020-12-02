#include <cmath>
#include <curses.h>

#include "../headers/VertexArray.hpp"


#define PI 3.14159265


namespace iagw
{
    VertexArray::VertexArray():
        Shape(2)
    {
        arr_nodes[0].pos = { 0, 0 };
        arr_nodes[1].pos = { rand()%20 + 20, rand()%20 + 20 };
        printw("nodes: %d, %d   %d, %d", arr_nodes[0].pos.x,
                                         arr_nodes[0].pos.y,
                                         arr_nodes[1].pos.x,
                                         arr_nodes[1].pos.y);
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
        setLocalBounds();
        if(size > 0)
        {
            for(int i = 0; i < size; i++)
                arr_nodes[i].pos = { coordinates[i].x, coordinates[i].y };
        }
    }

    void VertexArray::drawYourself() const
    {
        for(int i = 0; i < n_nodes - 1; i++)
        {
            double      angle = std::atan(float(local_bounds.height) / float(local_bounds.width));
            uint32_t    hyp =  std::sqrt(local_bounds.height*local_bounds.height +
                                    local_bounds.width*local_bounds.width);

            attron(COLOR_PAIR(color));

            for(int j = 0; j < hyp; j++)
            {
        			mvaddch(std::round(std::sin(angle)*j + arr_nodes[i].pos.y),
                            std::round(std::cos(angle)*j + arr_nodes[i].pos.x),
                            ' ');
            }
            attroff(COLOR_PAIR(color));
            printw("line is inside: %d x %d", local_bounds.width, local_bounds.height);
            printw(" angle is: %f and loop is: %d", angle, hyp);
        }

    }
}
