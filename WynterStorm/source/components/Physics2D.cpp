#include <components/Physics2D.h>
#include <core/IGameObject.h>


ws::components::Physics2D::Physics2D(ws::core::IGameObject* owner, std::string tag)
	: ws::core::IComponent(owner, tag) {
}

// getters
const sf::Vector2f ws::components::Physics2D::getPosition() {
	return position;
}
const sf::Vector2f ws::components::Physics2D::getConstantForce() {
	return constantForce;
}

// setters
void ws::components::Physics2D::setPosition(const sf::Vector2f newPosition) {
	position = newPosition;
}
void ws::components::Physics2D::setConstantForce(const sf::Vector2f newForce) {
	constantForce = newForce;
}

// update
void ws::components::Physics2D::update(float deltaTime) {
	position = position + (constantForce * deltaTime);
}