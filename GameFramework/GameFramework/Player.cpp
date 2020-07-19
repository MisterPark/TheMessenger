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

	// 애니메이션
	anim2 = new Animation;
	anim->SetFrameDelay(0.1f);
	anim->SetLoop(true);

	// 상태
	
}

Player::~Player()
{
	delete anim2;
}

void Player::Update()
{
	PreprocessCommand();

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
}

void Player::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);
	RenderManager::DrawSprite(SpriteType::NORMAL, anim2->GetCurrentSpriteIndex(), pos.x, pos.y);
	
	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(position + simpleCollider, RGB(0, 255, 0));
	}
	
}

void Player::PreprocessCommand()
{
	//if (jumpFlag == false)
	//{
	//	command = Command::JUMP;
	//}
	//else
	//{
	//	command = Command::NONE;
	//}
	command = Command::NONE;
}

void Player::ProcessCommand()
{
	if (command != Command::JUMP && isFalldown)
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
		if (!jumpFlag) break;
		if (isFalldown) break;
		anim->SetLoop(true);
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::PLAYER_IDLE_L);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::PLAYER_IDLE_R);
		}
		anim2->SetAnimation(SpriteIndex::NONE);
		break;
	case Command::MOVE_LEFT:
		if (!jumpFlag) break;
		if (isFalldown) break;
		anim->SetLoop(true);
		anim->SetAnimation(SpriteIndex::PLAYER_RUN_LEG_L1, SpriteIndex::PLAYER_RUN_LEG_L4);
		anim2->SetAnimation(SpriteIndex::PLAYER_RUN_BODY_L);
		break;
	case Command::MOVE_RIGHT:
		if (!jumpFlag) break;
		if (isFalldown) break;
		anim->SetLoop(true);
		anim->SetAnimation(SpriteIndex::PLAYER_RUN_LEG_R1, SpriteIndex::PLAYER_RUN_LEG_R4);
		anim2->SetAnimation(SpriteIndex::PLAYER_RUN_BODY_R);
		break;
	case Command::SIT_DOWN:
		if (!jumpFlag) break;
		if (isFalldown) break;
		anim->SetLoop(true);
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::PLAYER_SITDOWN_L);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::PLAYER_SITDOWN_R);
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
}
