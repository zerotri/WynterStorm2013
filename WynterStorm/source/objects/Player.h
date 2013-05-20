//
//  Player.h
//  WynterStorm
//
//  Created by Wynter Woods on 5/18/13.
//  Copyright (c) 2013 Amarant. All rights reserved.
//

#ifndef WYNTERSTORM_PLAYER_H
#define WYNTERSTORM_PLAYER_H

#include <iostream>
#include <core/IGameObject.h>
namespace ws {
	namespace objects {
		class Player : public ws::core::IGameObject {
		protected:
		public:
			Player(void);
			virtual ~Player(void);
			virtual int onEvent(ws::core::IEvent* event);
			virtual int subscribeToScene(ws::game::Scene* scene);
			virtual int update(float deltaTime);
			virtual int draw();
			virtual int onObjectCollision(ws::core::IGameObject* other);
		};
	}
}
#endif