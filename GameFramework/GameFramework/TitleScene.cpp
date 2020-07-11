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
	//TODO: 스페이스를 누르면 시작합니다
	if (InputManager::GetKeyDown(VK_SPACE))
	{
		SceneManager::LoadScene<PlayScene>();
	}
}
