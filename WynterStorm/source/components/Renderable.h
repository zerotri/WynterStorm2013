#ifndef WYNTERSTORM_COMPONENT_RENDERABLE_H
#define WYNTERSTORM_COMPONENT_RENDERABLE_H
#include <core/IComponent.h>
#include <SFML/Graphics/RenderWindow.hpp>
namespace ws {
	namespace components {
		class Renderable : public ws::core::IComponent {
		protected:
		public:
			Renderable(ws::core::IGameObject* owner, std::string tag);
			void render(sf::RenderWindow& renderTarget);

		};
	}
}
#endif