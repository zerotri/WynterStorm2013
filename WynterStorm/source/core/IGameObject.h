#ifndef WYNTERSTORM_IGAMEOBJECT_H
#define WYNTERSTORM_IGAMEOBJECT_H
#include <core/IEvent.h>
#include <SFML/System/Vector2.hpp>
#include <core/IComponent.h>
#include <core/Types.h>
#include <map>

namespace ws {
	typedef int64_t GoId;
	namespace game {
		class Scene;
	}
	namespace core {
		class IGameObject
		{
		private:
			static ws::GoId numGameObjects;
			static std::map<ws::GoId, IGameObject*> gameObjectDB;
		protected:
			//std::map<size_t, IComponent*> components;
			ws::GoId id;
			std::map<std::string, IComponent*> components;


			// default interpreted events
		
		public:
			static ws::GoId addGameObjectToDB(IGameObject*);
			static IGameObject* getGameObjectFromDB(ws::GoId id);

			IGameObject(void);
			virtual ~IGameObject(void);

			ws::GoId getId();

			template<typename ComponentType> int addComponent(std::string tag = "") {
				if(tag == "")
				{
					tag = typeid(ComponentType).name() + std::to_string(ws::core::IComponent::getNextComponentId());
				}
				auto componentSearch = components.find(tag);
				if(componentSearch == components.end()) {
					components[tag] = new ComponentType(this, tag);
					return ERROR_NONE;
				}
				// TODO: I really should implement this as c++ exceptions. Do that later.
				return ERROR_UNKNOWN;
			}


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
			template<typename ComponentType> std::vector<ComponentType*> getAllComponentsOfType() {
				std::vector<ComponentType*> list;
				for( auto iter : components ) {
					auto comp = dynamic_cast<ComponentType*>(iter.second);
					if(comp != nullptr) {
						list.push_back(comp);
					}
				}
				return list;
			}
			virtual int subscribeToScene(ws::game::Scene* scene);
			virtual int onEvent(ws::core::IEvent* event);

			//
			virtual int update(float deltaTime);
			virtual int draw();

			// automatically handled events
			virtual int onObjectCollision(IGameObject* other);


		
		};
	}
}
#endif