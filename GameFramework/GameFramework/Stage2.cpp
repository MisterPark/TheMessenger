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

void Stage2::OnLoaded()
{
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::GetInstance()->SetPosition(0, 0);
	SkyBox::SetAnimation(SpriteIndex::STAGE2_BG1, SpriteIndex::STAGE2_BG1);
	SkyBox2::SetAnimation(SpriteIndex::STAGE2_BG2, SpriteIndex::STAGE2_BG2);
	// ������Ʈ
	ObjectManager::CreateObject(ObjectType::HUD_BAR);
	player = ObjectManager::CreateObject(ObjectType::PLAYER);
	player->position = { 60,300 };
	// ī�޶�
	Camera::SetTarget(player);
	Camera::SetRangeX(0, 640 * 2);
	// Ÿ��
	TileManager::LoadToGameScene("Stage2.dat");
	//TileManager::LoadToGameSceneBack("Stage2_Back.dat");

	// ����
	Monster* m =(Monster*)ObjectManager::CreateObject(ObjectType::GREEN_KAPPA);
	m->SetSpawnPosition(640 * 3 - 320, 300);

}

void Stage2::OnUnloaded()
{
	SkyBox2::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	// ī�޶� Ÿ�� ����
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
		// TODO : ���߿� �˾�â ����
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
	// ������Ʈ
	ObjectManager::CreateObject(ObjectType::HUD_BAR);
	player = ObjectManager::CreateObject(ObjectType::PLAYER);
	// ī�޶�
	Camera::SetTarget(player);
	Camera::SetRangeX(0, 640 * 4);
	// Ÿ��
	TileManager::LoadToGameScene("Stage2_1.dat");
}

void Stage2_1::OnUnloaded()
{
	SkyBox2::SetAnimation(SpriteIndex::NONE, SpriteIndex::NONE);
	// ī�޶� Ÿ�� ����
	Camera::SetTarget(nullptr);
	Camera::SetPosition(0, 0);

	ObjectManager::DestroyAll();
}

void Stage2_1::Update()
{
	if (InputManager::GetKeyDown(VK_ESCAPE))
	{
		// TODO : ���߿� �˾�â ����
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
}

void Stage2_2::OnUnloaded()
{
}

void Stage2_2::Update()
{
}
