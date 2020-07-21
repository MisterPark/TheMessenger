#include "pch.h"
#include "RunKappa.h"
#include "Effect.h"

RunKappa::RunKappa()
{
	hp = 10003;
	speed = 20.f;
	useGravity = true;
	isAlliance = false;
	simpleCollider = { -24,-48,24,0 };
	anim->SetFrameDelay(0.5f);
	anim->SetLoop(true);
}

RunKappa::~RunKappa()
{
}

void RunKappa::Update()
{
	if (KnockBack()) return;
	// 왔다 갔다
	MoveLeft();

	if (isFalldown)
	{
		anim->SetAnimation(SpriteIndex::RUN_KAPPA_L5);
	}
	else
	{
		anim->SetAnimation(SpriteIndex::RUN_KAPPA_L1, SpriteIndex::RUN_KAPPA_L4);
	}

	anim->Update();

	if (position.y > 500) // 추후 스테이지 별로 바꿔야 함
	{
		Die();
	}
}

void RunKappa::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
}

void RunKappa::OnCollision(GameObject* _other)
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
