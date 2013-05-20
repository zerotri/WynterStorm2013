#ifndef WYNTERSTORM_COMPONENT_PhysicalBody_H
#define WYNTERSTORM_COMPONENT_PhysicalBody_H
#include <core/IComponent.h>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <chipmunk/chipmunk.h>
namespace ws {
	namespace components {
		class PhysicalBody : public ws::core::IComponent {
		protected:
			cpBody* body;
			cpShape* bodyShape;
			cpSpace* space;
			cpVect position;
		public:
			PhysicalBody(ws::core::IGameObject* owner, std::string tag);
			
			// getters
			const cpVect getPosition();

			
			// setters
			void setPosition(const cpVect newPosition);

			void setSpace(cpSpace* space);
			cpSpace* getSpace();
			
			// update
			void update(float deltaTime);

			static void updateSystem(std::vector<PhysicalBody*> components, float deltaTime);
		};
	}
}
#endif