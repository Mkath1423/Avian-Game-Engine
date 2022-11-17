#pragma once

#include "GameObject.h"
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

class Transform : engine::Component
{
	glm::vec3 position;
	glm::vec3 rotaion;
	glm::vec3 scale;
};

