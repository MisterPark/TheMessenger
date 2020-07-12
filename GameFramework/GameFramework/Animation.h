#pragma once
#include "RenderManager.h"

class Animation
{
public:
	Animation();
	virtual ~Animation();

	virtual void Update() = 0;
	virtual void Render() = 0;

	SpriteIndex startIndex;
	SpriteIndex endIndex;
	int frameDelay = 0;
	bool isLoop = false;
};

