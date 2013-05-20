//
//  ObjectCollision.h
//  WynterStorm
//
//  Created by Wynter Woods on 5/18/13.
//  Copyright (c) 2013 Amarant. All rights reserved.
//

#ifndef __WynterStorm__ObjectCollision__
#define __WynterStorm__ObjectCollision__

#include <iostream>
#include <core/IEvent.h>
#include <core/IGameObject.h>
namespace ws {
	namespace events {
		class ObjectCollision : public ws::core::IEvent {
		protected:
			ws::core::IGameObject* objectA;
			ws::core::IGameObject* objectB;
		public:
			ObjectCollision(ws::core::IGameObject* objectA, ws::core::IGameObject* objectB);
			ws::core::IGameObject* getObjectA();
			ws::core::IGameObject* getObjectB();
		};
	}
}
#endif /* defined(__WynterStorm__ObjectCollision__) */
