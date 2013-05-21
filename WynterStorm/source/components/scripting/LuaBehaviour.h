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
		class LuaBehaviour : public ws::core::IComponent {
		protected:
			static lua_State* state;
		public:
			LuaBehaviour(ws::core::IGameObject* owner, std::string tag);
			static void SetupLuaState();
			static void RegisterLuaFunction(std::string name, lua_CFunction function);
		};
	}
}

#endif
