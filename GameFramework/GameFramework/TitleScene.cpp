#include "pch.h"
#include "TitleScene.h"
#include "IntroScene.h"
#include "PlayScene.h"
#include "BackGround.h"
#include "SelectBox.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::OnLoaded()
{
	//백그라운드 변경
	BackGround::SetAnimation(SpriteIndex::TITLE_BG, SpriteIndex::TITLE_BG);
	ObjectManager::CreateObject(ObjectType::LOGO);
	pSelectBox = (SelectBox*)ObjectManager::CreateObject(ObjectType::SELECT_BOX);
	pSelectBox->AddSelector(L"시작");
	pSelectBox->AddSelector(L"옵션");
	pSelectBox->AddSelector(L"게임종료");
}

void TitleScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TitleScene::Update()
{
	//TODO: 스페이스를 누르면 시작합니다
	if (InputManager::GetKeyDown(VK_SPACE))
	{
		SceneManager::LoadScene<PlayScene>();
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
