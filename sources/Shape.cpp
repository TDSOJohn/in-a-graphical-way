#include <iostream>
#include <curses.h>

#include "../headers/Shape.hpp"


namespace iagw
{
//=====================================
//	Generic virtual Shape class
//=====================================
	void Shape::printData()
	{
		std::cout << "\norigin is at: " << m_origin.str();
		std::cout << "\nposition is at: " << m_position.str();
		std::cout << "\nrotation is: " << m_rotation;
		std::cout << "\ntransformation is: \n";
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
				std::cout << "\t" << this->getTransform()[i * 3 + j];

			std::cout << "\n\n";
		}
		std::cout << "nodes are at: ";
		for(int i = 0; i < m_nodes; i++)
		{
			std::cout << arr_nodes[i].pos.str() << "\t";
		}
		std::cout << "\n\n";
	}



	Shape::Shape():
		m_nodes(4),
		m_origin(0, 0),
		m_position(0, 0),
		m_rotation(0)
	{
		arr_nodes = new Node[m_nodes];
		m_color = 55;
	}

	Shape::Shape(uint8_t nodes):
		m_nodes(nodes),
		m_origin(0, 0),
		m_position(0, 0),
		m_rotation(0)
	{
		arr_nodes = new Node[m_nodes];
		m_color = 6;
	}

	Shape::Shape(uint8_t nodes, uint8_t b_col_in, uint8_t f_col_in):
		m_nodes(nodes),
		m_origin(0, 0),
		m_position(0, 0),
		m_rotation(0)
	{
		arr_nodes = new Node[m_nodes];

		setColor(b_col_in, f_col_in);
	}

	void Shape::setColor(uint8_t b_col_in, uint8_t f_col_in)
	{
		m_color = b_col_in * 8 + f_col_in;
	}

	void Shape::move(float x, float y)
	{
		m_transform.translate(x, y);

		m_position 			+= { x, y };
		transf_need_update 	= true;
	}

	void Shape::move(const vf2d& move_vec)
	{
		move(move_vec.x, move_vec.y);
	};

	void Shape::rotate(float r)
	{
		m_transform.rotate(-r, m_origin);
		setRotation(m_rotation + r);
	}

	void Shape::setRotation(float r)
	{
		float temp 			= fmod(r, 360);
		if(temp < 0)
			temp += 360.f;

		m_rotation 			= temp * M_PI / 180.f;
		transf_need_update 	= true;
	}

	float Shape::getRotation() const
	{
		return(m_rotation * 180.f / M_PI);
	}

	//	Create local bounds from arrNodes data
	void Shape::setLocalBounds()
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

	const Transform& Shape::getTransform()
	{
		if(transf_need_update)
			updateTransform();

		return m_transform;
	}

	void Shape::setOrigin(float x, float y)
	{
		m_origin = { x, y };
	}

	vf2d Shape::getOrigin() const
	{
		return vf2d(m_origin);
	}

	void Shape::updateTransform()
	{/*
		float sine 		= std::sin(m_rotation);
		float cosine 	= std::cos(m_rotation);

		float temp_x 	= -m_origin.x * cosine - m_origin.y * sine + m_position.x;
		float temp_y 	= m_origin.x * sine - m_origin.y * cosine + m_position.y;

		m_transform 	= {	cosine, 	-(sine), 	temp_x,
							sine, 		cosine,   	temp_y,
						 	0,			0, 			1 };
*/
		transf_need_update = false;
	}
}
