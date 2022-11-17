#pragma once

#include "glm/vec2.hpp"

namespace Events {
	struct VectorState {
		glm::vec2 position = glm::vec2();
		glm::vec2 velocity = glm::vec2();

		VectorState(glm::vec2 position, glm::vec2 velocity);
	};

	class VectorStateTracker {
	private:
		glm::vec2 position = glm::vec2();
		glm::vec2 velocity = glm::vec2();

	public:
		VectorStateTracker();
		VectorStateTracker(glm::vec2 _position, glm::vec2 _velocity);

		void updatePosition(float x, float y);

		void updateVelocity(float x, float y);

		VectorState getState();

		glm::vec2 getPosition();
		float getXPosition();
		float getYPosition();

		glm::vec2 getVelocity();
		float getXVelocity();
		float getYVelocity();


	};
}

