#pragma once
#include "UI.h"
class SkyBox : public UI
{
private:
	SkyBox();
	virtual ~SkyBox();
public:
	static SkyBox* GetInstance();
	static void Release();
	static void SetAnimation(SpriteIndex _startIndex, SpriteIndex _endIndex);

	virtual void Update()override;
	virtual void Render()override;

};

