#ifndef WYNTERSTORM_GAME_TGDP_H
#define WYNTERSTORM_GAME_TGDP_H

#include <core/IGame.h>
namespace ws {
	namespace games {
		class TGDP : public ws::core::IGame {
		public:
			TGDP(void);
			virtual ~TGDP(void);
		};
	}
}

#endif