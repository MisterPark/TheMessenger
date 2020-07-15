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
	//��׶��� ����
	BackGround::SetAnimation(SpriteIndex::TITLE_BG, SpriteIndex::TITLE_BG);
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
