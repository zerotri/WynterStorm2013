#include <components/physics/PhysicsCollider.h>
#include <iostream>

ws::components::physics::PhysicsCollider::PhysicsCollider(ws::core::IGameObject* owner, std::string tag)
	: ws::core::IComponent(owner, tag), mass(1), friction(1) {
}
void ws::components::physics::PhysicsCollider::addToBody(cpSpace* space, cpBody* body) {
	std::cout << "Made call to component <PhysicsCollider>::addToBody" << std::endl;
}
void ws::components::physics::PhysicsCollider::setMass(cpFloat mass) {
	this->mass = mass;
}
void ws::components::physics::PhysicsCollider::setFriction(cpFloat friction) {
	this->friction = friction;
}

cpFloat ws::components::physics::PhysicsCollider::getMoment() {
	return 0.0f;
}
cpFloat ws::components::physics::PhysicsCollider::getMass() {
	return mass;
}
cpFloat ws::components::physics::PhysicsCollider::getFriction() {
	return friction;
}