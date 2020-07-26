#include "pch.h"
#include "Stage2.h"
#include "PlayScene.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "SkyBox2.h"
#include "IntroScene.h"
#include "TitleScene.h"
#include "GameObject.h"
#include "Monster.h"
#include "Character.h"

void Stage2::OnLoaded()
{
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::GetInstance()->SetPosition(0, 0);
	SkyBox::SetAnimation(SpriteIndex::STAGE2_BG1, SpriteIndex::STAGE2_BG1);
	SkyBox2::SetAnimation(SpriteIndex::STAGE2_BG2, SpriteIndex::STAGE2_BG2);
	// 오브젝트
	ObjectManager::CreateObject(ObjectType::HUD_BAR);
	player = ObjectManager::CreateObject(ObjectType::PLAYER);
	player->position = { 60,280 };
	player->isEnable = true;
	player->isVisible = true;
	dynamic_cast<Character*>(player)->gravityCount = 0;
	// 카메라
	Camera::SetTarget(player);
	Camera::SetRangeX(0, 640 * 2);
	// 타일
	TileManager::LoadToGameScene("Stage2.dat");
	//TileManager::LoadToGameSceneBack("Stage2_Back.dat");

	// 몬스터
	Monster* m =(Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(640 * 3 - 320, 300);

}

void Stage2::OnUnloaded()
{
	SkyBox2::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	// 카메라 타겟 해제
	Camera::SetTarget(nullptr);
	Camera::SetPosition(0, 0);

	ObjectManager::DestroyAll();
}

void Stage2::Update()
{
	if (player->position.x > 640 * 3 - 20)
	{
		SceneManager::LoadScene<Stage2_1>();
	}

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
//===================================================
void Stage2_1::OnLoaded()
{
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::GetInstance()->SetPosition(0, 0);
	SkyBox::SetAnimation(SpriteIndex::STAGE2_BG1, SpriteIndex::STAGE2_BG1);
	SkyBox2::SetAnimation(SpriteIndex::STAGE2_BG2, SpriteIndex::STAGE2_BG2);
	// 오브젝트
	ObjectManager::CreateObject(ObjectType::HUD_BAR);
	player = ObjectManager::CreateObject(ObjectType::PLAYER);
	player->position = { 60,290 };
	player->isEnable = true;
	player->isVisible = true;
	// 카메라
	Camera::SetTarget(player);
	Camera::SetRangeX(0, 640 * 4);
	// 타일
	TileManager::LoadToGameScene("Stage2_1.dat");

	// 몬스터
	Monster* m = (Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(11 * 20, 9 * 20);
	m = (Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(24 * 20, 9 * 20);
	m = (Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(68 * 20, 13 * 20);
	m = (Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(83 * 20, 10 * 20);
	m = (Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(105 * 20, 15 * 20);
	m = (Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(147 * 20, 12 * 20);

	m = (Monster*)ObjectManager::CreateObject(ObjectType::RANGED_KAPPA);
	m->SetSpawnPosition(47 * 20, 11 * 20);
	m->SetTarget(player);
	m = (Monster*)ObjectManager::CreateObject(ObjectType::RANGED_KAPPA);
	m->SetSpawnPosition(76 * 20, 11 * 20);
	m->SetTarget(player);
	m = (Monster*)ObjectManager::CreateObject(ObjectType::RANGED_KAPPA);
	m->SetSpawnPosition(122 * 20, 11 * 20);
	m->SetTarget(player);

}

void Stage2_1::OnUnloaded()
{
	SkyBox2::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	// 카메라 타겟 해제
	Camera::SetTarget(nullptr);
	Camera::SetPosition(0, 0);

	ObjectManager::DestroyAll();
}

void Stage2_1::Update()
{
	if (player->position.x > 640 * 5 - 20)
	{
		SceneManager::LoadScene<Stage2_2>();
	}

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
//=================================================
void Stage2_2::OnLoaded()
{
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::GetInstance()->SetPosition(0, 0);
	SkyBox::SetAnimation(SpriteIndex::STAGE2_BG1, SpriteIndex::STAGE2_BG1);
	SkyBox2::SetAnimation(SpriteIndex::STAGE2_BG2, SpriteIndex::STAGE2_BG2);
	// 오브젝트
	ObjectManager::CreateObject(ObjectType::HUD_BAR);
	player = ObjectManager::CreateObject(ObjectType::PLAYER);
	player->position = { 40,100 };
	player->isEnable = true;
	player->isVisible = true;
	dynamic_cast<Character*>(player)->gravityCount = 0;
	// 카메라
	Camera::SetTarget(player);
	Camera::SetRangeX(0,0);
	Camera::SetRangeY(0, 320);
	// 타일
	TileManager::LoadToGameScene("Stage2_2.dat");
}

void Stage2_2::OnUnloaded()
{
	SkyBox2::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	Camera::SetTarget(nullptr);
	Camera::SetPosition(0, 0);
	ObjectManager::DestroyAll();
}

void Stage2_2::Update()
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
//=================================================

void Stage2_3::OnLoaded()
{
}

void Stage2_3::OnUnloaded()
{
	SkyBox2::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	Camera::SetTarget(nullptr);
	Camera::SetPosition(0, 0);
	ObjectManager::DestroyAll();
}

void Stage2_3::Update()
{
}
//=================================================

void Stage2_4::OnLoaded()
{
}

void Stage2_4::OnUnloaded()
{
	SkyBox2::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	Camera::SetTarget(nullptr);
	Camera::SetPosition(0, 0);
	ObjectManager::DestroyAll();
}

void Stage2_4::Update()
{
}
//=================================================

void Stage2_5::OnLoaded()
{
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::GetInstance()->SetPosition(0, 0);
	SkyBox::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	SkyBox2::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	// 오브젝트
	ObjectManager::CreateObject(ObjectType::HUD_BAR);
	player = ObjectManager::CreateObject(ObjectType::PLAYER);
	player->position = { 10,270 };
	player->isEnable = true;
	player->isVisible = true;
	dynamic_cast<Character*>(player)->gravityCount = 0;
	// 카메라
	Camera::SetTarget(player);
	Camera::SetRangeX(0, 0);
	// 타일
	TileManager::LoadToGameScene("Stage2_5.dat");

	GameObject* boss = ObjectManager::CreateObject(ObjectType::LEAF_MONSTER);
	boss->SetPosition(500, 270);
	boss->SetTarget(player);
}

void Stage2_5::OnUnloaded()
{
	SkyBox2::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	Camera::SetTarget(nullptr);
	Camera::SetPosition(0, 0);
	ObjectManager::DestroyAll();
}

void Stage2_5::Update()
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
