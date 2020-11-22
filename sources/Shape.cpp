#include "../headers/Shape.hpp"


namespace iagw
{
//=====================================
//	Generic virtual Shape class
//=====================================
	Shape::Shape()
	{
		nNodes = 4;
		arrNodes = new Node[4];
	}

	Shape::Shape(uint8_t nodes)
	{
		nNodes = nodes;
		arrNodes = new Node[nNodes];
	}

	void Shape::move(int32_t x, int32_t y)
	{
		for(int i = 0; i < nNodes; i++)
			arrNodes[i].pos += { x, y };
		transfUpdateNeeded = true;
	}

	void Shape::move(const vi2d& moveVec)
	{
		for(int i = 0; i < nNodes; i++)
			arrNodes[i].pos += moveVec;
		transfUpdateNeeded = true;
	};

	//	Create local bounds from arrNodes data
	void Shape::setLocalBounds()
	{
		int32_t min_x, min_y, max_x, max_y;
		min_x = max_x = arrNodes[0].pos.x;
		min_y = max_y = arrNodes[0].pos.y;

		for(int i = 1; i < nNodes; i++)
		{
			min_x = std::min(min_x, arrNodes[i].pos.x);
			max_x = std::max(max_x, arrNodes[i].pos.x);
			min_y = std::min(min_y, arrNodes[i].pos.y);
			max_y = std::max(max_y, arrNodes[i].pos.y);
		}
		localBounds.x = 0;
		localBounds.y = 0;
		localBounds.width = (max_x - min_x);
		localBounds.height = (max_y - min_y);
	}

	void Shape::updateTransform()
	{
		
	}
}
