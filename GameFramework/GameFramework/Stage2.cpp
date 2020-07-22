#include "pch.h"
#include "Stage2.h"
#include "PlayScene.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "IntroScene.h"
#include "TitleScene.h"
#include "GameObject.h"
#include "Monster.h"

void Stage2::OnLoaded()
{
	BackGround::SetStretch(true);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::SetAnimation(SpriteIndex::NINJA_BG_1, SpriteIndex::NINJA_BG_1);

	// ������Ʈ
	ObjectManager::CreateObject(ObjectType::HUD_BAR);
	player = ObjectManager::CreateObject(ObjectType::PLAYER);
	// ī�޶�
	Camera::SetTarget(player);
	// Ÿ��
	TileManager::LoadToGameScene("Stage2.dat");

	// ����
}

void Stage2::OnUnloaded()
{
	// ī�޶� Ÿ�� ����
	Camera::SetTarget(nullptr);
	Camera::SetPosition(0, 0);

	ObjectManager::DestroyAll();
}

void Stage2::Update()
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
