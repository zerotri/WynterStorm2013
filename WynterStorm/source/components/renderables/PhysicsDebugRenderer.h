#ifndef WYNTERSTORM_COMPONENT_PHYSICS_DEBUG_RENDERABLE_H
#define WYNTERSTORM_COMPONENT_PHYSICS_DEBUG_RENDERABLE_H
#include <core/IComponent.h>
#include <components/Renderable.h>
namespace ws {
	namespace components {
		namespace renderables {
			class PhysicsDebugRenderer: public ws::components::Renderable {
			protected:
			public:
				PhysicsDebugRenderer(ws::core::IGameObject* owner, std::string tag);
				virtual void render();

			};
		}
	}
}
#endif