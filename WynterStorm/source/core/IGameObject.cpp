#include <core/IGameObject.h>
#include <events/ObjectCollision.h>
#include <game/Scene.h>


ws::GoId ws::core::IGameObject::numGameObjects = 1;
std::map<ws::GoId, ws::core::IGameObject*> ws::core::IGameObject::gameObjectDB;


ws::GoId ws::core::IGameObject::addGameObjectToDB(ws::core::IGameObject* newObject) {
	ws::GoId id = newObject->getId();
	auto objRef = gameObjectDB.find(id);
	if(objRef == gameObjectDB.end()) {
		gameObjectDB[id] = newObject;
		return id;
	}
	return 0;
}
ws::core::IGameObject* ws::core::IGameObject::getGameObjectFromDB(ws::GoId id) {
	auto objRef = gameObjectDB.find(id);
	if(objRef != gameObjectDB.end()) {
		return gameObjectDB[id];
	}
	return nullptr;
}




ws::core::IGameObject::IGameObject(void) {
	id = numGameObjects++;
	std::cout << "New object created with id #" << id << std::endl;
	addGameObjectToDB(this);
}


ws::core::IGameObject::~IGameObject(void) {
	for( auto component : components )
	{
		delete component.second;
	}
}

ws::GoId ws::core::IGameObject::getId() {
	return id;
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