print("Hello Lua World!")

someObject = gameobject_new("Object_001")
print("Adding component of type: "..ComponentType_CircleCollider);
gameobject_addComponent(someObject, ComponentType_CircleCollider, "circle_collider");