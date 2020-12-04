
#include <curses.h>

#include "../headers/Shape.hpp"


namespace iagw
{
//=====================================
//	Generic virtual Shape class
//=====================================
	Shape::Shape():
		m_nodes(4),
		m_origin(0, 0),
		m_rotation(0)
	{
		arr_nodes = new Node[m_nodes];
		m_color = 55;
	}

	Shape::Shape(uint8_t nodes):
		m_nodes(nodes),
		m_origin(0, 0),
		m_rotation(0)
	{
		arr_nodes = new Node[m_nodes];
		m_color = 6;
	}

	Shape::Shape(uint8_t nodes, uint8_t b_col_in, uint8_t f_col_in):
		m_nodes(nodes),
		m_origin(0, 0),
		m_rotation(0)
	{
		arr_nodes = new Node[m_nodes];

		setColor(b_col_in, f_col_in);
	}

	void Shape::setColor(uint8_t b_col_in, uint8_t f_col_in)
	{
		m_color = b_col_in * 8 + f_col_in;
	}

	void Shape::move(int32_t x, int32_t y)
	{
		move({ x, y });
	}

	void Shape::move(const vi2d& move_vec)
	{
		m_origin += move_vec;
		for(int i = 0; i < m_nodes; i++)
			arr_nodes[i].pos += move_vec;
		transf_need_update = true;
	};

	void Shape::rotate(float r)
	{
		setRotation(m_rotation + r);
	}

	void Shape::setRotation(float r)
	{
		m_rotation 			= r;
		transf_need_update 	= true;
	}

	//	Create local bounds from arrNodes data
	void Shape::setLocalBounds()
	{
		int32_t min_x, min_y, max_x, max_y;
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

	const Transform& Shape::getTransform()
	{
		if(transf_need_update)
			updateTransform();

		return m_transform;
	}

	void Shape::updateTransform()
	{
		m_transform = { 	1,				0,						0,
		static_cast<float>	(m_origin.x), 	std::cos(m_rotation), 	std::sin(m_rotation),
		static_cast<float>	(m_origin.y), 	-(std::sin(m_rotation)),std::cos(m_rotation) };
	}
}
