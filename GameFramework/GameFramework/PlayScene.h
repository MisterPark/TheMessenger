#pragma once
#include "SceneManager.h"
class PlayScene : public IScene
{
public:
	PlayScene();
	~PlayScene();

	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

};

