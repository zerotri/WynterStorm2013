#ifndef WYNTERSTORM_IGAME_H
#define WYNTERSTORM_IGAME_H

#include <SFML/Graphics.hpp>

namespace ws {
	namespace core {
		class IGame {
		protected:
			sf::RenderWindow window;
		public:
			IGame(void);
			virtual ~IGame(void);
			virtual int Run();
		};
	}
}
#endif