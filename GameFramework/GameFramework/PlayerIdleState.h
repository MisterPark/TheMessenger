#pragma once
#include "IState.h"
#include "Player.h"
class PlayerIdleState :
	public IState
{
	// IState��(��) ���� ��ӵ�
	virtual void Update(GameObject* pObj) override;
};

