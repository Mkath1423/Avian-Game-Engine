#pragma once

#include "GameObject.h"
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

enum PositionMode {
	TopLeft,    TopCenter,    TopRight,
	MiddleLeft, MiddleCenter, MiddleRight,
	BottomLeft, BottomCenter, BottomRight
};

class Transform : engine::GameObject
{
	Transform* parent;

	glm::vec3 position;
	glm::vec3 rotaion;
	glm::vec3 scale;

	PositionMode rotatonCenter;

	glm::vec3 GetPosition();
	void SetPosition(glm::vec3 _position);

	glm::vec3 GetRotaion();
	void SetRotaion(glm::vec3 _rotaion);

	glm::vec3 GetScale();
	void SetScale(glm::vec3 _scale);

	glm::vec3 GetWorldPosition();

	glm::vec3 TransformPosition();
};



