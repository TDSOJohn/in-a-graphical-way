#include <cmath>
#include <curses.h>

#include "../headers/VertexArray.hpp"


namespace iagw
{
    VertexArray::VertexArray():
        m_nodes(4),
        Transformable(),
        Drawable()
    {
        arr_nodes = new Node[4];
        arr_nodes[0].pos = { 0, 0 };
        arr_nodes[1].pos = { rand()%30, rand()%30 };

        setLocalBounds();
    }

    VertexArray::VertexArray(int32_t vertex_count):
        m_nodes(vertex_count),
        Transformable(),
        Drawable()
    {
        arr_nodes = new Node[m_nodes];

        setLocalBounds();
    }

    VertexArray::VertexArray(const vf2d* coordinates, int size):
        m_nodes(std::max(0, size)),
        Transformable(),
        Drawable()
    {
        arr_nodes = new Node[m_nodes];

        for(int i = 0; i < m_nodes; i++)
            arr_nodes[i].pos = { coordinates[i].x, coordinates[i].y };

        setLocalBounds();
    }

    void        VertexArray::setLocalBounds()
    {
        float min_x, min_y, max_x, max_y;
        min_x = max_x = arr_nodes[0].pos.x;
        min_y = max_y = arr_nodes[0].pos.y;

        for(int i = 1; i < m_nodes; i++)
        {
            min_x = std::min(min_x, arr_nodes[i].pos.x);
            max_x = std::max(max_x, arr_nodes[i].pos.x);
            min_y = std::min(min_y, arr_nodes[i].pos.y);
            max_y = std::max(max_y, arr_nodes[i].pos.y);
        }
        local_bounds.x = 0;
        local_bounds.y = 0;
        local_bounds.width = (max_x - min_x);
        local_bounds.height = (max_y - min_y);
    }

    void 		VertexArray::setColor(uint8_t b_col_in, uint8_t f_col_in)
	{
		m_color = b_col_in * 8 + f_col_in;
	}

    void        VertexArray::drawYourself()
    {
/*        if(transf_need_update)
        {
            updateTransform();
        }
*/
        Node temp_nodes[m_nodes];

        for(int i = 0; i < m_nodes; i++)
            temp_nodes[i].pos = m_transform.transformPoint(arr_nodes[i].pos);


        for(int i = 0; i < m_nodes - 1; i++)
        {
            float   dx  = temp_nodes[i+1].pos.x - temp_nodes[i].pos.x;
            float   dy  = temp_nodes[i+1].pos.y - temp_nodes[i].pos.y;

            float   m   = dx/dy;
            float   step, x, y;

            if(std::abs(dx) >= std::abs(dy))
                step = std::abs(dx);
            else
                step = std::abs(dy);

            dx = dx / step;
            dy = dy / step;

            x = temp_nodes[i].pos.x;
            y = temp_nodes[i].pos.y;

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
