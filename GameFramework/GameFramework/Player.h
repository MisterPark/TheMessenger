#pragma once
#include "Character.h"

enum class PlayerState
{
	IDLE,
	MOVE_LEFT,
	MOVE_RIGHT,
	JUMP_LEFT,
	JUMP_RIGHT,

};

class Player : public Character
{
public:
	Player();
	virtual ~Player();

	virtual void Update() override;
	virtual void Render() override;

	PlayerState state = PlayerState::IDLE;
	Animation* anim2 = nullptr;
};

