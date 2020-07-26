#include "pch.h"
#include "MultiExplosionEffect.h"
#include "ExplosionEffect.h"

MultiExplosionEffect::MultiExplosionEffect()
{
}

MultiExplosionEffect::~MultiExplosionEffect()
{
}

void MultiExplosionEffect::Update()
{
	lifeTick += TimeManager::DeltaTime();
	if (lifeTick > lifeDelay)
	{
		lifeTick = 0.f;
		Die();
	}

	effectTick += TimeManager::DeltaTime();
	if (effectTick > effectDelay)
	{
		effectTick = 0.f;
		int rx = rand() % 60;
		int ry = rand() % 60;
		GameObject* effect = ObjectManager::CreateObject(ObjectType::EFFECT_EXPLOSION);
		effect->SetPosition(position.x - 60 + rx, position.y - 60 + ry);
	}
	
}

void MultiExplosionEffect::Render()
{
}
