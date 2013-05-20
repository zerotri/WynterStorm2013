#ifndef WYNTERSTORM_COMPONENT_RENDERABLE_H
#define WYNTERSTORM_COMPONENT_RENDERABLE_H
#include <core/IComponent.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <chipmunk/chipmunk.h>
namespace ws {
	namespace components {
		class Renderable : public ws::core::IComponent {
		protected:
			static sf::RenderWindow* renderTarget;
		public:
			Renderable(ws::core::IGameObject* owner, std::string tag);
			static cpVect worldToScreen(cpVect worldPos);
			virtual void render();

			static void setGlobalRenderTarget(sf::RenderWindow* renderTarget);
			static void updateSystem(std::vector<Renderable*> components, float deltaTime);

		};
	}
}
#endif