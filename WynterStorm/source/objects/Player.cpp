//
//  Player.cpp
//  WynterStorm
//
//  Created by Wynter Woods on 5/18/13.
//  Copyright (c) 2013 Amarant. All rights reserved.
//

#include <objects/Player.h>
#include <components/PhysicalBody.h>
#include <components/Renderable.h>
#include <components/physics/CircleCollider.h>
#include <components/physics/RectangleCollider.h>
#include <components/renderables/PhysicsDebugRenderer.h>
#include <iostream>
#include <game/Scene.h>

ws::objects::Player::Player() {
	//addComponent<ws::components::Renderable>("renderable");
	addComponent<ws::components::PhysicalBody>("physics");
	addComponent<ws::components::physics::RectangleCollider>("physics_rectangle_shape");
	addComponent<ws::components::renderables::PhysicsDebugRenderer>("physics_renderer");
	//auto collider = getComponent<ws::components::physics::CircleCollider>("physics_circle_shape");
}

ws::objects::Player::~Player() {
}

int ws::objects::Player::onEvent(ws::core::IEvent* event) {
	std::cout << "Player::onEvent" << std::endl;
	return ws::core::IGameObject::onEvent(event);
}

int ws::objects::Player::subscribeToScene(ws::game::Scene* scene) {
	return 0;
}
int ws::objects::Player::update(float deltaTime) {
	return 0;
}
int ws::objects::Player::draw() {
	return 0;
}

int ws::objects::Player::onObjectCollision(IGameObject* other) {
	std::cout << "Player collided with object: " << other << std::endl;
	return 0;
}