#pragma once
#include "Define.h"
#include "Transform.h"
#include "RenderManager.h"
#include "Animation.h"
#include "IState.h"

enum class ObjectType
{
	// 렌더링 순서 중요
	NONE,
	BACK_TILE,
	TILE,
	MONSTER,
	GREEN_KAPPA,
	BLUE_BALL,
	BLUE_KAPPA,
	RUN_KAPPA,
	FIRE_BALL,
	RANGED_KAPPA,
	SCURUBU,
	ITEM_CRYSTAL,
	ITEM_HP,
	PLAYER,
	LEAF_RING,
	LEAF_MONSTER,
	EFFECT,
	EFFECT_EXPLOSION,
	EFFECT_MULTI_EXPLOSION,

	UI,
	LOGO,
	SELECT_BOX,
	HUD_BAR,
	
	LABEL,
	ENDING_CREDIT,
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
	void SetTarget(GameObject* _target);
	void SetAnimation(SpriteIndex _index);
	void SetAnimation(SpriteIndex _startIndex, SpriteIndex _endIndex);
	Transform GetPositionFromCamera();

	void FollowTarget();
	void FaceTarget();
	void TakeDamage(int _damage);
	bool KnockBack();

public:
	// 위치 방향
	Transform position{ 0.f, 0.f };
	Transform localPosition{ 0.f,0.f };
	Direction direction = Direction::RIGHT;
	int width = 0;
	int height = 0;
	
	ObjectType type = ObjectType::NONE;
	int hp = 5;
	int uid = 0;
	bool isEnable = true;
	bool isVisible = true;
	bool jumpFlag = false;
	bool isDead = false;
	bool isAlliance = true;
	bool isSitdown = false;
	//  공격받았을 시 넉백 관련
	Direction knockbackDirection = Direction::RIGHT;
	float knockbackDelay = 0.5f;
	float knockbackTick = 0.f;
	bool isAttacked = false;
	bool isImmortal = false;
	float immotalDelay = 0.5f;
	float immotalTick = 0.f;

	//스프라이트 관련
	Animation* anim = nullptr;

	// 타겟팅
	GameObject* target = nullptr;


};