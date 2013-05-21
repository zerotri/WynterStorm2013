//
//  LuaBehaviour.h
//  WynterStorm
//
//  Created by Wynter Woods on 5/19/13.
//  Copyright (c) 2013 Amarant. All rights reserved.
//

#ifndef WYNTERSTORM_LUABEHAVIOUR_H
#define WYNTERSTORM_LUABEHAVIOUR_H
#include <core/IComponent.h>
#include <lua/lua.hpp>
#include <iostream>

namespace ws {
	namespace components {
		struct lua_light_object{
			size_t type_hash;
			void* object_pointer;
		};
		class LuaBehaviour : public ws::core::IComponent {
		protected:
			static lua_State* state;
		public:
			template<typename ObjectType> static lua_light_object WrapLightObject(ObjectType* object) {
				lua_light_object light_object;
				light_object.type_hash = typeid(ObjectType).hash_code();
				light_object.object_pointer = (void*)object;
				return light_object;
			}
			template<typename ObjectType> static ObjectType* UnwrapLightObject(lua_light_object light_object) {
				// we can exit early with a quick check of the type hash
				if(light_object.type_hash == typeid(ObjectType).hash_code()) {
					ObjectType* object = dynamic_cast<ObjectType*>(light_object.object_pointer);
					if(object != nullptr) {
						return object;
					}
				}
				return nullptr;
			}
			static void SetupLuaState();
			static void RegisterLuaFunction(std::string name, lua_CFunction function);
		};
	}
}

#endif
