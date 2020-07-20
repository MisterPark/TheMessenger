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
	ATTACK,
};

class Player : public Character
{
public:
	Player();
	virtual ~Player();

	virtual void Update() override;
	virtual void Render() override;

	void ProcessCommand();
	void UpdateCollisionArea();
	void JumpUpdate();
	void AttackUpdate();

	void Jump();
	void Attack();

	bool IsSitdown();
	bool IsMoving();

	Animation* anim2 = nullptr;

	Command command = Command::NONE;

	RECT idleCollider = { -10,-40,10,0 };
	RECT jumpCollider = { -10,-40,10,-20 };
	RECT sitCollider = { -10,-20,10,0 };
};

