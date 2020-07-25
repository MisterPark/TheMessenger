#include "pch.h"
#include "Player.h"
#include "PlayerIdleState.h"
#include "PlayerMoveState.h"
#include "Effect.h"
#include "Monster.h"

Player::Player()
{
	// 정보
	hp = 1000;
	position = { 30,250 };
	speed = 200.f;
	useGravity = true;

	simpleCollider = idleCollider;
	direction = Direction::RIGHT;
	// 애니메이션
	anim2 = new Animation;
	anim->SetAnimation(SpriteIndex::PLAYER_IDLE_R);
	anim->SetFrameDelay(0.1f);
	anim2->SetFrameDelay(0.1f);
	anim->SetLoop(true);

	// 상태
	
}

Player::~Player()
{
	delete anim2;
}

void Player::Update()
{
	isSitdown = false;
	useGravity = true;
	command = Command::NONE;

	if (KnockBack())
	{
		if (knockbackDirection == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::PLAYER_ATTACKED_L);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::PLAYER_ATTACKED_R);
		}


		anim2->SetAnimation(SpriteIndex::NONE);
		anim->Update();
		anim2->Update();
		return;
	}

	if (stickFlag)
	{
		jumpFlag = true;
		useGravity = false;
		gravityCount = 0;
		if (InputManager::GetKey(VK_UP))
		{
			if (stickMaxY < (simpleCollider.top + position.y))
			{
				position.y -= 50.f * TimeManager::DeltaTime();
				command = Command::MOVE_UP;
			}
			else
			{
				stickFlag = false;
				Jump();
				anim->SetLoop(false);
				if (direction == Direction::LEFT)
				{
					anim->SetAnimation(SpriteIndex::PLAYER_JUMP_L1, SpriteIndex::PLAYER_JUMP_L6);
				}
				else
				{
					anim->SetAnimation(SpriteIndex::PLAYER_JUMP_R1, SpriteIndex::PLAYER_JUMP_R6);
				}
				anim2->SetAnimation(SpriteIndex::NONE);
			}
			
		}
		else if (InputManager::GetKey(VK_DOWN))
		{
			position.y += 100.f * TimeManager::DeltaTime();
			command = Command::MOVE_DOWN;
		}


		if (InputManager::GetKeyDown('C'))
		{
			// 이구간 좀 변경해야할 듯 ( 점프 애니메이션도 재생 안하고) 점프하면 조금 위로 올라가야함
			if (stickDirection == Direction::LEFT)
			{
				position.x -= 10;
			}
			else
			{
				position.x += 10;
			}
			gravityCount = 0;
			//Jump();
			stickFlag = false;
		}
		
		StickAnimationProcess();
		anim2->SetAnimation(SpriteIndex::NONE);
		anim->Update();
		anim2->Update();
		return;
	}
	else
	{
		if (InputManager::GetKey(VK_RIGHT))
		{
			position.x += speed * TimeManager::DeltaTime();
			direction = Direction::RIGHT;
			command = Command::MOVE_RIGHT;
		}
		else if (InputManager::GetKey(VK_LEFT))
		{
			position.x -= speed * TimeManager::DeltaTime();
			direction = Direction::LEFT;
			command = Command::MOVE_LEFT;
		}
		else if (InputManager::GetKey(VK_DOWN))
		{
			command = Command::SIT_DOWN;
			isSitdown = true;
		}

		if (InputManager::GetKeyDown('Z'))
		{
			Attack();
		}
		if (InputManager::GetKeyDown('C'))
		{
			Jump();
		}
	}


	AnimationProcess();
	
	anim->Update();
	anim2->Update();
	UpdateCollisionArea();
	JumpUpdate();
	AttackUpdate();
}

void Player::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);
	RenderManager::DrawSprite(SpriteType::NORMAL, anim2->GetCurrentSpriteIndex(), pos.x, pos.y);
	
	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
	
}

void Player::OnCollision(GameObject* _other)
{
	if (dynamic_cast<Monster*>(_other))
	{
		TakeDamage(1);
		isAttacked = true;
		knockbackDirection = _other->direction;
	}

	if (_other->type == ObjectType::TILE)
	{
		Tile* tile = dynamic_cast<Tile*>(_other);
		if (tile->option & dfTILE_OPTION_STICK)
		{
			if (jumpFlag) return;

			RECT targetRect = tile->simpleCollider + tile->position;
			RECT myRect = simpleCollider + position;

			RECT area;
			if (IntersectRect(&area, &targetRect, &myRect) == false)return;
			int dx = area.right - area.left;
			int dy = area.bottom - area.top;

			if (dx < dy)
			{
				if (targetRect.left > myRect.left)
				{
					if (tile->option & dfTILE_OPTION_COLLISION_LEFT)
					{
						stickFlag = true;
						stickDirection = Direction::LEFT;
						position.x = targetRect.left - 30;
						position.y = targetRect.top + 40;
						stickMaxY = ObjectManager::FindTopStickTileY(_other);
					}
				}
				else if (targetRect.right < myRect.right)
				{
					if (tile->option & dfTILE_OPTION_COLLISION_RIGHT)
					{
						stickFlag = true;
						stickDirection = Direction::RIGHT;
						position.x = targetRect.right + 30;
						position.y = targetRect.top + 40;
						stickMaxY = ObjectManager::FindTopStickTileY(_other);
					}
				}
			}
			
			
		}
	}
}


void Player::StickAnimationProcess()
{
	if (stickDirection == Direction::LEFT)
	{
		simpleCollider = stickColliderL;

		switch (command)
		{
		case Command::NONE:
			anim->SetAnimation(SpriteIndex::PLAYER_STICK_L1);
			break;
		case Command::MOVE_UP:
			anim->SetLoop(true);
			anim->SetAnimation(SpriteIndex::PLAYER_STICK_L3, SpriteIndex::PLAYER_STICK_L4);
			break;
		case Command::MOVE_DOWN:
			anim->SetAnimation(SpriteIndex::PLAYER_STICK_L2);
			break;
		case Command::JUMP:
			break;
		case Command::ATTACK:
			break;
		default:
			break;
		}
	}
	else
	{
		simpleCollider = stickColliderR;

		switch (command)
		{
		case Command::NONE:
			anim->SetAnimation(SpriteIndex::PLAYER_STICK_R1);
			break;
		case Command::MOVE_UP:
			anim->SetLoop(true);
			anim->SetAnimation(SpriteIndex::PLAYER_STICK_R3, SpriteIndex::PLAYER_STICK_R4);
			break;
		case Command::MOVE_DOWN:
			anim->SetAnimation(SpriteIndex::PLAYER_STICK_R2);
			break;
		case Command::JUMP:
			break;
		case Command::ATTACK:
			break;
		default:
			break;
		}
	}
	
}

void Player::AnimationProcess()
{
	if ((command != Command::JUMP || command != Command::ATTACK) && isFalldown && attackFlag)
	{
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::PLAYER_JUMP_L6);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::PLAYER_JUMP_R6);
		}
		anim2->SetAnimation(SpriteIndex::NONE);
	}


	switch (command)
	{
	case Command::NONE:
		if (!attackFlag) break;
		if (!jumpFlag) break;
		anim->SetLoop(true);
		if (isFalldown)
		{
			if (direction == Direction::LEFT)
			{
				anim->SetAnimation(SpriteIndex::PLAYER_JUMP_L6);
			}
			else
			{
				anim->SetAnimation(SpriteIndex::PLAYER_JUMP_R6);
			}
		}
		else
		{
			if (direction == Direction::LEFT)
			{
				anim->SetAnimation(SpriteIndex::PLAYER_IDLE_L);
			}
			else
			{
				anim->SetAnimation(SpriteIndex::PLAYER_IDLE_R);
			}
			
		}
		anim2->SetAnimation(SpriteIndex::NONE);
		break;
	case Command::MOVE_LEFT:
		if (!jumpFlag) break;
		anim->SetLoop(true);
		if (isFalldown)
		{
			anim->SetAnimation(SpriteIndex::PLAYER_JUMP_L6);
			anim2->SetAnimation(SpriteIndex::NONE);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::PLAYER_RUN_LEG_L1, SpriteIndex::PLAYER_RUN_LEG_L4);
			if (attackFlag == false)
			{
				anim2->SetAnimation(SpriteIndex::PLAYER_RUN_ATTACK_L1, SpriteIndex::PLAYER_RUN_ATTACK_L4);
			}
			else
			{
				anim2->SetAnimation(SpriteIndex::PLAYER_RUN_BODY_L);
			}
		}
		
			
		break;
	case Command::MOVE_RIGHT:
		if (!jumpFlag) break;
		anim->SetLoop(true);
		if (isFalldown)
		{
			anim->SetAnimation(SpriteIndex::PLAYER_JUMP_R6);
			anim2->SetAnimation(SpriteIndex::NONE);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::PLAYER_RUN_LEG_R1, SpriteIndex::PLAYER_RUN_LEG_R4);
			if (attackFlag == false)
			{
				anim2->SetAnimation(SpriteIndex::PLAYER_RUN_ATTACK_R1, SpriteIndex::PLAYER_RUN_ATTACK_R4);
			}
			else
			{
				anim2->SetAnimation(SpriteIndex::PLAYER_RUN_BODY_R);
			}
		}
		break;
	case Command::SIT_DOWN:
		if (!jumpFlag) break;
		if (isFalldown) break;
		anim->SetLoop(false);
		if (attackFlag == false)
		{
			if (direction == Direction::LEFT)
			{
				anim->SetAnimation(SpriteIndex::PLAYER_SIT_ATTACK_L1,SpriteIndex::PLAYER_SIT_ATTACK_L4);
			}
			else
			{
				anim->SetAnimation(SpriteIndex::PLAYER_SIT_ATTACK_R1,SpriteIndex::PLAYER_SIT_ATTACK_R4);
			}
		}
		else
		{
			if (direction == Direction::LEFT)
			{
				anim->SetAnimation(SpriteIndex::PLAYER_SITDOWN_L);
			}
			else
			{
				anim->SetAnimation(SpriteIndex::PLAYER_SITDOWN_R);
			}
		}
		
		anim2->SetAnimation(SpriteIndex::NONE);
		break;
	case Command::JUMP:
		
		anim->SetLoop(false);
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::PLAYER_JUMP_L1, SpriteIndex::PLAYER_JUMP_L6);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::PLAYER_JUMP_R1, SpriteIndex::PLAYER_JUMP_R6);
		}
		anim2->SetAnimation(SpriteIndex::NONE);
		break;
	case Command::ATTACK:
		anim->SetLoop(false);
		if (!jumpFlag) // 체공중에 공격
		{
			if (direction == Direction::LEFT)
			{
				anim->SetAnimation(SpriteIndex::PLAYER_JUMP_ATTACK_L1, SpriteIndex::PLAYER_JUMP_ATTACK_L4);
			}
			else
			{
				anim->SetAnimation(SpriteIndex::PLAYER_JUMP_ATTACK_R1, SpriteIndex::PLAYER_JUMP_ATTACK_R4);
			}
			anim2->SetAnimation(SpriteIndex::NONE);
		}
		else if (IsSitdown()) // 앉았을때 공격
		{
			if (direction == Direction::LEFT)
			{
				anim->SetAnimation(SpriteIndex::PLAYER_SIT_ATTACK_L1, SpriteIndex::PLAYER_SIT_ATTACK_L4);
			}
			else
			{
				anim->SetAnimation(SpriteIndex::PLAYER_SIT_ATTACK_R1, SpriteIndex::PLAYER_SIT_ATTACK_R4);
			}
			anim2->SetAnimation(SpriteIndex::NONE);
		}
		else if(IsMoving()) // 달리기중 공격
		{
			if (direction == Direction::LEFT)
			{
				anim2->SetAnimation(SpriteIndex::PLAYER_RUN_ATTACK_L1,SpriteIndex::PLAYER_RUN_ATTACK_L4);
			}
			else
			{
				anim2->SetAnimation(SpriteIndex::PLAYER_RUN_ATTACK_R1, SpriteIndex::PLAYER_RUN_ATTACK_R4);
			}
			
		}
		else // 그냥 공격
		{
			if (direction == Direction::LEFT)
			{
				anim->SetAnimation(SpriteIndex::PLAYER_ATTACK1_L1, SpriteIndex::PLAYER_ATTACK1_L4);
			}
			else
			{
				anim->SetAnimation(SpriteIndex::PLAYER_ATTACK1_R1, SpriteIndex::PLAYER_ATTACK1_R4);
			}
			anim2->SetAnimation(SpriteIndex::NONE);
		}

		
		break;
	default:
		break;
	}
}

void Player::UpdateCollisionArea()
{
	if (isSitdown)
	{
		simpleCollider = sitCollider;
	}
	else
	{
		simpleCollider = idleCollider;
	}
}

void Player::JumpUpdate()
{
	if (jumpCount == 0) return;
	
	position.y -= 400 * TimeManager::DeltaTime();

	jumpCount--;
}

void Player::AttackUpdate()
{
	if (attackFlag) return;

	attackTick += TimeManager::DeltaTime();

	if (attackTick >= attackDelay)
	{
		attackTick = 0.f;
		attackFlag = true;
	}
}

void Player::Jump()
{
	if (jumpFlag)
	{
		stickFlag = false;
		jumpFlag = false;
		command = Command::JUMP;
		jumpCount = 20;
	}
}

void Player::Attack()
{
	if (attackFlag)
	{
		attackFlag = false;
		command = Command::ATTACK;
		attackTick = 0.f;
		if (direction == Direction::LEFT)
		{
			if (IsMoving())
			{
				Effect* e = (Effect*)ObjectManager::CreateObject(ObjectType::EFFECT);
				e->anim->SetAnimation(SpriteIndex::EFFECT01_L4, SpriteIndex::EFFECT01_L4);
				e->SetPosition(position.x - 35, position.y - 31);
				e->direction = direction;
			}
			else if (isSitdown)
			{
				Effect* e = (Effect*)ObjectManager::CreateObject(ObjectType::EFFECT);
				e->anim->SetAnimation(SpriteIndex::EFFECT01_L1, SpriteIndex::EFFECT01_L3);
				e->SetPosition(position.x - 35, position.y - 10);
				e->direction = direction;
			}
			else
			{
				Effect* e = (Effect*)ObjectManager::CreateObject(ObjectType::EFFECT);
				e->anim->SetAnimation(SpriteIndex::EFFECT01_L1, SpriteIndex::EFFECT01_L3);
				e->SetPosition(position.x - 35, position.y - 31);
				e->direction = direction;
			}
			

		}
		else if (direction == Direction::RIGHT)
		{
			if (IsMoving())
			{
				Effect* e = (Effect*)ObjectManager::CreateObject(ObjectType::EFFECT);
				e->anim->SetAnimation(SpriteIndex::EFFECT01_R4, SpriteIndex::EFFECT01_R4);
				e->SetPosition(position.x + 35, position.y - 31);
				e->direction = direction;
			}
			else if (isSitdown)
			{
				Effect* e = (Effect*)ObjectManager::CreateObject(ObjectType::EFFECT);
				e->anim->SetAnimation(SpriteIndex::EFFECT01_R1, SpriteIndex::EFFECT01_R3);
				e->SetPosition(position.x + 35, position.y - 10);
				e->direction = direction;
			}
			else
			{
				Effect* e = (Effect*)ObjectManager::CreateObject(ObjectType::EFFECT);
				e->anim->SetAnimation(SpriteIndex::EFFECT01_R1, SpriteIndex::EFFECT01_R3);
				e->SetPosition(position.x + 35, position.y - 31);
				e->direction = direction;
			}
			
		}
	}
}

bool Player::IsSitdown()
{
	return (anim->GetCurrentSpriteIndex() == SpriteIndex::PLAYER_SITDOWN_L || anim->GetCurrentSpriteIndex() == SpriteIndex::PLAYER_SITDOWN_R);
}

bool Player::IsMoving()
{
	SpriteIndex cur = anim->GetCurrentSpriteIndex();
	if (cur < SpriteIndex::PLAYER_RUN_LEG_R1) return false;
	if (cur > SpriteIndex::PLAYER_RUN_LEG_L4) return false;
	return true;
}
