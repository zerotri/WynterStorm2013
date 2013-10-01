#ifndef WYNTERSTORM_SCENE_H
#define WYNTERSTORM_SCENE_H
#include <core/IGameObject.h>
#include <core/IEvent.h>
#include <iostream>
#include <vector>
#include <map>
#include <typeinfo>
#include <SFML/Graphics/RenderWindow.hpp>
#include <core/IComponentSystem.h>
#include <components/PhysicalBody.h>
#include <components/Renderable.h>

#include <chipmunk/chipmunk.h>

namespace ws {
	namespace game {
		class Scene {
		protected:
			std::vector<ws::core::IGameObject*> objects;
			std::map<size_t, std::vector<ws::core::IGameObject*>> eventSubscriptions;

			//physical space
			cpSpace* space;


			//systems
			ws::core::IComponentSystem<ws::components::PhysicalBody> physicsSystem;
			ws::core::IComponentSystem<ws::components::Renderable> renderingSystem;
		public:
			Scene(void);
			virtual ~Scene(void);
			
			void addObject(ws::core::IGameObject* object);

			void update(float deltaTime);
			void draw(sf::RenderWindow& window);


			template<typename EventType> int fireEvent(EventType event) {
				size_t typeHash = typeid(EventType).hash_code();
				auto subscriptions = eventSubscriptions.find(typeHash);
				std::cout << "Number of subscriptions: " << eventSubscriptions.size() << std::endl;
				std::cout << "Sending event of type: " << typeid(EventType).name() << " with id@" << typeid(EventType).hash_code() << std::endl;
				if(subscriptions != eventSubscriptions.end())
				{
					for( auto subscription : subscriptions->second )
					{
						subscription->onEvent(&event);
					}
					return 0;
				}
				else
				{
					std::cout << "Event type not found: " << typeHash << std::endl;
					return 1;
				}
			}


			template<typename EventType> void addEventSubscription(ws::core::IGameObject* subscribedObject) {
				size_t typeHash = typeid(EventType).hash_code();
				auto subscriptions = eventSubscriptions.find(typeHash);
				if(subscriptions == eventSubscriptions.end())
				{
					std::cout << "Adding new subscription: " << typeHash << std::endl;
					eventSubscriptions[typeHash] = std::vector<ws::core::IGameObject*>();
				}
				eventSubscriptions[typeHash].push_back(subscribedObject);
			}

		};
	}
}
#endif