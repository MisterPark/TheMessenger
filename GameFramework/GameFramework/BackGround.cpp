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

void BackGround::Update()
{

}

void BackGround::Render()
{
	RenderManager::DrawSprite(SpriteType::NORMAL, SpriteIndex::TITLE, position.x, position.y);
}
