#include "pch.h"
#include "Player.h"
#include "PlayerIdleState.h"
#include "PlayerMoveState.h"

Player::Player()
{
	// 정보
	position = { 0,360 };
	speed = 100.f;
	//useGravity = true;

	// 애니메이션
	anim2 = new Animation;
	anim->SetFrameDelay(6);
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
		position.y -= speed * TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_DOWN))
	{
		position.y += speed * TimeManager::DeltaTime();
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
	


	ProcessCommand();
	
	anim->Update();
	anim2->Update();
}

void Player::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawSprite(SpriteType::NORMAL, anim->GetCurrentSpriteIndex(), pos.x, pos.y);
	RenderManager::DrawSprite(SpriteType::NORMAL, anim2->GetCurrentSpriteIndex(), pos.x, pos.y);
}

void Player::ProcessCommand()
{
	switch (command)
	{
	case Command::NONE:
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
		anim->SetAnimation(SpriteIndex::PLAYER_RUN_LEG_L1, SpriteIndex::PLAYER_RUN_LEG_L4);
		anim2->SetAnimation(SpriteIndex::PLAYER_RUN_BODY_L);
		break;
	case Command::MOVE_RIGHT:
		anim->SetAnimation(SpriteIndex::PLAYER_RUN_LEG_R1, SpriteIndex::PLAYER_RUN_LEG_R4);
		anim2->SetAnimation(SpriteIndex::PLAYER_RUN_BODY_R);
		break;
	default:
		break;
	}
}
