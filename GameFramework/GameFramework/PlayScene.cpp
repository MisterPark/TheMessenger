#include "pch.h"
#include "PlayScene.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "IntroScene.h"

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::OnLoaded()
{
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::SetAnimation(SpriteIndex::NINJA_BG_1, SpriteIndex::NINJA_BG_1);
	
	ObjectManager::CreateObject(ObjectType::HUD_BAR);
	ObjectManager::CreateObject(ObjectType::PLAYER);

	TileManager::LoadToGameScene();
}

void PlayScene::OnUnloaded()
{
    ObjectManager::DestroyAll();
}

void PlayScene::Update()
{
	//if (InputManager::GetKeyDown(VK_SPACE))
	//{
	//	SceneManager::LoadScene<IntroScene>();
	//}
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
	if (InputManager::GetKeyDown('R'))
	{
		if (ObjectManager::IsVisibleCollider())
		{
			ObjectManager::SetVisibleCollider(false);
		}
		else
		{
			ObjectManager::SetVisibleCollider(true);
		}
		
	}
}
