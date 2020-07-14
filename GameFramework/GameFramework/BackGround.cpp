#include "pch.h"
#include "BackGround.h"


BackGround* pBackGround = nullptr;

BackGround::BackGround()
{
	position.x = 0;
	position.y = 0;
}

BackGround::~BackGround()
{
}

BackGround* BackGround::GetInstance()
{
	if (pBackGround == nullptr)
	{
		pBackGround = new BackGround();
	}
	return pBackGround;
}

void BackGround::Release()
{
	delete pBackGround;
}

void BackGround::SetAnimation(SpriteIndex _startIndex, SpriteIndex _endIndex)
{
	pBackGround->anim->SetAnimation(_startIndex, _endIndex);
}

void BackGround::Update()
{
	pBackGround->anim->Update();
}

void BackGround::Render()
{
	int w = 0;
	int h = 0;
	SpriteIndex index = anim->GetCurrentSpriteIndex();
	RenderManager::GetSpriteSize(index, &w, &h);
	RenderManager::SetBufferSize(w, h);
	RenderManager::DrawImage(index, position.x, position.y);
}
