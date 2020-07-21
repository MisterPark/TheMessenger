#include "pch.h"
#include "BlueBall.h"

BlueBall::BlueBall()
{
	hp = 10003;
	speed = 20.f;
	useGravity = true;
	isAlliance = false;
	simpleCollider = { -10, -10, 10, 10 };
	anim->SetAnimation(SpriteIndex::BLUE_BALL);

	jumpCount = 25;
}

BlueBall::~BlueBall()
{
}

void BlueBall::Update()
{
	if (direction == Direction::LEFT)
	{
		position.x -= 150.f * TimeManager::DeltaTime();
	}
	else
	{
		position.x += 150.f * TimeManager::DeltaTime();
	}

	if (jumpCount == 0) return;

	position.y -= 400 * TimeManager::DeltaTime();

	

	jumpCount--;
}

void BlueBall::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
}

void BlueBall::OnCollision(GameObject* _other)
{
}
