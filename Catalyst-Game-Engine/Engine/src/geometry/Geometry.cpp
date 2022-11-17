#include "Geometry.h"

#include "glm/vec3.hpp"
#include "glm/vec2.hpp"

namespace geometry2D {

	Quad::Quad(glm::vec3 topLeft, glm::vec3 topRight, glm::vec3 bottomLeft, glm::vec3 bottomRight)
	{
		this->topLeft     = glm::vec3(topLeft.x,     topLeft.y,     topLeft.z);
		this->topRight    = glm::vec3(topRight.x,    topRight.y,    topRight.z);
		this->bottomLeft  = glm::vec3(bottomLeft.x,  bottomLeft.y,  bottomLeft.z);
		this->bottomRight = glm::vec3(bottomRight.x, bottomRight.y, bottomRight.z);
	}

	Quad Quad::Rectangle(glm::vec3 topLeft, float width, float height)
	{
		return Quad(
			glm::vec3(topLeft.x,          topLeft.y,          topLeft.z),
			glm::vec3(topLeft.x + width,  topLeft.y,          topLeft.z),
			glm::vec3(topLeft.x,          topLeft.y - height, topLeft.z),
			glm::vec3(topLeft.x  + width, topLeft.y - height, topLeft.z)
		);
	}

	Quad Quad::Square(glm::vec3 topLeft, float length)
	{
		return Quad(
			glm::vec3(topLeft.x,          topLeft.y,          topLeft.z),
			glm::vec3(topLeft.x + length, topLeft.y,          topLeft.z),
			glm::vec3(topLeft.x,          topLeft.y - length, topLeft.z),
			glm::vec3(topLeft.x + length, topLeft.y - length, topLeft.z)
		);
	}

	float Quad::getTopWidth()    { return abs(topLeft.x    - topRight.x      ); }

	float Quad::getBottomWidth() { return abs(bottomLeft.x - bottomRight.x   ); }

	float Quad::getLeftHeight()  { return abs(topLeft.y    - bottomLeft.y    ); }

	float Quad::getRightHeight() { return abs(topRight.y   - bottomRight.y   ); }

}