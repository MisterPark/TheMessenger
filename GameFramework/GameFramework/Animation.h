#pragma once
#include "RenderManager.h"

class Animation
{
public:
	Animation();
	~Animation();

	void Update();

	SpriteIndex GetCurrentSpriteIndex();

	void SetAnimation(SpriteIndex _start, SpriteIndex _end);
	void SetFrameDelay(int _framePerSprite);
	void SetLoop(bool _isLoop);


private:
	SpriteIndex startIndex = SpriteIndex::NONE;
	SpriteIndex endIndex = SpriteIndex::NONE;
	SpriteIndex curIndex = SpriteIndex::NONE;
	int frameDelay = 0;
	int frameCount = 0;
	bool isLoop = false;
};

