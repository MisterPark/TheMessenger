#pragma once
#include "IScene.h"
#define dfEDIT_WIDTH 1280
#define dfEDIT_HEIGHT 720


class EditScene :
	public IScene
{
	// IScene��(��) ���� ��ӵ�
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

};

