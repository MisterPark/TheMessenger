#pragma once
#include "IState.h"
class PlayerMoveState :
	public IState
{
	// IState을(를) 통해 상속됨
	virtual void Update(GameObject* pObj) override;
};

