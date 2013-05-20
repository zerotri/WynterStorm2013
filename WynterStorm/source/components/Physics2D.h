#ifndef WYNTERSTORM_COMPONENT_PHYSICS2D_H
#define WYNTERSTORM_COMPONENT_PHYSICS2D_H
#include <core/IComponent.h>
#include <SFML/System/Vector2.hpp>
namespace ws {
	namespace components {
		class Physics2D : public ws::core::IComponent {
		protected:
			sf::Vector2f position;
			sf::Vector2f constantForce;
			float rotation;
		public:
			Physics2D(ws::core::IGameObject* owner, std::string tag);
			
			// getters
			const sf::Vector2f getPosition();
			const sf::Vector2f getConstantForce();
			
			// setters
			void setPosition(const sf::Vector2f newPosition);
			void setConstantForce(const sf::Vector2f newForce);
			
			// update
			void update(float deltaTime);
		};
	}
}
#endif