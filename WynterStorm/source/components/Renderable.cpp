#include <core/IGameObject.h>
#include <components/Renderable.h>
#include <components/Physics2D.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

ws::components::Renderable::Renderable(ws::core::IGameObject* owner, std::string tag)
	: ws::core::IComponent(owner, tag) {
}
void ws::components::Renderable::render(sf::RenderWindow& renderTarget) {
	sf::CircleShape shape(32.0f);
	shape.setFillColor(sf::Color::Magenta);
	auto physics = owner->getComponent<ws::components::Physics2D>("physics");
	if(physics != nullptr)
	{
		shape.setPosition(physics->getPosition());
		renderTarget.draw(shape);
	}

}