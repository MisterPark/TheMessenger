#include "pch.h"
#include "PlayScene.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "IntroScene.h"
#include "TitleScene.h"
#include "GameObject.h"
#include "Monster.h"

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
	
	// 오브젝트
	ObjectManager::CreateObject(ObjectType::HUD_BAR);
	player = ObjectManager::CreateObject(ObjectType::PLAYER);
	// 카메라
	Camera::SetTarget(player);
	// 타일
	TileManager::LoadToGameScene("TileData.dat");

	// 몬스터
	
}

void PlayScene::OnUnloaded()
{
	// 카메라 타겟 해제
	Camera::SetTarget(nullptr);
	Camera::SetPosition(0, 0);

    ObjectManager::DestroyAll();
}

void PlayScene::Update()
{
	if (InputManager::GetKeyDown(VK_ESCAPE))
	{
		// TODO : 나중에 팝업창 띄우기
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

	if (InputManager::GetKeyDown('1'))
	{
		Monster* m = (Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
		m->SetSpawnPosition(300, 250);
		m->SetBackAndForth(400, 150);
	}
	if (InputManager::GetKeyDown('2'))
	{
		Monster* m = (Monster*)ObjectManager::CreateObject(ObjectType::SCURUBU);
		m->SetSpawnPosition(400, 250);
	}
	if (InputManager::GetKeyDown('3'))
	{
		Monster* m = (Monster*)ObjectManager::CreateObject(ObjectType::RUN_KAPPA);
		m->SetSpawnPosition(500, 250);
	}
	if (InputManager::GetKeyDown('4'))
	{
		
		Monster* m = (Monster*)ObjectManager::CreateObject(ObjectType::BLUE_KAPPA);
		m->SetSpawnPosition(450, 250);
		m->SetTarget(player);
	}
	if (InputManager::GetKeyDown('5'))
	{
		Monster* m = (Monster*)ObjectManager::CreateObject(ObjectType::RANGED_KAPPA);
		m->SetSpawnPosition(450, 250);
		m->SetTarget(player);
	}
}
