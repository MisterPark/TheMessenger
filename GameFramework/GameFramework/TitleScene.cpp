#include "pch.h"
#include "TitleScene.h"
#include "PlayScene.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::OnLoaded()
{
	MainGame::Resume();
}

void TitleScene::OnUnloaded()
{
}

void TitleScene::Update()
{
	//TODO: �����̽��� ������ �����մϴ�
	if (InputManager::GetKeyDown(VK_SPACE))
	{
		SceneManager::LoadScene<PlayScene>();
	}
}
