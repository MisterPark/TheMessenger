#include "pch.h"
#include "LeafRing.h"

LeafRing::LeafRing()
{
	hp = 10003;
	speed = 300.f;
	useGravity = false;
	isAlliance = false;
	simpleCollider = { -30, -20, 30, 20 };
	anim->SetLoop(true);
	anim->SetAnimation(SpriteIndex::LEAF_RING_01, SpriteIndex::LEAF_RING_04);
	anim->SetFrameDelay(0.1f);
}

LeafRing::~LeafRing()
{
}

void LeafRing::Update()
{
	if (isAttack1)
	{
		if (direction == Direction::LEFT)
		{
			if (position.x < 0)
			{
				isComeback = true;
			}

			if (!isComeback)
			{
				position.x -= speed * TimeManager::DeltaTime();
			}
			else
			{
				position.x += speed * TimeManager::DeltaTime();
			}
		}
		else
		{
			if (position.x > 640)
			{
				isComeback = true;
			}

			if (!isComeback)
			{
				position.x += speed * TimeManager::DeltaTime();
			}
			else
			{
				position.x -= speed * TimeManager::DeltaTime();
			}
		}
	}
	else // attack2
	{
		if (direction == Direction::LEFT)
		{
			if (!isComeback)
			{
				if (position.y < 300)
				{
					position.y += speed * TimeManager::DeltaTime();
				}
				else
				{
					position.x -= speed * TimeManager::DeltaTime();

					if (position.x < 0)
					{
						isComeback = true;
					}
				}
			}
			else
			{
				if (position.x < 330)
				{
					position.x += speed * TimeManager::DeltaTime();
				}
				else
				{
					position.y -= speed * TimeManager::DeltaTime();

				}
			}
		}
		else
		{
			if (!isComeback)
			{
				if (position.y < 280)
				{
					position.y += speed * TimeManager::DeltaTime();
				}
				else
				{
					position.x += speed * TimeManager::DeltaTime();

					if (position.x > 640)
					{
						isComeback = true;
					}
				}
			}
			else
			{
				if (position.x > 330)
				{
					position.x -= speed * TimeManager::DeltaTime();
				}
				else
				{
					position.y -= speed * TimeManager::DeltaTime();

				}
			}

		}
	}
}

void LeafRing::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
}

void LeafRing::OnCollision(GameObject* _other)
{
	if (_other->type == ObjectType::LEAF_MONSTER)
	{
		if (isComeback)
		{
			Die();
		}
	}
}
