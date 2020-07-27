#include "pch.h"
#include "GameOverScene.h"
#include "TitleScene.h"
#include "IntroScene.h"
#include "PlayScene.h"
#include "EditScene.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "Player.h"

void GameOverScene::OnLoaded()
{
	//백그라운드 변경
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::GAMEOVER1,SpriteIndex::GAMEOVER2);
	SkyBox::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);

	SoundManager::GetInstance()->StopAll();

	Player::GetInstance()->isVisible = false;
	Player::GetInstance()->isEnable = false;

	ObjectManager::CreateObject(ObjectType::ENDING_CREDIT);
	
}

void GameOverScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void GameOverScene::Update()
{

	if (InputManager::GetKeyDown(VK_ESCAPE))
	{
		SceneManager::LoadScene<TitleScene>();
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
