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
	GameObject* p = ObjectManager::CreateObject(ObjectType::PLAYER);
	// 카메라
	Camera::SetTarget(p);
	// 타일
	TileManager::LoadToGameScene();

	// 몬스터
	Monster* m = (Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(300, 250);
	m->SetBackAndForth(400, 150);

	m = (Monster*)ObjectManager::CreateObject(ObjectType::SCURUBU);
	m->SetSpawnPosition(400, 250);

	m = (Monster*)ObjectManager::CreateObject(ObjectType::RUN_KAPPA);
	m->SetSpawnPosition(500, 250);

	m = (Monster*)ObjectManager::CreateObject(ObjectType::BLUE_KAPPA);
	m->SetSpawnPosition(450, 250);
	m->SetTarget(p);

	m = (Monster*)ObjectManager::CreateObject(ObjectType::BLUE_BALL);
	m->SetSpawnPosition(450, 220);
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
}
