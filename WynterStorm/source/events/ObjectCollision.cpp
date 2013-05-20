//
//  ObjectCollision.cpp
//  WynterStorm
//
//  Created by Wynter Woods on 5/18/13.
//  Copyright (c) 2013 Amarant. All rights reserved.
//

#include "ObjectCollision.h"

ws::events::ObjectCollision::ObjectCollision(ws::core::IGameObject* other)
	: other(other) {
	
}
ws::core::IGameObject* ws::events::ObjectCollision::getOtherObject() {
	return this->other;
}