#ifndef WYNTERSTORM_COMPONENT_PHYSICS_COLLIDER_H
#define WYNTERSTORM_COMPONENT_PHYSICS_COLLIDER_H
#include <core/IComponent.h>
#include <chipmunk.h>

namespace ws {
	namespace components {
		namespace physics {
			class PhysicsCollider : public ws::core::IComponent {
			protected:
				cpShape* shape;
				cpFloat mass;
				cpFloat friction;
			public:
				PhysicsCollider(ws::core::IGameObject* owner, std::string tag);
				virtual void addToBody(cpSpace* space, cpBody* body);

				// getters
				cpFloat getMass();
				cpFloat getFriction();
				virtual cpFloat getMoment();

				// setters
				void setMass(cpFloat mass);
				void setFriction(cpFloat friction);
			};
		}
	}
}
#endif