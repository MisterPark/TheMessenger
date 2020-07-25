#include "pch.h"
#include "Scurubu.h"
#include "Effect.h"

Scurubu::Scurubu()
{
	hp = 1;
	speed = 20.f;
	useGravity = true;
	isAlliance = false;
	simpleCollider = { -11,-22,11,0 };
	anim->SetAnimation(SpriteIndex::SCURUBU_L1, SpriteIndex::SCURUBU_L4);
	anim->SetFrameDelay(0.5f);
	anim->SetLoop(true);
}

Scurubu::~Scurubu()
{
}

void Scurubu::Update()
{
	if (KnockBack()) return;
	
	MoveLeft();

	anim->Update();

	if (position.y > 500) // 추후 스테이지 별로 바꿔야 함
	{
		Die();
	}
}

void Scurubu::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
}