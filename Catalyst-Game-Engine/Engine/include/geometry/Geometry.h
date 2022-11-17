#pragma once

#include "glm/vec3.hpp"
#include "glm/vec2.hpp"

namespace geometry2D
{
	enum PositionMode {
		TOP_LEFT,
		TOP_CENTER,
		TOP_RIGHT,
		MIDDLE_LEFT,
		MIDDLE_CENTER,
		MIDDLE_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_CENTER,
		BOTTOM_RIGHT
	};

	/*
	glm::vec2 positionModeAdjustment(PositionMode mode);

	bool IsColliding(Quad     a, Quad     b);
	bool IsColliding(Quad     a, Triangle b);
	bool IsColliding(Quad     a, Circle   b);

	bool IsColliding(Triangle a, Triangle b);
	bool IsColliding(Triangle a, Quad     b);
	bool IsColliding(Triangle a, Circle   b);

	bool IsColliding(Circle   a, Circle   b);
	bool IsColliding(Circle   a, Quad     b);
	bool IsColliding(Circle   a, Triangle b);
	*/

	class Quad {
	private:
		glm::vec3 topLeft;
		glm::vec3 topRight;
		glm::vec3 bottomLeft;
		glm::vec3 bottomRight;

		Quad(glm::vec3 topLeft,
			glm::vec3 topRight,
			glm::vec3 bottomLeft,
			glm::vec3 bottomRight);

	public:
		Quad Rectangle(glm::vec3 topLeft, float width, float height); // rect
		Quad Square(glm::vec3 topLeft, float length); // square


// 		void traslate(glm::vec2 step);
// 		void rotate(glm::vec2 center, float angle);
// 		void scale(glm::vec2 center, float factor);

		float getTopWidth();
		float getBottomWidth();

		float getLeftHeight();
		float getRightHeight();
	};

// 	class Triangle {
// 		glm::vec3 a;
// 		glm::vec3 b;
// 		glm::vec3 c;
// 	};
// 
// 	class Circle {
// 		glm::vec3 center;
// 		float radius;
// 	};
}


