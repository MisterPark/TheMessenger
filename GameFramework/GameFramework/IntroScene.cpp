#include "pch.h"
#include "IntroScene.h"
#include "TitleScene.h"

void IntroScene::OnLoaded()
{
	MainGame::Resume();

	// ��׶��� ����

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
