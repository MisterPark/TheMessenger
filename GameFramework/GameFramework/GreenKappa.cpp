#include "pch.h"
#include "GreenKappa.h"
#include "Player.h"
#include "Effect.h"

GreenKappa::GreenKappa()
{
	hp = 3;
	speed = 10.f;
	useGravity = true;
	isAlliance = false;
	simpleCollider = { -16,-44,16,0 };
	anim->SetFrameDelay(0.5f);
	anim->SetLoop(true);
}

GreenKappa::~GreenKappa()
{
}

void GreenKappa::Update()
{
	if (KnockBack()) return;
	// �Դ� ����
	BackAndForth();

	if (direction == Direction::LEFT)
	{
		anim->SetAnimation(SpriteIndex::GREEN_KAPPA_L1, SpriteIndex::GREEN_KAPPA_L4);
	}
	else
	{
		anim->SetAnimation(SpriteIndex::GREEN_KAPPA_R1, SpriteIndex::GREEN_KAPPA_R4);
	}

	anim->Update();
}

void GreenKappa::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
}
