#include "pch.h"
#include "ExplosionEffect.h"

ExplosionEffect::ExplosionEffect()
{
	anim->SetAnimation(SpriteIndex::EFFECT_EXPLOSION1, SpriteIndex::EFFECT_EXPLOSION6);
	anim->SetFrameDelay(0.1f);
}

ExplosionEffect::~ExplosionEffect()
{
}

void ExplosionEffect::Update()
{

	if (anim->IsEndFrame())
	{
		Die();
	}
	anim->Update();
}

void ExplosionEffect::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);
}
