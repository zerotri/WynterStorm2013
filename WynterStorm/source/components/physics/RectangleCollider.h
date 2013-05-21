#ifndef WYNTERSTORM_COMPONENT_RECTANGLE_COLLIDER_H
#define WYNTERSTORM_COMPONENT_RECTANGLE_COLLIDER_H
#include <components/physics/PhysicsCollider.h>
#include <chipmunk/chipmunk.h>

namespace ws {
	namespace components {
		namespace physics {
			class RectangleCollider : public ws::components::physics::PhysicsCollider {
			protected:
				cpVect size;
			public:
				RectangleCollider(ws::core::IGameObject* owner, std::string tag);
				virtual void addToBody(cpSpace* space, cpBody* body);

				// getters
				cpVect getSize();
				virtual cpFloat getMoment();

				// setters
				void setSize(cpVect size);
			};
		}
	}
}
#endif