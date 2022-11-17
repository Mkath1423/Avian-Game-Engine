#include "Inputs.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define NUM_KEYS 350
#define NUM_BUTTONS 8

#include "ErrorChecking.h" 
#include "glm/vec2.hpp"

#include <iostream>
#define print(x) std::cout << x << std::endl;

#include "BooleanState.h"
#include "VectorState.h"

using Events::BooleanStateTracker;
using Events::VectorStateTracker;

namespace Inputs {
	enum KeyCode;

	bool keyValueBuffer[NUM_KEYS] = { false };
	BooleanStateTracker keyStates[NUM_KEYS] = {};

	void key_callback(GLFWwindow* window, int key, int scencode, int action, int mods) {
		print(key << (action == GLFW_PRESS ? " PRESS" : " release"))
		if (key < 0 || key >= NUM_KEYS) return;

		if (action == GLFW_PRESS) 
			keyValueBuffer[key] = true;

		else if (action == GLFW_RELEASE) 
			keyValueBuffer[key] = false;
	}

	VectorStateTracker mouseState = VectorStateTracker();

	void mouse_position_callback(GLFWwindow* window, double xpos, double ypos) {
		mouseState.updatePosition((float)xpos, (float)ypos);
	}

	bool buttonStatesBuffer[NUM_BUTTONS] = { false };
	BooleanStateTracker buttonStates[NUM_BUTTONS] = {};

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		if (button < 0 || button >= NUM_BUTTONS) return;

		if (action == GLFW_PRESS)
			buttonStatesBuffer[button] = true;

		else if (action == GLFW_RELEASE)
			buttonStatesBuffer[button] = false;
	}

	VectorStateTracker scrollState = VectorStateTracker();
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
		scrollState.updateVelocity((float)xoffset, (float)yoffset);
	}
	
	
	void setCallbacks(GLFWwindow* window) {
		glfwSetKeyCallback(window, key_callback);

		glfwSetCursorPosCallback(window, mouse_position_callback);
		glfwSetMouseButtonCallback(window, mouse_button_callback);

		glfwSetScrollCallback(window, scroll_callback);

		// glfwSetCursorEnterCallback(window, cursor_enter_callback);
	}

	void update(float deltatime) {
		for (int i = 0; i < NUM_KEYS; i++) {
			keyStates[i].updateValue(keyValueBuffer[i]);
		}
	}

	namespace KeyBoard {
		bool getValue(int k) {
			if (k < 0 || k >= NUM_KEYS) return false;
			return keyStates[k].getValue(); 
		}

		bool getChanged(int k) {
			if (k < 0 || k >= NUM_KEYS) return false;
			return keyStates[k].getValue();
		}

		bool getPressed(int k) {
			if (k < 0 || k >= NUM_KEYS) return false;
			return keyStates[k].getValue();
		}

		bool getReleased(int k) {
			if (k < 0 || k >= NUM_KEYS) return false;
			return keyStates[k].getValue();
		}
	}

	namespace Mouse {
		glm::vec2 getPosition()      { return mouseState.getPosition(); }
		glm::vec2 getVelocity()      { return mouseState.getVelocity(); }

		float     getXPosition()     { return mouseState.getXPosition(); }
		float     getYPosition()     { return mouseState.getYPosition(); }

		float     getXVelocity()     { return mouseState.getXVelocity(); }
		float     getYVelocity()     { return mouseState.getYVelocity(); }

		bool      getValue(int b)    { if (b < 0 || b >= NUM_BUTTONS) return false; return buttonStates[b].getValue(); }
		bool      getChanged(int b)  { if (b < 0 || b >= NUM_BUTTONS) return false; return buttonStates[b].getChanged(); }
		bool      getPressed(int b)  { if (b < 0 || b >= NUM_BUTTONS) return false; return buttonStates[b].getRising(); }
		bool      getReleased(int b) { if (b < 0 || b >= NUM_BUTTONS) return false; return buttonStates[b].getFalling(); }
	}

	namespace ScrollWheel {
		glm::vec2 getPosition() { return scrollState.getPosition(); }
		glm::vec2 getVelocity() { return scrollState.getVelocity(); }

		float getXPosition()    { return scrollState.getXPosition(); }
		float getYPosition()    { return scrollState.getYPosition(); }

		float getXVelocity()    { return scrollState.getXVelocity(); }
		float getYVelocity()    { return scrollState.getYVelocity(); }
	}
}