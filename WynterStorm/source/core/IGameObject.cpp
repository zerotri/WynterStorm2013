#include <core/IGameObject.h>

ws::core::IGameObject::IGameObject(void) {
}


ws::core::IGameObject::~IGameObject(void) {
	for( auto component : components )
	{
		delete component.second;
	}
}
int ws::core::IGameObject::onEvent(ws::core::IEvent* event) {
	return 0;
}
int ws::core::IGameObject::subscribeToScene(ws::game::Scene* scene) {
	return 0;
}
int ws::core::IGameObject::update(float deltaTime) {
	return 0;
}
int ws::core::IGameObject::draw() {
	return 0;
}