#include "pch.h"
#include "SkyBox2.h"

SkyBox2* pSkyBox2 = nullptr;

SkyBox2::SkyBox2()
{
	position = { 0.f,0.f };
}

SkyBox2::~SkyBox2()
{
}

SkyBox2 * SkyBox2::GetInstance()
{
	if (pSkyBox2 == nullptr)
	{
		pSkyBox2 = new SkyBox2;
	}
	return pSkyBox2;
}

void SkyBox2::Release()
{
	if (pSkyBox2)
	{
		delete pSkyBox2;
	}
}

void SkyBox2::SetAnimation(SpriteIndex _startIndex, SpriteIndex _endIndex)
{
	pSkyBox2->anim->SetAnimation(_startIndex, _endIndex);
}

void SkyBox2::Update()
{
	pSkyBox2->anim->Update();
}

void SkyBox2::Render()
{
	SpriteIndex index = anim->GetCurrentSpriteIndex();
	RenderManager::DrawImage(index, position.x, position.y);
}
