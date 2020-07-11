#pragma once
#include "Define.h"
#include "Transform.h"
enum class ObjectType
{
	NONE,
	UI,

	END
};



class GameObject
{
public:
	GameObject();
	virtual ~GameObject();


	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void OnCollision(GameObject* _other) {};
	virtual void Die();

	void SetPosition(float _x, float _y);

	Transform position{ 0.f, 0.f };
	int width = 0;
	int height = 0;
	
	ObjectType type = ObjectType::NONE;
	bool isDead = false;
	int uid = 0;
	bool isEnable = true;
	bool isVisible = true;
	bool jumpFlag = false;
};