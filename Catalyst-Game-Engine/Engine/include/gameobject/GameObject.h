#pragma once

#include <vector>
#include <typeinfo>

namespace engine {
	class GameObject; class Component;
	 
	class GameObject {
		bool enabled;

	private:
		std::vector<Component*> components;
		int componentCount;

		void Enable();
		void Disable();

		bool isEnabled();

		void Initialize();
		void Start();

		void PhysicsUpdate(float deltaTime);

		void EarlyUpdate(float deltaTime);
		void Update(float deltaTime);
		void LateUpdate(float deltaTime);

		void End();
		void Finalize();


	public:

		void addComponent(Component*component);

		template<typename T>
		T* getComponent();
	};

	class Component {

	private:
		bool enabled;

		void Enable();
		void Disable();

		bool isEnabled();

		virtual void Initialize();
		virtual void Start();

		virtual void PhysicsUpdate(float deltaTime);

		virtual void EarlyUpdate(float deltaTime);
		virtual void Update(float deltaTime);
		virtual void LateUpdate(float deltaTime);


		virtual void End();
		virtual void Finalize();

		friend class GameObject;
	};
	
}



