#pragma once
#include "Character.h"

class PlayerIdleState;
class PlayerMoveState;

enum class Command
{
	NONE,
	MOVE_LEFT,
	MOVE_RIGHT,

};

class Player : public Character
{
public:
	Player();
	virtual ~Player();

	virtual void Update() override;
	virtual void Render() override;

	void ProcessCommand();

	Animation* anim2 = nullptr;

	Command command = Command::NONE;
};

