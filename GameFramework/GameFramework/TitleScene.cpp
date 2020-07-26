#include "pch.h"
#include "TitleScene.h"
#include "IntroScene.h"
#include "PlayScene.h"
#include "EditScene.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "SelectBox.h"
#include "Stage2.h"
#include "Player.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::OnLoaded()
{
	//백그라운드 변경
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::TITLE_BG);
	SkyBox::SetAnimation(SpriteIndex::NONE,SpriteIndex::NONE);
	ObjectManager::CreateObject(ObjectType::LOGO);

	Player::GetInstance()->isVisible = false;
	Player::GetInstance()->isEnable = false;

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

	if (InputManager::GetKeyDown('E'))
	{
		EditMode();
	}

	if (InputManager::GetKeyDown('T'))
	{
		SceneManager::LoadScene<PlayScene>();
	}
}

void TitleScene::Start()
{
	SceneManager::LoadScene<Stage2>();
}

void TitleScene::Option()
{
}

void TitleScene::EditMode()
{
	SceneManager::LoadScene<EditScene>();
}

void TitleScene::End()
{
	MainGame::Shutdown();
}
