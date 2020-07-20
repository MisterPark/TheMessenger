#include "pch.h"
#include "Player.h"
#include "PlayerIdleState.h"
#include "PlayerMoveState.h"

Player::Player()
{
	// 정보
	position = { 330,250 };
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
	command = Command::NONE;

	if (InputManager::GetKey(VK_UP))
	{
	}
	if (InputManager::GetKey(VK_DOWN))
	{
		command = Command::SIT_DOWN;
	}
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
	if (InputManager::GetKeyDown('Z'))
	{
		Attack();
	}
	if (InputManager::GetKeyDown('C'))
	{
		Jump();
	}
	


	ProcessCommand();
	
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


void Player::ProcessCommand()
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
	//switch (command)
	//{
	//case Command::NONE:
	//	simpleCollider = idleCollider;
	//	break;
	//case Command::MOVE_LEFT:
	//	simpleCollider = idleCollider;
	//	break;
	//case Command::MOVE_RIGHT:
	//	simpleCollider = idleCollider;
	//	break;
	//case Command::SIT_DOWN:
	//	simpleCollider = sitCollider;
	//	break;
	//case Command::JUMP:
	//	simpleCollider = jumpCollider;
	//	break;
	//default:
	//	break;
	//}
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
		jumpFlag = false;
		command = Command::JUMP;
		jumpCount = 25;
	}
}

void Player::Attack()
{
	if (attackFlag)
	{
		attackFlag = false;
		command = Command::ATTACK;
		attackTick = 0.f;
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
