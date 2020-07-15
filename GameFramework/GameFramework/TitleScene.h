#pragma once
#include "SceneManager.h"

class SelectBox;

class TitleScene : public IScene
{
public:
	TitleScene();
	~TitleScene();
	// IScene��(��) ���� ��ӵ�
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

	SelectBox* pSelectBox = nullptr;
};

