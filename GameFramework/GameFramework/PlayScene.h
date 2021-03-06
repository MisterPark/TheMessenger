#pragma once
#include "SceneManager.h"

class GameObject;

class PlayScene : public IScene
{
public:
	PlayScene();
	~PlayScene();

	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

	
	GameObject* player = nullptr;
};

