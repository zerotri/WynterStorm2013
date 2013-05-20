#include <game/Scene.h>
#include <core/IGameObject.h>
#include <components/Renderable.h>
#include <components/PhysicalBody.h>
#include <components/scripting/LuaBehaviour.h>
#include <SFML/Graphics/RectangleShape.hpp>
cpShape* ground = nullptr;

ws::game::Scene::Scene() {
	// setup lua state

	// setup scene physics

	// create gravity and empty space
	cpVect gravity = cpv(0, -100);
	space = cpSpaceNew();
	cpSpaceSetGravity(space, gravity);

	ground = cpSegmentShapeNew(space->staticBody, cpv(-200, 5), cpv(200, -5), 0);
	cpShapeSetFriction(ground, 1);
	cpSpaceAddShape(space, ground);
	ws::components::LuaBehaviour::SetupLuaState();

}
ws::game::Scene::~Scene() {
}

void ws::game::Scene::addObject(ws::core::IGameObject* object) {
	objects.push_back(object);
	object->subscribeToScene(this);

	auto physicsComponent = object->getComponent<ws::components::PhysicalBody>("physics");
	physicsComponent->setSpace(space);

}
void ws::game::Scene::update(float deltaTime) {
	
	cpSpaceStep(space, deltaTime);
	// PhysicalBody
	for( auto object : objects )
	{
		auto physics = object->getComponent<ws::components::PhysicalBody>("physics");
		if( physics != nullptr )
		{
			physics->update(deltaTime);
		}
	}
}
void ws::game::Scene::draw(sf::RenderWindow& window) {
	ws::components::Renderable::setGlobalRenderTarget(&window);
	auto groundPos = cpBodyGetPos(cpShapeGetBody(ground));
	auto rect = sf::RectangleShape(sf::Vector2f(400, 10));
	//std::cout << "Ground Position [" << groundPos.x << "," << groundPos.y << "]" << std::endl;


	cpVect screenSize = cpv(800,600);
	cpVect screenPos = groundPos;
	screenPos = cpvsub(cpvmult(screenSize, 0.5), groundPos);


	rect.setPosition(sf::Vector2f(screenPos.x-200, screenPos.y));
	rect.setFillColor(sf::Color::Green);
	window.draw(rect);
	// Renderable
	for( auto object : objects )
	{
		auto renderables = object->getAllComponentsOfType<ws::components::Renderable>();
		for( auto renderable : renderables ) {
			if( renderable != nullptr )
			{
				renderable->render();
			}
		}
	}
}