#include <components/physics/CircleCollider.h>

ws::components::physics::CircleCollider::CircleCollider(ws::core::IGameObject* owner, std::string tag)
	: ws::components::physics::PhysicsCollider(owner, tag), radius(5) {
}
void ws::components::physics::CircleCollider::addToBody(cpSpace* space, cpBody* body) {
	//cpFloat moment = getMoment();
	shape = cpSpaceAddShape(space, cpCircleShapeNew(body, radius, cpvzero));
	cpShapeSetFriction(shape, friction);
}

void ws::components::physics::CircleCollider::setRadius(cpFloat radius) {
	this->radius = radius;
}

cpFloat ws::components::physics::CircleCollider::getMoment() {
	return cpMomentForCircle(mass, 0, radius, cpvzero);
}

cpFloat ws::components::physics::CircleCollider::getRadius() {
	return radius;
}