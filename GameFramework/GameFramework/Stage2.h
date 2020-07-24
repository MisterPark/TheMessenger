#pragma once
#include "IScene.h"
class Stage2 :
	public IScene
{
	// IScene을(를) 통해 상속됨
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

	GameObject* player = nullptr;
};

class Stage2_1 : public IScene
{
public:
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

	GameObject* player = nullptr;
};

class Stage2_2 : public IScene
{
public:
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

	GameObject* player = nullptr;
};

