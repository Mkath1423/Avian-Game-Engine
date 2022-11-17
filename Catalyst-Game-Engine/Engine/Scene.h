#pragma once
#include <GameObject.h>

using engine::GameObject;

class Scene
{
private:
	GameObject gameObjects[1];
	int num_gameObjects;

public:
	virtual void Initialize();
	virtual void Start();

	virtual void PhysicsUpdate(float deltaTime);

	virtual void EarlyUpdate(float deltaTime);
	virtual void Update(float deltaTime);
	virtual void LateUpdate(float deltaTime);


	virtual void End();
	virtual void Finalize();
};

