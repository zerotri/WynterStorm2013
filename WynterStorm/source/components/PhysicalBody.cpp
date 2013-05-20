#include <components/PhysicalBody.h>
#include <core/IComponentSystem.h>
#include <core/IGameObject.h>
#include <components/physics/PhysicsCollider.h>
#include <iostream>

void ws::components::PhysicalBody::updateSystem(std::vector<PhysicalBody*> components, float deltaTime) {
	for( auto component : components ) {
		component->update(deltaTime);
	}
}
ws::components::PhysicalBody::PhysicalBody(ws::core::IGameObject* owner, std::string tag)
	: ws::core::IComponent(owner, tag), body(nullptr), space(nullptr) {
}

// getters
const cpVect ws::components::PhysicalBody::getPosition() {
	return position;
}

// setters
void ws::components::PhysicalBody::setPosition(const cpVect newPosition) {
	position = newPosition;
	cpBodySetPos(body, newPosition);
}
void ws::components::PhysicalBody::setSpace(cpSpace* space) {
	// add all physics colliders to body
	auto colliders = owner->getAllComponentsOfType<ws::components::physics::PhysicsCollider>();

	// calculate moment and mass of all colliders
	cpFloat moment = 0.0f;
	cpFloat mass = 0.0f;
	for( auto collider : colliders ) {
		moment += collider->getMoment();
		mass += collider->getMass();
	}
	std::cout << "Creating body with " << colliders.size() << " colliders. Mass: " << mass << " Moment: " << moment <<std::endl;
	// create physical body
	body = cpSpaceAddBody(space, cpBodyNew(mass, moment));

	// add collider shapes to body
	for( auto collider : colliders ) {
		collider->addToBody(space, body);
	}
	cpBodySetPos(body, position);
}
cpSpace* ws::components::PhysicalBody::getSpace() {
	return space;

}
// update
void ws::components::PhysicalBody::update(float deltaTime) {
	position = cpBodyGetPos(body);
}