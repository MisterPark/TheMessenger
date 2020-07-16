#include "pch.h"
#include "EditScene.h"
#include "TitleScene.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "Label.h"

void EditScene::OnLoaded()
{
	BackGround::SetStretch(false);
	RenderManager::SetBufferSize(1280, 720);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::SetAnimation(SpriteIndex::NINJA_BG_1, SpriteIndex::NINJA_BG_1);

	ObjectManager::CreateObject(ObjectType::PLAYER);
	ObjectManager::CreateObject(ObjectType::HUD_BAR);
	label = (Label*)ObjectManager::CreateObject(ObjectType::LABEL);
	label->SetPosition(500, 0);
}

void EditScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void EditScene::Update()
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

	

	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hwnd, &pt);
	WCHAR wstr[64];
	wsprintf(wstr, L"X:%d Y:%d", pt.x, pt.y);
	label->SetText(wstr);

	
}
