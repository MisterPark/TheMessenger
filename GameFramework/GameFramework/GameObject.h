#pragma once
#include "Define.h"
#include "Transform.h"
#include "RenderManager.h"
#include "Animation.h"
#include "IState.h"

enum class ObjectType
{
	// ������ ���� �߿�
	NONE,
	TILE,
	PLAYER,

	UI,
	LOGO,
	SELECT_BOX,
	HUD_BAR,
	
	LABEL,
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
	void SetAnimation(SpriteIndex _index);
	void SetAnimation(SpriteIndex _startIndex, SpriteIndex _endIndex);

public:
	Transform position{ 0.f, 0.f };
	Transform offset{ 0.f,0.f };
	int width = 0;
	int height = 0;
	
	ObjectType type = ObjectType::NONE;
	Direction direction = Direction::RIGHT;
	int uid = 0;
	bool isEnable = true;
	bool isVisible = true;
	bool jumpFlag = false;
	bool isDead = false;

	//��������Ʈ ����
	Animation* anim = nullptr;
};