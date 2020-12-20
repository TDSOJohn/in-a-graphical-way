#include <iostream>
#include <curses.h>

#include "../headers/Transformable.hpp"


namespace iagw
{
	Transformable::Transformable():
		m_origin(0, 0),
		m_position(0, 0),
		m_rotation(0)
	{ }

	Transformable::Transformable(const Transformable& transf_in):
		m_origin(transf_in.m_origin),
		m_position(transf_in.m_position),
		m_rotation(transf_in.m_rotation)
	{ }

	Transformable::Transformable(int32_t x_in, int32_t y_in, float rot_in):
		m_origin(0, 0),
		m_position(x_in, y_in),
		m_rotation(rot_in)
	{ }

	void 		Transformable::move(float x, float y)
	{
		m_transform.translate(x, y);

		m_position 			+= { x, y };
		m_origin 			+= { x, y };
		transf_need_update 	= true;
	}

	void 		Transformable::move(const vf2d& move_vec)
	{
		move(move_vec.x, move_vec.y);
	};

	void 		Transformable::rotate(float r)
	{
		m_transform.rotate(-r, m_origin);
		setRotation(m_rotation + r);
	}

	void 		Transformable::setRotation(float r)
	{
		float temp 			= fmod(r, 360);
		if(temp < 0)
			temp += 360.f;

		m_rotation 			= temp * M_PI / 180.f;
		transf_need_update 	= true;
	}

	float 		Transformable::getRotation() const
	{
		return(m_rotation * 180.f / M_PI);
	}

	const Transform& Transformable::getTransform()
	{
		if(transf_need_update)
			updateTransform();

		return m_transform;
	}

	void 		Transformable::setOrigin(float x, float y)
	{
		m_origin = { x, y };
	}

	void 		Transformable::setOrigin(const vf2d& new_origin)
	{
		setOrigin(new_origin.x, new_origin.y);
	}

	vf2d 		Transformable::getOrigin() const
	{
		return vf2d(m_origin);
	}

	void 		Transformable::updateTransform()
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
