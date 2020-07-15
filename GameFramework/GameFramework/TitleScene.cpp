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
	pSelectBox->AddSelector(L"시작", Start);
	pSelectBox->AddSelector(L"옵션", Option);
	pSelectBox->AddSelector(L"게임종료", End);
}

void TitleScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TitleScene::Update()
{

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

void TitleScene::Start()
{
	SceneManager::LoadScene<PlayScene>();
}

void TitleScene::Option()
{
}

void TitleScene::End()
{
	MainGame::Shutdown();
}
