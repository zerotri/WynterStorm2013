#include <core/IComponent.h>
#include <iostream>
namespace ws {
	namespace core {
		static uint64_t numberOfComponents = 1;
	}
}

uint64_t ws::core::IComponent::getNextComponentId() {
	return numberOfComponents;
}

ws::core::IComponent::IComponent(IGameObject* owner, std::string tag)
	: owner(owner), tag(tag), id(numberOfComponents++), enabled(true) {
		std::cout << "Creating component <" << tag << ">" << std::endl;
}
bool ws::core::IComponent::getEnabled() {
	return enabled;
}
void ws::core::IComponent::setEnabled(bool newvalue) {
	enabled = newvalue;
}

void ws::core::IComponent::polymorphismhack() {
}