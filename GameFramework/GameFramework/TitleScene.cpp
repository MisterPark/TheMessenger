#include "pch.h"
#include "TitleScene.h"
#include "IntroScene.h"
#include "PlayScene.h"
#include "BackGround.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::OnLoaded()
{
	//��׶��� ����
	BackGround::SetAnimation(SpriteIndex::GAMEOVER1, SpriteIndex::GAMEOVER2);
	BackGround::GetInstance()->anim->SetLoop(true);
	BackGround::GetInstance()->anim->SetFrameDelay(30);

}

void TitleScene::OnUnloaded()
{
}

void TitleScene::Update()
{
	//TODO: �����̽��� ������ �����մϴ�
	if (InputManager::GetKeyDown(VK_SPACE))
	{
		SceneManager::LoadScene<IntroScene>();
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
