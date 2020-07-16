#pragma once
#include "IState.h"
#include "Player.h"
class PlayerIdleState :
	public IState
{
	// IState을(를) 통해 상속됨
	virtual void Update(GameObject* pObj) override;
};

