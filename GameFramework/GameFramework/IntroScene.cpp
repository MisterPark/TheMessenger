#include "pch.h"
#include "IntroScene.h"
#include "TitleScene.h"
#include "BackGround.h"

void IntroScene::OnLoaded()
{
	BackGround::SetAnimation(SpriteIndex::INTRO, SpriteIndex::INTRO);
	MainGame::Resume();

	// 백그라운드 변경

}

void IntroScene::OnUnloaded()
{
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
