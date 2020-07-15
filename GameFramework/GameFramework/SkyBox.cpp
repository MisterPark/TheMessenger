#include "pch.h"
#include "SkyBox.h"

SkyBox* pSkyBox = nullptr;

SkyBox::SkyBox()
{
	position.x = -80;
	position.y = 0;
}

SkyBox::~SkyBox()
{
}

SkyBox * SkyBox::GetInstance()
{
	if (pSkyBox == nullptr)
	{
		pSkyBox = new SkyBox;
	}
	return pSkyBox;
}

void SkyBox::Release()
{
	delete pSkyBox;
}

void SkyBox::SetAnimation(SpriteIndex _startIndex, SpriteIndex _endIndex)
{
	pSkyBox->anim->SetAnimation(_startIndex, _endIndex);
}

void SkyBox::Update()
{
	pSkyBox->anim->Update();
}

void SkyBox::Render()
{
	SpriteIndex index = anim->GetCurrentSpriteIndex();
	RenderManager::DrawImage(index, position.x, position.y);
}
