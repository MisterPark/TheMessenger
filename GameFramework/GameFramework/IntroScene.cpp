#include "pch.h"
#include "IntroScene.h"
#include "TitleScene.h"

void IntroScene::OnLoaded()
{
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
	if (InputManager::GetKeyDown(VK_RETURN))
	{
		MainGame::GetInstance()->PullScreen();
	}
}
