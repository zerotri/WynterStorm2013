#include <core/IGameObject.h>
#include <components/Renderable.h>
#include <components/PhysicalBody.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

cpVect ws::components::Renderable::worldToScreen(cpVect worldPos) {
	cpVect screenSize = cpv(800,600);
	cpVect screenPos = worldPos;
	screenPos = cpvsub(cpvmult(screenSize, 0.5), worldPos);
	return screenPos;
}

sf::RenderWindow* ws::components::Renderable::renderTarget = nullptr;
void ws::components::Renderable::setGlobalRenderTarget(sf::RenderWindow* renderTarget) {
	Renderable::renderTarget = renderTarget;
}

void ws::components::Renderable::updateSystem(std::vector<Renderable*> components, float deltaTime) {
	for( auto component : components ) {
		component->render();
	}
}
ws::components::Renderable::Renderable(ws::core::IGameObject* owner, std::string tag)
	: ws::core::IComponent(owner, tag) {
}
void ws::components::Renderable::render() {
	sf::CircleShape shape(5.0f);
	shape.setFillColor(sf::Color::Magenta);
	auto physics = owner->getComponent<ws::components::PhysicalBody>("physics");
	if(physics != nullptr)
	{
		cpVect position = worldToScreen(physics->getPosition());
		//std::cout << "Position: [" << position.x << "," << position.y << "]" << std::endl;
		shape.setPosition(sf::Vector2f(position.x, position.y));
		Renderable::renderTarget->draw(shape);
	}

}