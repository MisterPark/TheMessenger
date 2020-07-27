#include "pch.h"
#include "LeafMonster.h"
#include "Effect.h"
#include "LeafRing.h"

LeafMonster::LeafMonster()
{
	hp = 20;
	speed = 10.f;
	direction = Direction::LEFT;
	useGravity = true;
	isAlliance = false;
	jumpFlag = false;
	attackRange = 150;
	simpleCollider = { -30,-90,30,0 };
	anim->SetFrameDelay(0.5f);
	anim->SetLoop(false);
}

LeafMonster::~LeafMonster()
{
}

void LeafMonster::Update()
{
	if (isAttacked)
	{
		knockbackTick += TimeManager::DeltaTime();
		if (knockbackDelay < knockbackTick)
		{
			knockbackTick = 0.f;
			isAttacked = false;
		}
	}

	if (!bornFlag)
	{
		if (anim->GetCurrentSpriteIndex() == SpriteIndex::LEAF_BORN_20)
		{
			bornFlag = true;
			lmState = LM_IDLE;
		}
		AnimationProcess();
		anim->Update();
		return;
	}
	
	if (!attack2Ready)
	{
		if (!attack1Flag)
		{
			FaceTarget();

			if (IsTargetClose())
			{
				lmState = LM_IDLE;

				attackTick += TimeManager::DeltaTime();
				if (attackTick > attackDelay)
				{
					attackTick = 0.f;
					lmState = LM_ATTACK1;
					GameObject* ring = ObjectManager::CreateObject(ObjectType::LEAF_RING);
					ring->SetPosition(position.x, position.y - 60);
					ring->direction = direction;

				}

			}
			else
			{
				if (target != nullptr)
				{
					if (target->position.x < position.x)
					{
						position.x -= speed * TimeManager::DeltaTime();
					}
					else
					{
						position.x += speed * TimeManager::DeltaTime();
					}
					lmState = LM_WALK;
				}

			}
		}
	}
	else // АјАн 2
	{
		if (!JumpUpFlag)
		{
			lmState = LM_JUMP;

			float dx = (330.f - position.x) / 30;
			float dy = (110.f - position.y) / 30;

			position.x += dx;
			position.y += dy;

			if (position.y < 140)
			{
				position.x = 330;
				position.y = 100;
				JumpUpFlag = true;
				lmState = LM_IDLE;
			}

		}
		else
		{
			if (!attack2Flag)
			{
				attack2Tick += TimeManager::DeltaTime();
				if (attack2Tick > attack2Delay)
				{
					attack2Tick = 0.f;
					lmState = LM_ATTACK2;
					if (!attack2Once)
					{
						LeafRing* ring = (LeafRing*)ObjectManager::CreateObject(ObjectType::LEAF_RING);
						ring->SetPosition(position.x, position.y - 20);
						ring->direction = Direction::LEFT;
						ring->isAttack1 = false;
						ring = (LeafRing*)ObjectManager::CreateObject(ObjectType::LEAF_RING);
						ring->SetPosition(position.x, position.y);
						ring->direction = Direction::RIGHT;
						ring->isAttack1 = false;

						attack2Once = true;
					}
					
					
				}
			}
			else
			{
				if (!JumpDownFlag)
				{
					isNotPushed = true;
					lmState = LM_JUMP;

					float dx = (target->position.x - position.x) / 30;
					float dy = (target->position.y - position.y) / 30;

					position.x += dx * TimeManager::DeltaTime();
					position.y += dy * TimeManager::DeltaTime();

					if (position.y > 250)
					{
						JumpDownFlag = true;
						isNotPushed = false;
						lmState = LM_IDLE;
					}
				}
				else
				{
					attack2Ready = false;
					attack1Flag = false;
					attack2Flag = false;
					JumpUpFlag = false;
					JumpDownFlag = false;
					isNotPushed = false;
				}
				

			}
			
			
		}
	}
	
	
	

	AnimationProcess();
	anim->Update();
}

void LeafMonster::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
}

void LeafMonster::OnCollision(GameObject* _other)
{
	if (_other->type == ObjectType::LEAF_RING)
	{
		LeafRing* ring = (LeafRing*)_other;
		if (ring->isAttack1 && ring->isComeback)
		{
			attack2Ready = true;
		}
		if (ring->isAttack1 == false && ring->isComeback)
		{
			attack2Once = false;
			attack2Flag = true;
		}
	}
	else if (dynamic_cast<Effect*>(_other))
	{
		Effect* effect = (Effect*)_other;
		if (effect->isAlliance && effect->damageFlag)
		{
			TakeDamage(1);
			isAttacked = true;
			knockbackDirection = effect->direction;

			if (hp <= 0)
			{
				SoundManager::GetInstance()->StopAll();
				ObjectManager::DestroyAll(ObjectType::LEAF_RING);
				int w, h;
				RenderManager::GetSpriteSize(anim->GetCurrentSpriteIndex(), &w, &h);
				GameObject* effect = ObjectManager::CreateObject(ObjectType::EFFECT_MULTI_EXPLOSION);
				effect->SetPosition(position.x, position.y - 40);
			}
		}
	}
}

void LeafMonster::AnimationProcess()
{
	switch (lmState)
	{
	case LM_BORN:
		anim->SetAnimation(SpriteIndex::LEAF_BORN_01, SpriteIndex::LEAF_BORN_20);
		break;
	case LM_IDLE:
		anim->SetLoop(true);
		if (isAttacked)
		{
			if (direction == Direction::LEFT)
			{
				anim->SetAnimation(SpriteIndex::LEAF_ATTACKED_L2);
			}
			else
			{
				anim->SetAnimation(SpriteIndex::LEAF_ATTACKED_R2);
			}
		}
		else
		{
			if (direction == Direction::LEFT)
			{
				anim->SetAnimation(SpriteIndex::LEAF_IDLE_L1, SpriteIndex::LEAF_IDLE_L4);
			}
			else
			{
				anim->SetAnimation(SpriteIndex::LEAF_IDLE_R1, SpriteIndex::LEAF_IDLE_R4);
			}
		}
		
		break;
	case LM_WALK:
		anim->SetLoop(true);
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::LEAF_WALK_L1, SpriteIndex::LEAF_WALK_L4);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::LEAF_WALK_R1, SpriteIndex::LEAF_WALK_R4);
		}
		break;
	case LM_JUMP:
		anim->SetLoop(false);
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::LEAF_JUMP_L1, SpriteIndex::LEAF_JUMP_L4);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::LEAF_JUMP_R1, SpriteIndex::LEAF_JUMP_R4);
		}
		break;
	case LM_ATTACK1:
		anim->SetLoop(false);
		
		if (isAttacked)
		{
			if (direction == Direction::LEFT)
			{
				anim->SetAnimation(SpriteIndex::LEAF_ATTACKED_L1);
			}
			else
			{
				anim->SetAnimation(SpriteIndex::LEAF_ATTACKED_R1);
			}
			
		}
		else
		{
			if (attack1Flag)
			{
				if (direction == Direction::LEFT)
				{
					anim->SetAnimation(SpriteIndex::LEAF_ATTACK1_L4);
				}
				else
				{
					anim->SetAnimation(SpriteIndex::LEAF_ATTACK1_R4);
				}
			}
			else
			{
				attack1Flag = true;
				if (direction == Direction::LEFT)
				{
					anim->SetAnimation(SpriteIndex::LEAF_JUMP_L4, SpriteIndex::LEAF_ATTACK1_L4);
				}
				else
				{
					anim->SetAnimation(SpriteIndex::LEAF_JUMP_R4, SpriteIndex::LEAF_ATTACK1_R4);
				}
			}
			
		}
		break;
	case LM_ATTACK2:
		anim->SetLoop(false);
		anim->SetAnimation(SpriteIndex::LEAF_ATTACK2_L1, SpriteIndex::LEAF_ATTACK2_L5);
		break;
	case LM_ATTACKED:
		break;
	default:
		break;
	}
}
