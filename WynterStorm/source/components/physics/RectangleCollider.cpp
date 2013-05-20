#include <components/physics/RectangleCollider.h>

ws::components::physics::RectangleCollider::RectangleCollider(ws::core::IGameObject* owner, std::string tag)
	: ws::components::physics::PhysicsCollider(owner, tag), size(cpv(32,32)) {
}
void ws::components::physics::RectangleCollider::addToBody(cpSpace* space, cpBody* body) {
	cpFloat moment = getMoment();
	shape = cpSpaceAddShape(space, cpBoxShapeNew(body, size.x, size.y));
	cpShapeSetFriction(shape, friction);
}

void ws::components::physics::RectangleCollider::setSize(cpVect size) {
	this->size = size;
}

cpFloat ws::components::physics::RectangleCollider::getMoment() {
	return cpMomentForBox(mass, size.x, size.y);
}

cpVect ws::components::physics::RectangleCollider::getSize() {
	return size;
}