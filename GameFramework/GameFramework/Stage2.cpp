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
#include "GameOverScene.h"

void Stage2::OnLoaded()
{
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::GetInstance()->SetPosition(0, 0);
	SkyBox::SetAnimation(SpriteIndex::STAGE2_BG1, SpriteIndex::STAGE2_BG1);
	SkyBox2::SetAnimation(SpriteIndex::STAGE2_BG2, SpriteIndex::STAGE2_BG2);
	// BGM
	SoundManager::GetInstance()->StopAll();
	SoundManager::GetInstance()->PlayBGM((WCHAR*)L"bgm.mp3");
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

	GameObject* item;

	for (int i = 0; i < 20; i++)
	{
		item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
		item->SetPosition(670+(i * (640/20)), 250);
	}

	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(240, 170);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(240, 190);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(240, 210);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(240, 230);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(240, 250);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(220, 270);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(200, 270);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(180, 250);

	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(280, 170);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(280, 190);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(280, 210);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(280, 230);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(280, 250);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(300, 270);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(320, 270);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(340, 170);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(340, 190);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(340, 210);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(340, 230);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(340, 250);

	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(380, 190);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(380, 210);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(380, 250);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(400, 170);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(400, 210);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(400, 270);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(420, 170);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(420, 210);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(420, 270);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(440, 190);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(440, 230);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(440, 250);

	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(480, 170);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(480, 270);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(500, 170);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(500, 190);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(500, 210);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(500, 230);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(500, 250);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(500, 270);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(520, 170);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(520, 270);

	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(560, 170);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(560, 190);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(560, 210);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(560, 230);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(560, 250);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(560, 270);

	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(580, 190);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(580, 210);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(600, 230);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(600, 250);

	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(620, 170);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(620, 190);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(620, 210);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(620, 230);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(620, 250);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(620, 270);
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
	if (player->hp <= 0)
	{
		player->hp = 5;
		SceneManager::LoadScene<Stage2>();
	}
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
	if (player->hp <= 0)
	{
		player->hp = 5;
		SceneManager::LoadScene<Stage2_1>();
	}
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

	GameObject* item;
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(6*20, 6 * 20);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(7 * 20, 5 * 20);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(8 * 20, 4 * 20);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(9 * 20, 4 * 20);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(10 * 20, 4 * 20);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(11 * 20, 5 * 20);
	item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
	item->SetPosition(12 * 20, 6 * 20);

	for (int i = 9; i < 27; i++)
	{
		item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
		item->SetPosition(280, i * 20);
	}

	for (int i = 9; i < 27; i++)
	{
		item = ObjectManager::CreateObject(ObjectType::ITEM_CRYSTAL);
		item->SetPosition(430, i * 20);
	}

	item = ObjectManager::CreateObject(ObjectType::ITEM_HP);
	item->SetPosition(172, 591);

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
	if (player->hp <= 0)
	{
		player->hp = 5;
		SceneManager::LoadScene<Stage2_2>();
	}
	if (player->position.x > 640 * 1 - 20)
	{
		SceneManager::LoadScene<Stage2_3>();
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

void Stage2_3::OnLoaded()
{
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::GetInstance()->SetPosition(0, 0);
	SkyBox::SetAnimation(SpriteIndex::STAGE2_BG1, SpriteIndex::STAGE2_BG1);
	SkyBox2::SetAnimation(SpriteIndex::STAGE2_BG2, SpriteIndex::STAGE2_BG2);
	// 오브젝트
	ObjectManager::CreateObject(ObjectType::HUD_BAR);
	player = ObjectManager::CreateObject(ObjectType::PLAYER);
	player->position = { 30,280 };
	player->isEnable = true;
	player->isVisible = true;
	dynamic_cast<Character*>(player)->gravityCount = 0;
	// 카메라
	Camera::SetTarget(player);
	Camera::SetRangeX(0, 640 * 1);
	Camera::SetRangeY(0, 0);
	// 타일
	TileManager::LoadToGameScene("Stage2_3.dat");

	// 몬스터
	Monster* m = (Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(140, 290);
	m->SetTarget(player);
	m = (Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(450, 200);
	m->SetTarget(player);
	m = (Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(840, 284);
	m->SetTarget(player);

	m = (Monster*)ObjectManager::CreateObject(ObjectType::SCURUBU);
	m->SetSpawnPosition(240,290);
	m->SetTarget(player);

	m = (Monster*)ObjectManager::CreateObject(ObjectType::RANGED_KAPPA);
	m->SetSpawnPosition(374,260);
	m->SetTarget(player);
	m = (Monster*)ObjectManager::CreateObject(ObjectType::RANGED_KAPPA);
	m->SetSpawnPosition(613,200);
	m->SetTarget(player);

	m = (Monster*)ObjectManager::CreateObject(ObjectType::BLUE_KAPPA);
	m->SetSpawnPosition(670,100);
	m->SetTarget(player);
	m = (Monster*)ObjectManager::CreateObject(ObjectType::BLUE_KAPPA);
	m->SetSpawnPosition(1035,124);
	m->SetTarget(player);

	m = (Monster*)ObjectManager::CreateObject(ObjectType::RUN_KAPPA);
	m->SetSpawnPosition(590, 200);
	m->SetTarget(player);
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
	if (player->hp <= 0)
	{
		player->hp = 5;
		SceneManager::LoadScene<Stage2_3>();
	}
	if (player->position.x > 640 * 2 - 20)
	{
		SceneManager::LoadScene<Stage2_5>();
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


void Stage2_5::OnLoaded()
{
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::GetInstance()->SetPosition(0, 0);
	SkyBox::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	SkyBox2::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	// BGM
	SoundManager::GetInstance()->StopAll();
	SoundManager::GetInstance()->PlayBGM((WCHAR*)L"bossBGM.mp3");
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
	if (player->hp <= 0)
	{
		player->hp = 10;
		SceneManager::LoadScene<Stage2_3>();
	}
	if (player->position.x > 640 * 1 - 20)
	{
		SceneManager::LoadScene<GameOverScene>();
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
