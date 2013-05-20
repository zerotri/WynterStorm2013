#include <core/IGameObject.h>
#include <events/ObjectCollision.h>
#include <game/Scene.h>

ws::core::IGameObject::IGameObject(void) {
	std::cout << "New object created" << std::endl;
}


ws::core::IGameObject::~IGameObject(void) {
	for( auto component : components )
	{
		delete component.second;
	}
}
int ws::core::IGameObject::onEvent(ws::core::IEvent* event) {
	if(ws::events::ObjectCollision* collisionEvent = dynamic_cast<ws::events::ObjectCollision*>(event)) {
		// if this object was involved in the collision, call onObjectCollision with other object
		if(collisionEvent->getObjectA() == this) {
			onObjectCollision(collisionEvent->getObjectB());
		} else if(collisionEvent->getObjectB() == this) {
			onObjectCollision(collisionEvent->getObjectA());
		}
	}
	return 0;
}
int ws::core::IGameObject::subscribeToScene(ws::game::Scene* scene) {
	scene->addEventSubscription<ws::events::ObjectCollision>(this);
	return 0;
}
int ws::core::IGameObject::update(float deltaTime) {
	return 0;
}
int ws::core::IGameObject::draw() {
	return 0;
}

int ws::core::IGameObject::onObjectCollision(IGameObject* other) {
	return 0;
}