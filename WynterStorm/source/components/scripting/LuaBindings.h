#ifndef WYNTERSTORM_LUA_BINDINGS_H
#define WYNTERSTORM_LUA_BINDINGS_H
#include <lua.hpp>

namespace ws {
	namespace components {
		namespace scripting {
			namespace lua {
				// light user data wrapper
				struct lua_light_object{
					size_t type_hash;
					void* object_pointer;
				};
				template<typename ObjectType>
				lua_light_object* WrapLightObject(ObjectType* object) {
					lua_light_object* light_object = new lua_light_object;
					light_object->type_hash = typeid(ObjectType).hash_code();
					light_object->object_pointer = (void*)object;
					return light_object;
				}
				template<typename ObjectType>
				ObjectType* UnwrapLightObject(lua_light_object* light_object) {
					// we can exit early with a quick check of the type hash
					if(light_object->type_hash == typeid(ObjectType).hash_code()) {
						ObjectType* object = (ObjectType*)(light_object->object_pointer);
						return object;
						/*ObjectType* object = dynamic_cast<ObjectType*>(light_object->object_pointer);
						if(object != nullptr) {
							return object;
						}*/
					}
					return nullptr;
				}

				// Push for generic user data
				template<typename DataType>
				int Push(lua_State* state, DataType* object) {
					auto lightObject = ws::components::scripting::lua::WrapLightObject<DataType>(object);
					lua_pushlightuserdata(state, (void*)&lightObject);
					return 0;
				}
				// Push for integers
				int PushNumber(lua_State* state, int integer) {
					lua_pushnumber(state, integer);
					return 0;
				}

				int Pop(lua_State* state, int index = -1) {
					lua_pop(state, index);
					return 0;
				}

				// PopValue for generic user data
				template<typename DataType>
				DataType* GetValue(lua_State* state, int index = -1) {
					if(lua_type(state, index) != LUA_TLIGHTUSERDATA) {
						// TODO: I really should implement some sort of error handling
						std::cout << "Stack object not light user data" << std::endl;
						return nullptr;
					}
					auto object = ws::components::scripting::lua::UnwrapLightObject<DataType>((lua_light_object*)lua_touserdata(state, index));
					return object;
				}

				// PopValue for integers
				int GetInteger(lua_State* state, int index = -1) {
					if(lua_type(state, index) != LUA_TNUMBER) {
						// TODO: I really should implement some sort of error handling
						return -1;
					}
					return (int)lua_tonumber(state, index);
				}

				// PopValue for doubles
				double GetDouble(lua_State* state, int index = -1) {
					if(lua_type(state, index) != LUA_TNUMBER)
					{
						// TODO: I really should implement some sort of error handling
						return -1;
					}
					return lua_tonumber(state, index);
				}

				// PopValue for doubles
				std::string GetString(lua_State* state, int index = -1) {
					if(lua_type(state, index) != LUA_TSTRING)
					{
						// TODO: I really should implement some sort of error handling
						return std::string("");
					}
					return std::string(lua_tostring(state, index));
				}

				// PopValue for generic user data
				template<typename DataType>
				DataType* PopValue(lua_State* state) {
					if(lua_type(state, lua_gettop(state)) != LUA_TLIGHTUSERDATA) {
						// TODO: I really should implement some sort of error handling
						std::cout << "Stack object not light user data" << std::endl;
						return nullptr;
					}
					lua_light_object* lightObject = (lua_light_object*)lua_touserdata(state, lua_gettop(state));
					auto object = ws::components::scripting::lua::UnwrapLightObject<DataType>(lightObject);
					return object;
				}

				// PopValue for integers
				int PopInteger(lua_State* state) {
					if(lua_type(state, lua_gettop(state)) != LUA_TNUMBER) {
						// TODO: I really should implement some sort of error handling
						return -1;
					}
					int ret = (int)lua_tonumber(state, lua_gettop(state));
					lua_pop(state,1);
					return ret;
				}

				// PopValue for doubles
				double PopDouble(lua_State* state) {
					if(lua_type(state, lua_gettop(state)) != LUA_TNUMBER)
					{
						// TODO: I really should implement some sort of error handling
						return -1;
					}
					double ret = lua_tonumber(state, lua_gettop(state));
					lua_pop(state,1);
					return ret;
				}

				// PopValue for doubles
				std::string PopString(lua_State* state) {
					if(lua_type(state, lua_gettop(state)) != LUA_TSTRING)
					{
						// TODO: I really should implement some sort of error handling
						return std::string("");
					}
					std::string ret(lua_tostring(state, lua_gettop(state)));
					lua_pop(state,1);
					return ret;
				}

				template<typename DataType>
				int SetGlobal(lua_State* state, DataType* data, std::string name) {
					Push<DataType>(state, data);
					lua_setglobal(state, name.c_str());
					return 0;
				}
				int SetGlobal(lua_State* state, int data, std::string name) {
					PushNumber(state, data);
					lua_setglobal(state, name.c_str());
					return 0;
				}
			}
		}
	}
}

#endif