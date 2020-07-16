#include "pch.h"
#include "Player.h"

Player::Player()
{
	anim2 = new Animation;
	anim->SetLoop(true);
	anim->SetFrameDelay(1000);
	position = { 0,0 };
	speed = 100.f;
	//useGravity = true;
}

Player::~Player()
{
	delete anim2;
}

void Player::Update()
{
	state = PlayerState::IDLE;

	if (InputManager::GetKey(VK_UP))
	{
		position.y -= speed * TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_DOWN))
	{
		position.y += speed * TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_LEFT))
	{
		position.x -= speed * TimeManager::DeltaTime();
		direction = Direction::LEFT;
		state = PlayerState::MOVE_LEFT;
	}
	if (InputManager::GetKey(VK_RIGHT))
	{
		position.x += speed * TimeManager::DeltaTime();
		direction = Direction::RIGHT;
		state = PlayerState::MOVE_RIGHT;
	}

	anim2->SetAnimation(SpriteIndex::NONE);

	switch (state)
	{
	case PlayerState::IDLE:
		if (direction == Direction::LEFT)
		{
			anim->SetAnimation(SpriteIndex::PLAYER_IDLE_L);
		}
		else
		{
			anim->SetAnimation(SpriteIndex::PLAYER_IDLE_R);
		}
		
		break;
	case PlayerState::MOVE_LEFT:
		anim2->SetAnimation(SpriteIndex::PLAYER_RUN_BODY_L);
		anim->SetAnimation(SpriteIndex::PLAYER_RUN_LEG_L1, SpriteIndex::PLAYER_RUN_LEG_L4);
		break;
	case PlayerState::MOVE_RIGHT:
		anim2->SetAnimation(SpriteIndex::PLAYER_RUN_BODY_R);
		anim->SetAnimation(SpriteIndex::PLAYER_RUN_LEG_R1, SpriteIndex::PLAYER_RUN_LEG_R4);
		break;
	case PlayerState::JUMP_LEFT:
		break;
	case PlayerState::JUMP_RIGHT:
		break;
	default:
		break;
	}
	anim->Update();
	anim2->Update();
}

void Player::Render()
{
	RenderManager::DrawSprite(SpriteType::NORMAL, anim2->GetCurrentSpriteIndex(), position.x, position.y);
	RenderManager::DrawSprite(SpriteType::NORMAL,anim->GetCurrentSpriteIndex(), position.x, position.y);
}
