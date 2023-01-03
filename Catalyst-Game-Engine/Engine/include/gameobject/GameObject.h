#pragma once

#include <vector>
#include <typeinfo>

namespace engine {
	class GameObject; class Component;
	 
	class GameObject {
	private:
		bool enabled;

		std::vector<GameObject*> components;
		int componentCount;


		bool isEnabled();

		// for engine 
		void _Initialize();
		void _Start();

		void _PhysicsUpdate(float deltaTime);

		void _EarlyUpdate(float deltaTime);
		void _Update(float deltaTime);
		void _LateUpdate(float deltaTime);

		void _End();
		void _Finalize();

		// user defined
		virtual void Initialize();
		virtual void Start();

		virtual void PhysicsUpdate(float deltaTime);

		virtual void EarlyUpdate(float deltaTime);
		virtual void Update(float deltaTime);
		virtual void LateUpdate(float deltaTime);

		virtual void End();
		virtual void Finalize();

	protected:

		void addComponent(GameObject* component);

		void Enable();
		void Disable();
	};
}



