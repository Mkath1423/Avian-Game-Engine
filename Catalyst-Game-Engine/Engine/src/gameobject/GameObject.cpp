#include "GameObject.h"

#include <typeinfo>

namespace engine {
	
	// GameObject
	void GameObject::Enable()    { enabled = true;  }
	void GameObject::Disable()   { enabled = false; }
	bool GameObject::isEnabled() { return enabled;  }
	
	void GameObject::Initialize() {
		if(!isEnabled()) return; 

		for (Component* c : components) {
			if (!c->isEnabled()) continue;

			c->Initialize();
		}
	}

	void GameObject::Start() {
		if (!isEnabled()) return; 

		for (Component* c : components) {
			if (!c->isEnabled()) continue;

			c->Start();
		}
	}

	void GameObject::PhysicsUpdate(float deltaTime) {
		if (!isEnabled()) return; 

		for (Component* c : components) {
			if (!c->isEnabled()) continue;

			c->PhysicsUpdate(deltaTime);
		}
	}

	void GameObject::EarlyUpdate(float deltaTime) {
		if (!isEnabled()) return; 

		for (Component* c : components) {
			if (!c->isEnabled()) continue;

			c->EarlyUpdate(deltaTime);
		}
	}

	void GameObject::Update(float deltaTime) {
		if (!isEnabled()) return; 

		for (Component* c : components) {
			if (!c->isEnabled()) continue;

			c->Update(deltaTime);
		}
	}

	void GameObject::LateUpdate(float deltaTime) {
		if (!isEnabled()) return; 

		for (Component* c : components) {
			if (!c->isEnabled()) continue;

			c->LateUpdate(deltaTime);
		}
	}

	void GameObject::End() {
		if (!isEnabled()) return; 

		for (Component* c : components) {
			if (!c->isEnabled()) continue;

			c->End();
		}
	}

	void GameObject::Finalize() {
		if (!isEnabled()) return; 

		for (Component* c : components) {
			if (!c->isEnabled()) continue;

			c->Finalize();
		}
	}


	void GameObject::addComponent(Component* component) {
		for (const Component* c : components) {
			if (typeid(*component) == typeid(*c)) {
				break;
			}
		}

		components.push_back(component);
	}

	template<typename T>
	T* GameObject::getComponent() {
		for (Component* component : components) {
			if (typeid(*component) == typeid(T)) {
				return component;
			}
		}

		return nullptr;
	}

	// Component

	void Component::Enable()    { enabled = true;  }
	void Component::Disable()   { enabled = false; }
	bool Component::isEnabled() { return enabled;  }

	void Component::Initialize() { }

	void Component::Start() { }

	void Component::PhysicsUpdate(float deltaTime) { }

	void Component::EarlyUpdate(float deltaTime) { }

	void Component::Update(float deltaTime) { }

	void Component::LateUpdate(float deltaTime) { }

	void Component::End() { }

	void Component::Finalize() { }

}

