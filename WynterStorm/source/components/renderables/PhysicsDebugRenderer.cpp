#include <core/IGameObject.h>
#include <components/renderables/PhysicsDebugRenderer.h>
#include <components/physics/CircleCollider.h>
#include <components/physics/RectangleCollider.h>
#include <components/PhysicalBody.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>


ws::components::renderables::PhysicsDebugRenderer::PhysicsDebugRenderer(ws::core::IGameObject* owner, std::string tag)
	: ws::components::Renderable(owner, tag) {
}
void ws::components::renderables::PhysicsDebugRenderer::render() {
	auto physicsColliders = owner->getAllComponentsOfType<ws::components::physics::PhysicsCollider>();
	auto physics = owner->getComponent<ws::components::PhysicalBody>("physics");
	for( auto collider : physicsColliders ) {
		if(auto circle = dynamic_cast<ws::components::physics::CircleCollider*>(collider)) {
			// renderable is a circle
			sf::CircleShape shape;
			auto position = Renderable::worldToScreen(physics->getPosition());
			shape.setPosition(position.x, position.y);
			shape.setRadius(circle->getRadius());
			shape.setFillColor(sf::Color::Transparent);
			shape.setOutlineColor(sf::Color::Blue);
			shape.setOutlineThickness(2);
			Renderable::renderTarget->draw(shape);
		}else if(auto rect = dynamic_cast<ws::components::physics::RectangleCollider*>(collider)) {
			// renderable is a rectangle
			sf::RectangleShape shape;
			auto position = Renderable::worldToScreen(physics->getPosition());
			auto size = rect->getSize();
			shape.setPosition(position.x, position.y);
			shape.setSize(sf::Vector2f(size.x, size.y));
			shape.setFillColor(sf::Color::Transparent);
			shape.setOutlineColor(sf::Color::Blue);
			shape.setOutlineThickness(2);
			Renderable::renderTarget->draw(shape);

		}
	}
	/*if(physics != nullptr)
	{
		cpVect position = physics->getPosition();
		shape.setPosition(sf::Vector2f(position.x, position.y));
		Renderable::renderTarget->draw(shape);
	}
	*/
}