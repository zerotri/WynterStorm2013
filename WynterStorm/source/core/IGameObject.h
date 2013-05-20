#ifndef WYNTERSTORM_IGAMEOBJECT_H
#define WYNTERSTORM_IGAMEOBJECT_H
#include <core/IEvent.h>
#include <SFML/System/Vector2.hpp>
#include <core/IComponent.h>
#include <core/Types.h>
#include <map>

namespace ws {
	namespace game {
		class Scene;
	}
	namespace core {
		class IGameObject
		{
		protected:
			//std::map<size_t, IComponent*> components;
			std::map<std::string, IComponent*> components;


			// default interpreted events
		
		public:
			IGameObject(void);
			virtual ~IGameObject(void);


			template<typename ComponentType> int addComponent(std::string tag = "") {
				if(tag == "")
				{
					tag = typeid(ComponentType).name() + std::to_string(ws::core::IComponent::getNextComponentId());
				}
				//size_t componentHash = typeid(ComponentType).hash_code();
				auto componentSearch = components.find(tag);
				if(componentSearch == components.end()) {
					components[tag] = new ComponentType(this, tag);
					return ERROR_NONE;
				}
				// TODO: I really should implement this as c++ exceptions. Do that later.
				return ERROR_UNKNOWN;
			}
			/*template<typename ComponentType> int addComponent() {
				size_t componentHash = typeid(ComponentType).hash_code();
				auto componentSearch = components.find(componentHash);
				if(componentSearch == components.end()) {
					components[componentHash] = new ComponentType(this);
					return ERROR_NONE;
				}
				// TODO: I really should implement this as c++ exceptions. Do that later.
				return ERROR_UNKNOWN;
			}*/


			template<typename ComponentType> bool hasComponentOfType() {
				for( auto iter : components ) {
					if( typeid(iter.second) == typeid(ComponentType)){
						return true;
					}
				}
				return false;
			}

			template<typename ComponentType> ComponentType* getComponent(std::string tag) {
				auto componentSearch = components.find(tag);
				if(componentSearch != components.end()) {
					return dynamic_cast<ComponentType*>(componentSearch->second);
				}
				return nullptr;
			}
			template<typename ComponentType> std::vector<ComponentType*> getAllEnabledComponentsOfType() {
				std::vector<ComponentType*> list;
				for( auto iter : components ) {
					if(iter.second->getEnabled()) {
						auto comp = dynamic_cast<ComponentType*>(iter.second);
						if(comp != nullptr) {
							list.push_back(comp);
						}
					}
				}
				return list;
			}
			virtual int subscribeToScene(ws::game::Scene* scene);
			virtual int onEvent(ws::core::IEvent* event);
			virtual int update(float deltaTime);
			virtual int draw();
		
		};
	}
}
#endif