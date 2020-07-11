#pragma once
#include <list>
#include "GameObject.h"

using namespace std;


class ObjectManager
{
private:
	ObjectManager();
	~ObjectManager();
public:
	static ObjectManager* GetInstance();
	static GameObject* CreateObject(ObjectType _type);
	static bool DeleteObject(GameObject* _target);
	static void DestroyAll();
	static void DestroyAll(ObjectType _type);

	static void Release();
	static void Update();
	static void LateUpdate();
	static void Render();


	list<GameObject*>objectTable[MaxOfEnum<ObjectType>()];
};