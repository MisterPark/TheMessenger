#pragma once
#include "UI.h"
class SkyBox2 :
	public UI
{
private:
	SkyBox2();
	virtual ~SkyBox2();
public:
	static SkyBox2* GetInstance();
	static void Release();
	static void SetAnimation(SpriteIndex _startIndex, SpriteIndex _endIndex);

	virtual void Update()override;
	virtual void Render()override;
};

