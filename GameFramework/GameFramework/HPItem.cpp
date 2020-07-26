#include "pch.h"
#include "HPItem.h"

HPItem::HPItem()
{
	simpleCollider = { -16,-32,16,0 };
	anim->SetLoop(true);
	anim->SetFrameDelay(0.15f);
	anim->SetAnimation(SpriteIndex::ITEM_HP_01, SpriteIndex::ITEM_HP_04);
}

HPItem::~HPItem()
{
}

void HPItem::Update()
{
	anim->Update();
}

void HPItem::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
}

void HPItem::OnCollision(GameObject* _other)
{
}
