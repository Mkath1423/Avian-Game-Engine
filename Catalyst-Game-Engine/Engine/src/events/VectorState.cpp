#include "VectorState.h"
#include "glm/vec2.hpp"

namespace Events {

		VectorState::VectorState(glm::vec2 _position, glm::vec2 _velocity) {
			position = _position;
			velocity = _velocity;
		}

		VectorStateTracker::VectorStateTracker() {
			glm::vec2 position = glm::vec2();
			glm::vec2 velocity = glm::vec2();
		}

		VectorStateTracker::VectorStateTracker(glm::vec2 _position, glm::vec2 _velocity)
		{
			position = _position;
			velocity = _velocity;
		}

		void VectorStateTracker::updatePosition(float x, float y) {
			velocity = glm::vec2(x, y) - position;
			position.x = x;
			position.y = y;
		}

		void VectorStateTracker::updateVelocity(float x, float y) {
			velocity.x = x;
			velocity.y = y;

			position.x += x;
			position.y += y;
		}

		VectorState VectorStateTracker::getState() {
			return VectorState(glm::vec2(position), glm::vec2(velocity));
		}

		glm::vec2 VectorStateTracker::getPosition() { return glm::vec2(position.x, position.y); }
		float VectorStateTracker::getXPosition() { return position.x; }
		float VectorStateTracker::getYPosition() { return position.y; }

		glm::vec2 VectorStateTracker::getVelocity() { return glm::vec2(velocity.x, velocity.y); }
		float VectorStateTracker::getXVelocity() { return velocity.x; }
		float VectorStateTracker::getYVelocity() { return velocity.y; }
	
}
