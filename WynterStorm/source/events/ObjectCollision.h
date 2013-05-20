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
			ws::core::IGameObject* other;
		public:
			ObjectCollision(ws::core::IGameObject* other);
			ws::core::IGameObject* getOtherObject();
		};
	}
}
#endif /* defined(__WynterStorm__ObjectCollision__) */
