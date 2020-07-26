#include "pch.h"
#include "Fireball.h"

Fireball::Fireball()
{
	hp = 10003;
	speed = 150.f;
	useGravity = false;
	isAlliance = false;
	simpleCollider = { -8, -8, 8, 8 };
	anim->SetLoop(true);
}

Fireball::~Fireball()
{
}

void Fireball::Update()
{
	if (direction == Direction::LEFT)
	{
		anim->SetAnimation(SpriteIndex::FIRE_BALL_L1,SpriteIndex::FIRE_BALL_L4);
		position.x -= speed * TimeManager::DeltaTime();
	}
	else
	{
		anim->SetAnimation(SpriteIndex::FIRE_BALL_R1, SpriteIndex::FIRE_BALL_R4);
		position.x += speed * TimeManager::DeltaTime();
	}

	lifeTick += TimeManager::DeltaTime();
	if (lifeTick > lifeTime)
	{
		Die();
	}
}

void Fireball::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
}

void Fireball::OnCollision(GameObject* _other)
{
	if (_other->type == ObjectType::TILE)
	{
		Die();
	}
}
