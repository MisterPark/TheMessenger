#pragma once
#include "IState.h"
class PlayerMoveState :
	public IState
{
	// IState��(��) ���� ��ӵ�
	virtual void Update(GameObject* pObj) override;
};

