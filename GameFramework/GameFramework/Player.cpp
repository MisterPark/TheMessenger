#include "pch.h"
#include "Player.h"

Player::Player()
{
	position = { 0,0 };
	speed = 100.f;
	//useGravity = true;
}

Player::~Player()
{
}

void Player::Update()
{
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
	}
	if (InputManager::GetKey(VK_RIGHT))
	{
		position.x += speed * TimeManager::DeltaTime();
	}
}

void Player::Render()
{
	RenderManager::DrawSprite(SpriteType::NORMAL, SpriteIndex::PLAYER_IDLE_R, position.x, position.y);
}
