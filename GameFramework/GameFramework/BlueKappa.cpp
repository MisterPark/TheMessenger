#include "pch.h"
#include "BlueKappa.h"
#include "Effect.h"

BlueKappa::BlueKappa()
{
	hp = 10003;
	speed = 20.f;
	attackDelay = 5.f;
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
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_L1, SpriteIndex::BLUE_KAPPA_L4);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_R1, SpriteIndex::BLUE_KAPPA_R4);
		}
	}

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

void BlueKappa::OnCollision(GameObject* _other)
{
	if (dynamic_cast<Effect*>(_other))
	{
		Effect* effect = (Effect*)_other;
		if (effect->isAlliance && effect->damageFlag)
		{
			TakeDamage(1);
			isAttacked = true;
			knockbackDirection = effect->direction;
		}
	}
}

void BlueKappa::ShootTheBlueBall()
{
	if (reloadingFlag)
	{
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_L5, SpriteIndex::BLUE_KAPPA_L8);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_R5, SpriteIndex::BLUE_KAPPA_R8);
		}

		if (anim->GetCurrentSpriteIndex() == SpriteIndex::BLUE_KAPPA_L8 ||
			anim->GetCurrentSpriteIndex() == SpriteIndex::BLUE_KAPPA_R8 )
		{
			reloadingFlag = false;
		}
	}
	else
	{
		attackTick += TimeManager::DeltaTime();

		if (attackTick < attackDelay) return;
		
		attackTick = 0.f;

		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_L9, SpriteIndex::BLUE_KAPPA_L12);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::BLUE_KAPPA_R9, SpriteIndex::BLUE_KAPPA_R12);
		}

		if (anim->GetCurrentSpriteIndex() == SpriteIndex::BLUE_KAPPA_L11 ||
			anim->GetCurrentSpriteIndex() == SpriteIndex::BLUE_KAPPA_R11)
		{
			reloadingFlag = true;
		}
	}
}
