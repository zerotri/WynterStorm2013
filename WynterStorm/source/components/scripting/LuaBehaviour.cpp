//
//  LuaBehaviour.cpp
//  WynterStorm
//
//  Created by Wynter Woods on 5/19/13.
//  Copyright (c) 2013 Amarant. All rights reserved.
//

#include <objects/Player.h>
#include <components/physics/CircleCollider.h>
#include <components/scripting/LuaBehaviour.h>
#include <iostream>

lua_State* ws::components::LuaBehaviour::state = 0;


int lua_GameObject_New(lua_State* state) {
	if(lua_type(state, -1) != LUA_TSTRING)
	{
		std::cout << "jnsdk;lfjndskjbdksahdfblhkj,svb" << std::endl;
		return -1;
	}
	else std::cout << "string" << std::endl;
	std::string arg0(lua_tostring(state, -1));
	std::cout << "Creating new object: " << arg0 << std::endl;
	ws::core::IGameObject* object = new ws::core::IGameObject();
	object->addComponent<ws::components::physics::CircleCollider>();
	auto lightObject = ws::components::LuaBehaviour::WrapLightObject<ws::core::IGameObject>(object);
	lua_pushlightuserdata(state, (void*)&lightObject);
	return 1;
}

void RegisterClass_Player(lua_State* state) {

	lua_register(state, "gameobject_new", lua_GameObject_New);
}

void ws::components::LuaBehaviour::SetupLuaState() {
	state = luaL_newstate();
	static const luaL_Reg lualibs[] = {
		{"base", luaopen_base},
		{NULL, NULL}
	};
	const luaL_Reg* lib = lualibs;
	for(; lib->func != NULL; lib++) {
		lib->func(state);
		lua_settop(state, 0);
	}
	RegisterClass_Player(state);

	luaL_dofile(state, "assets/test.lua");
	lua_close(state);
}

void ws::components::LuaBehaviour::RegisterLuaFunction(std::string name, lua_CFunction function) {
	lua_register(state, name.c_str(), function);
}