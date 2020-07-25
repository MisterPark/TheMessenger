#include "pch.h"
#include "RangedKappa.h"
#include "Effect.h"

RangedKappa::RangedKappa()
{
	hp = 3;
	speed = 20.f;
	attackDelay = 2.f;
	attackRange = 300;
	useGravity = true;
	isAlliance = false;
	simpleCollider = { -20,-30,20,0 };
	anim->SetFrameDelay(0.5f);
	anim->SetLoop(true);
}

RangedKappa::~RangedKappa()
{
}

void RangedKappa::Update()
{
	if (KnockBack()) return;
	FaceTarget();

	if (IsTargetClose())
	{
		FireBall();
	}

	if (fireOnceFlag)
	{
		if (anim->GetCurrentSpriteIndex() == SpriteIndex::RANGED_KAPPA_L7)
		{
			GameObject* fb = ObjectManager::CreateObject(ObjectType::FIRE_BALL);
			fb->SetPosition(position.x, position.y - 25);
			fb->direction = direction;
			fireOnceFlag = false;
		}
		else if (anim->GetCurrentSpriteIndex() == SpriteIndex::RANGED_KAPPA_R7)
		{
			GameObject* fb = ObjectManager::CreateObject(ObjectType::FIRE_BALL);
			fb->SetPosition(position.x, position.y - 25);
			fb->direction = direction;
			fireOnceFlag = false;
		}
		
	}
	
	
	
	FireBallUpdate();
	AnimationProcess();

	anim->Update();
}

void RangedKappa::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
}


void RangedKappa::AnimationProcess()
{
	if (isShoot)
	{
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::RANGED_KAPPA_L5, SpriteIndex::RANGED_KAPPA_L8);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::RANGED_KAPPA_R5, SpriteIndex::RANGED_KAPPA_R8);
		}
	}
	else
	{
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::RANGED_KAPPA_L1, SpriteIndex::RANGED_KAPPA_L4);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::RANGED_KAPPA_R1, SpriteIndex::RANGED_KAPPA_R4);
		}
	}
}

void RangedKappa::FireBall()
{
	if (!isShoot)
	{
		waitTick += TimeManager::DeltaTime();
		if (waitTick > waitDelay)
		{
			waitTick = 0.f;
			isShoot = true;
			fireOnceFlag = true;
		}
	}
	
}

void RangedKappa::FireBallUpdate()
{
	if (isShoot)
	{
		attackTick += TimeManager::DeltaTime();
		if (attackTick > attackDelay)
		{
			attackTick = 0.f;
			isShoot = false;
		}
	}
	
}
