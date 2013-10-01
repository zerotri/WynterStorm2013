//
//  LuaBehaviour.cpp
//  WynterStorm
//
//  Created by Wynter Woods on 5/19/13.
//  Copyright (c) 2013 Amarant. All rights reserved.
//

#include <objects/Player.h>
#include <core/IGame.h>
#include <components/PhysicalBody.h>
#include <components/physics/CircleCollider.h>
#include <components/physics/RectangleCollider.h>
#include <components/scripting/LuaBehaviour.h>
#include <components/scripting/LuaBindings.h>
#include <components/renderables/PhysicsDebugRenderer.h>
#include <components/PhysicalBody.h>
#include <iostream>

#define LUA_USE_LIGHTOBJECT

lua_State* ws::components::LuaBehaviour::state = 0;

int lua_gameobject_new(lua_State* state) {

	//  create new game object
	ws::core::IGameObject* object = new ws::core::IGameObject();

	//  add CircleCollider component
	//  object->addComponent<ws::components::physics::CircleCollider>();
	
	//  push object to lua stack
#ifdef LUA_USE_LIGHTOBJECT
	//ws::components::scripting::lua::Push< ws::core::IGameObject >(state, object);
	auto lightObject = ws::components::scripting::lua::WrapLightObject<ws::core::IGameObject>(object);
	lua_pushlightuserdata(state, (void*)&lightObject);
#else
	ws::components::scripting::lua::PushNumber(state, object->getId());
#endif
	return 1;
}

// lua function: GameObject.AddComponent( GameObject object, int type_hash, string tag )
int lua_gameobject_addcomponent(lua_State* state) {

	int arguments = lua_gettop(state);
	//ws::components::scripting::lua::GetInteger(state);
	std::cout << "gameobject_addComponent called with " << arguments << " arguments." << std::endl;

	//  get string from arg2
	std::string tag = ws::components::scripting::lua::PopString(state);

	//  get integer from arg1, containing RTTI hash_code
	size_t hash = (size_t)ws::components::scripting::lua::PopInteger(state);

	//  get object from arg0
#ifdef LUA_USE_LIGHTOBJECT
	ws::core::IGameObject* object = ws::components::scripting::lua::PopValue<ws::core::IGameObject>(state);
#else
	int objId = ws::components::scripting::lua::PopInteger(state);

	std::cout << "object id specified: #" << objId << std::endl;
	auto object = ws::core::IGameObject::getGameObjectFromDB(objId);
#endif

	//  make sure we aren't about to try to add a component to a nullptr
	if(object == nullptr) {
		std::cout << "[gameobject_addComponent]\t" << "Error finding object" << std::endl;
		//  TODO: I really should implement some sort of error handling
		return -1;
	}

	

	// TODO: hard coding all of these components in isn't the most extendable way to do this
	std::cout << "[gameobject_addComponent]\t" << "Adding component of type @" << hash << std::endl;
	if(hash == typeid(ws::components::LuaBehaviour).hash_code()) {
		// LuaBehaviour
		object->addComponent<ws::components::LuaBehaviour>(tag);

	} else if(hash == typeid(ws::components::PhysicalBody).hash_code()) {
		// PhysicalBody
		object->addComponent<ws::components::PhysicalBody>(tag);

	} else if(hash == typeid(ws::components::physics::CircleCollider).hash_code()) {
		// CircleCollider
		object->addComponent<ws::components::physics::CircleCollider>(tag);

	} else if(hash == typeid(ws::components::physics::RectangleCollider).hash_code()) {
		// RectangleCollider
		object->addComponent<ws::components::physics::RectangleCollider>(tag);

	} else if(hash == typeid(ws::components::Renderable).hash_code()) {
		// Renderable
		object->addComponent<ws::components::Renderable>(tag);

	} else if(hash == typeid(ws::components::renderables::PhysicsDebugRenderer).hash_code()) {
		// PhysicsDebugRenderer
		object->addComponent<ws::components::renderables::PhysicsDebugRenderer>(tag);
	} else {
		std::cout << "Trying to add component of unknown type: " << hash << std::endl;
		std::cout << "CircleCollider: " <<  typeid(ws::components::physics::CircleCollider).hash_code() << std::endl;
	}
	return 1;
}

void RegisterClass_Player(lua_State* state) {
	lua_register(state, "gameobject_new", lua_gameobject_new);
	lua_register(state, "gameobject_addComponent", lua_gameobject_addcomponent);
	ws::components::scripting::lua::SetGlobal(state, typeid(ws::components::physics::CircleCollider).hash_code(),"ComponentType_CircleCollider");
}

ws::components::LuaBehaviour::LuaBehaviour(ws::core::IGameObject* owner, std::string tag)
	: ws::core::IComponent(owner, tag) {
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

	luaL_dofile(state, (ws::core::IGame::getResourcePath() + std::string("test.lua")).c_str());
	lua_close(state);
}

void ws::components::LuaBehaviour::RegisterLuaFunction(std::string name, lua_CFunction function) {
	lua_register(state, name.c_str(), function);
}