#include "pch.h"
#include "TitleScene.h"
#include "IntroScene.h"
#include "PlayScene.h"
#include "EditScene.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "SelectBox.h"
#include "Stage2.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::OnLoaded()
{
	//��׶��� ����
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::TITLE_BG);
	SkyBox::SetAnimation(SpriteIndex::NONE,SpriteIndex::NONE);
	ObjectManager::CreateObject(ObjectType::LOGO);
	pSelectBox = (SelectBox*)ObjectManager::CreateObject(ObjectType::SELECT_BOX);
	pSelectBox->AddSelector(L"����", Start);
	pSelectBox->AddSelector(L"�ɼ�", Option);
	pSelectBox->AddSelector(L"��������", End);
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
}

void TitleScene::Start()
{
	//SceneManager::LoadScene<Stage2>();
	SceneManager::LoadScene<PlayScene>();
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
