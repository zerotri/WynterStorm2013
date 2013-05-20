//
//  IComponentService.h
//  WynterStorm
//
//  Created by Wynter Woods on 5/19/13.
//  Copyright (c) 2013 Amarant. All rights reserved.
//

#ifndef WYNTERSTORM_ICOMPONENTSYSTEM_H
#define WYNTERSTORM_ICOMPONENTSYSTEM_H

#include <iostream>
#include <vector>

namespace ws {
	namespace core {
		template<typename ComponentType>
		class IComponentSystem {
		protected:
			std::vector<ComponentType*> registeredComponents;
		public:
			void registerComponent(ComponentType* component) {
				registeredComponents.push_back(component);
			}
			void registerComponents(std::vector<ComponentType*> components) {
				for(auto component : components ) {
					registeredComponents.push_back(component);
				}
			}

			int update(float deltaTime) {
				ComponentType::updateSystem(registeredComponents, deltaTime);
				return 0;
			}

		};
	}
}
#endif
