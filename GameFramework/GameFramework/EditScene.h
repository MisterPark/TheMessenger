#pragma once
#include "IScene.h"

class Label;

class EditScene :
	public IScene
{
	// IScene을(를) 통해 상속됨
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

	Label* label = nullptr;
};

