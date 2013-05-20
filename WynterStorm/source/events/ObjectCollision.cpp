//
//  ObjectCollision.cpp
//  WynterStorm
//
//  Created by Wynter Woods on 5/18/13.
//  Copyright (c) 2013 Amarant. All rights reserved.
//

#include "ObjectCollision.h"

ws::events::ObjectCollision::ObjectCollision(ws::core::IGameObject* objectA, ws::core::IGameObject* objectB)
	: objectA(objectA), objectB(objectB) {
	
}
ws::core::IGameObject* ws::events::ObjectCollision::getObjectA() {
	return this->objectA;
}
ws::core::IGameObject* ws::events::ObjectCollision::getObjectB() {
	return this->objectB;
}