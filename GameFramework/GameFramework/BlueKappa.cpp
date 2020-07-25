#include "pch.h"
#include "BlueKappa.h"
#include "Effect.h"

BlueKappa::BlueKappa()
{
	hp = 1;
	speed = 20.f;
	attackDelay = 2.f;
	attackRange = 300;
	useGravity = true;
	isAlliance = false;
	simpleCollider = { -20,-44,20,0 };
	anim->SetFrameDelay(0.5f);
	anim->SetLoop(true);
}

BlueKappa::~BlueKappa()
{
}

void BlueKappa::Update()
{
	if (KnockBack()) return;

	if (!reloadingFlag)
	{
		FaceTarget();
	}
	

	if (IsTargetClose())
	{
		ShootTheBlueBall();
	}
	else
	{
		bkState = BK_IDLE;
	}
	AnimationProcess();
	anim->Update();

	if (position.y > 500) // 추후 스테이지 별로 바꿔야 함
	{
		Die();
	}
}

void BlueKappa::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
}


void BlueKappa::AnimationProcess()
{
	switch (bkState)
	{
	case BK_IDLE:
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_L1, SpriteIndex::BLUE_KAPPA_L4);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_R1, SpriteIndex::BLUE_KAPPA_R4);
		}
		break;
	case BK_READY:
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_L5, SpriteIndex::BLUE_KAPPA_L8);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_R5, SpriteIndex::BLUE_KAPPA_R8);
		}
		break;
	case BK_SHOOT:
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_L9, SpriteIndex::BLUE_KAPPA_L12);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_R9, SpriteIndex::BLUE_KAPPA_R12);
		}
		break;
	default:
		break;
	}
}

void BlueKappa::ShootTheBlueBall()
{
	attackTick += TimeManager::DeltaTime();
	if (attackTick < attackDelay) return;
	attackTick = 0.f;

	if (reloadingFlag)
	{
		bkState = BK_READY;

		if (anim->GetCurrentSpriteIndex() == SpriteIndex::BLUE_KAPPA_L7 ||
			anim->GetCurrentSpriteIndex() == SpriteIndex::BLUE_KAPPA_R7 )
		{
			reloadingFlag = false;
		}
	}
	else
	{
		bkState = BK_SHOOT;
		GameObject* bb = ObjectManager::CreateObject(ObjectType::BLUE_BALL);
		bb->direction = direction;
		bb->SetPosition(position.x, position.y);
		

		if (anim->GetCurrentSpriteIndex() == SpriteIndex::BLUE_KAPPA_L11 ||
			anim->GetCurrentSpriteIndex() == SpriteIndex::BLUE_KAPPA_R11)
		{
			reloadingFlag = true;
		}
	}
}
