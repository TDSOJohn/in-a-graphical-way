
#include <curses.h>

#include "../headers/Shape.hpp"


namespace iagw
{
//=====================================
//	Generic virtual Shape class
//=====================================
	Shape::Shape()
	{
		n_nodes = 4;
		arr_nodes = new Node[4];
		color = 55;
	}

	Shape::Shape(uint8_t nodes)
	{
		n_nodes = nodes;
		arr_nodes = new Node[n_nodes];
		color = 56;
	}

	Shape::Shape(uint8_t nodes, uint8_t b_col_in, uint8_t f_col_in)
	{
		n_nodes = nodes;
		arr_nodes = new Node[n_nodes];

		setColor(b_col_in, f_col_in);
	}

	void Shape::setColor(uint8_t b_col_in, uint8_t f_col_in)
	{
		color = b_col_in * 8 + f_col_in;
	}

	void Shape::move(int32_t x, int32_t y)
	{
		for(int i = 0; i < n_nodes; i++)
			arr_nodes[i].pos += { x, y };
		transf_need_update = true;
	}

	void Shape::move(const vi2d& move_vec)
	{
		for(int i = 0; i < n_nodes; i++)
			arr_nodes[i].pos += move_vec;
		transf_need_update = true;
	};

	//	Create local bounds from arrNodes data
	void Shape::setLocalBounds()
	{
		int32_t min_x, min_y, max_x, max_y;
		min_x = max_x = arr_nodes[0].pos.x;
		min_y = max_y = arr_nodes[0].pos.y;

		for(int i = 1; i < n_nodes; i++)
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

	const Transform& Shape::getTransform()
	{
		if(transf_need_update)
			updateTransform();

		return m_transform;
	}

	void Shape::updateTransform()
	{

	}
}
