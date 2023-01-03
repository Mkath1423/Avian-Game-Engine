#include "GameObject.h"

#include <typeinfo>

namespace engine {
	
	// GameObject
	void GameObject::Enable()    { enabled = true;  }
	void GameObject::Disable()   { enabled = false; }
	bool GameObject::isEnabled() { return enabled;  }
	
	void GameObject::_Initialize() {
		if(!isEnabled()) return; 

		for (GameObject* c : components) {
			if (!c->isEnabled()) continue;

			c->_Initialize();
		}
		Initialize();
	}

	void GameObject::_Start() {
		if (!isEnabled()) return; 

		for (GameObject* c : components) {
			if (!c->isEnabled()) continue;

			c->_Start();
		}

		Start();
	}

	void GameObject::_PhysicsUpdate(float deltaTime) {
		if (!isEnabled()) return; 

		for (GameObject* c : components) {
			if (!c->isEnabled()) continue;

			c->_PhysicsUpdate(deltaTime);
		}

		PhysicsUpdate(deltaTime);
	}

	void GameObject::_EarlyUpdate(float deltaTime) {
		if (!isEnabled()) return; 

		for (GameObject* c : components) {
			if (!c->isEnabled()) continue;

			c->_EarlyUpdate(deltaTime);
		}

		EarlyUpdate(deltaTime);
	}

	void GameObject::_Update(float deltaTime) {
		if (!isEnabled()) return; 

		for (GameObject* c : components) {
			if (!c->isEnabled()) continue;

			c->_Update(deltaTime);
		}

		Update(deltaTime);
	}

	void GameObject::_LateUpdate(float deltaTime) {
		if (!isEnabled()) return; 

		for (GameObject* c : components) {
			if (!c->isEnabled()) continue;

			c->_LateUpdate(deltaTime);
		}

		LateUpdate(deltaTime);
	}

	void GameObject::_End() {
		if (!isEnabled()) return; 

		for (GameObject* c : components) {
			if (!c->isEnabled()) continue;

			c->_End();
		}

		End();
	}

	void GameObject::_Finalize() {
		if (!isEnabled()) return; 

		for (GameObject* c : components) {
			if (!c->isEnabled()) continue;

			c->_Finalize();
		}

		Finalize();
	}
	void GameObject::Initialize() {};
	void GameObject::Start() {};

	void GameObject::PhysicsUpdate(float deltaTime) {};

	void GameObject::EarlyUpdate(float deltaTime) {};
	void GameObject::Update(float deltaTime) {};
	void GameObject::LateUpdate(float deltaTime) {};

	void GameObject::End() {};
	void GameObject::Finalize() {};


	void GameObject::addComponent(GameObject* component) {
		components.push_back(component);
	}
}

