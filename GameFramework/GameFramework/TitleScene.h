#pragma once
#include "SceneManager.h"

class SelectBox;

class TitleScene : public IScene
{
public:
	TitleScene();
	~TitleScene();
	// IScene을(를) 통해 상속됨
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

	static void Start();
	static void Option();
	static void End();


	SelectBox* pSelectBox = nullptr;

};

