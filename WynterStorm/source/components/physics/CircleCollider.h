#ifndef WYNTERSTORM_COMPONENT_CIRCLE_COLLIDER_H
#define WYNTERSTORM_COMPONENT_CIRCLE_COLLIDER_H
#include <components/physics/PhysicsCollider.h>
#include <chipmunk/chipmunk.h>

namespace ws {
	namespace components {
		namespace physics {
			class CircleCollider : public ws::components::physics::PhysicsCollider {
			protected:
				cpFloat radius;
			public:
				CircleCollider(ws::core::IGameObject* owner, std::string tag);
				virtual void addToBody(cpSpace* space, cpBody* body);

				// getters
				cpFloat getRadius();
				virtual cpFloat getMoment();

				// setters
				void setRadius(cpFloat radius);
			};
		}
	}
}
#endif