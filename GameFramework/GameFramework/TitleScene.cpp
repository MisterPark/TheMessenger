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
	pSelectBox->AddSelector(L"����");
	pSelectBox->AddSelector(L"�ɼ�");
	pSelectBox->AddSelector(L"��������");
}

void TitleScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TitleScene::Update()
{
	//TODO: �����̽��� ������ �����մϴ�
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
