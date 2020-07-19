#include "pch.h"
#include "IntroScene.h"
#include "TitleScene.h"
#include "BackGround.h"
#include "SkyBox.h"

void IntroScene::OnLoaded()
{
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::INTRO, SpriteIndex::CUT_SCENE7);
	BackGround::GetInstance()->anim->SetFrameDelay(1);
	BackGround::GetInstance()->anim->SetLoop(false);
	SkyBox::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
}

void IntroScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void IntroScene::Update()
{
	if (InputManager::GetKeyDown(VK_SPACE))
	{
		SceneManager::LoadScene<TitleScene>();
	}

	if (InputManager::GetKeyDown('P'))
	{
		if (MainGame::IsFullScreen())
		{
			MainGame::WindowMode();
		}
		else
		{
			MainGame::FullScreen();
		}
		
	}
}
