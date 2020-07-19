#pragma once
#include "Character.h"

class PlayerIdleState;
class PlayerMoveState;

enum class Command
{
	NONE,
	MOVE_LEFT,
	MOVE_RIGHT,
	SIT_DOWN,
	JUMP,
};

class Player : public Character
{
public:
	Player();
	virtual ~Player();

	virtual void Update() override;
	virtual void Render() override;

	void PreprocessCommand();
	void ProcessCommand();
	void UpdateCollisionArea();
	void JumpUpdate();

	void Jump();
	void Attack();

	Animation* anim2 = nullptr;

	Command command = Command::NONE;

	RECT idleCollider = { -10,-40,10,0 };
	RECT jumpCollider = { -10,-40,10,-20 };
	RECT sitCollider = { -10,-20,10,0 };
};

