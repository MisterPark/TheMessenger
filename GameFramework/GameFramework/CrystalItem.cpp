#include "pch.h"
#include "CrystalItem.h"

CrystalItem::CrystalItem()
{
    simpleCollider = { -10,-10,10,10 };
    anim->SetLoop(true);
    anim->SetFrameDelay(0.15f);
    anim->SetAnimation(SpriteIndex::ITEM_CRYSTAL_01, SpriteIndex::ITEM_CRYSTAL_06);
}

CrystalItem::~CrystalItem()
{
}

void CrystalItem::Update()
{
    anim->Update();
}

void CrystalItem::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
}

void CrystalItem::OnCollision(GameObject* _other)
{
	if (_other->type == ObjectType::PLAYER)
	{
		Die();
	}
}
