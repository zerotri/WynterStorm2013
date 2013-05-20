#include <game/Scene.h>
#include <core/IGameObject.h>
#include <components/Renderable.h>
#include <components/Physics2D.h>

ws::game::Scene::Scene() {
}
ws::game::Scene::~Scene() {
}

void ws::game::Scene::addObject(ws::core::IGameObject* object) {
	objects.push_back(object);
	object->subscribeToScene(this);
}
void ws::game::Scene::update(float deltaTime) {
	for( auto object : objects )
	{
		auto physics = object->getComponent<ws::components::Physics2D>("physics");
		if( physics != nullptr )
		{
			physics->update(deltaTime);
		}
	}
}
void ws::game::Scene::draw(sf::RenderWindow& window) {
	for( auto object : objects )
	{
		auto renderable = object->getComponent<ws::components::Renderable>("renderable");
		if( renderable != nullptr )
		{
			renderable->render(window);
		}
	}
}