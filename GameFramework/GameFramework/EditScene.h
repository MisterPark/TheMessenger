#pragma once
#include "IScene.h"

class Label;

class EditScene :
	public IScene
{
	// IScene��(��) ���� ��ӵ�
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

	Label* label = nullptr;
};

