//
//  Player.cpp
//  WynterStorm
//
//  Created by Wynter Woods on 5/18/13.
//  Copyright (c) 2013 Amarant. All rights reserved.
//

#include "Player.h"
#include <events/ObjectCollision.h>
#include <components/Physics2D.h>
#include <components/Renderable.h>
#include <iostream>
#include <game/Scene.h>

ws::objects::Player::Player() {
	addComponent<ws::components::Renderable>("renderable");
	addComponent<ws::components::Physics2D>("physics");
}

ws::objects::Player::~Player() {
}

int ws::objects::Player::onEvent(ws::core::IEvent* event) {
	std::cout << "Player::onEvent" << std::endl;
	if(ws::events::ObjectCollision* collisionEvent = dynamic_cast<ws::events::ObjectCollision*>(event))
	{
		std::cout << "Player collided with object: " << collisionEvent->getOtherObject() << std::endl;
	}
	return ws::core::IGameObject::onEvent(event);
}

int ws::objects::Player::subscribeToScene(ws::game::Scene* scene) {
	scene->addEventSubscription<ws::events::ObjectCollision>(this);
	return 0;
}
int ws::objects::Player::update(float deltaTime) {
	return 0;
}
int ws::objects::Player::draw() {
	return 0;
}