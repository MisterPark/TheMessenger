#include "pch.h"
#include "EditScene.h"
#include "TitleScene.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "Label.h"

void EditScene::OnLoaded()
{
	BackGround::SetStretch(false);
	RenderManager::SetBufferSize(dfEDIT_WIDTH, dfEDIT_HEIGHT);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::SetAnimation(SpriteIndex::NINJA_BG_1, SpriteIndex::NINJA_BG_1);

	ObjectManager::CreateObject(ObjectType::PLAYER);
	ObjectManager::CreateObject(ObjectType::HUD_BAR);

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

	if (InputManager::GetKey(VK_LBUTTON))
	{
		// 여기서부터 해야함
		POINT pt;
		InputManager::GetTileIndex(&pt);
		GameObject* tile = ObjectManager::CreateObject(ObjectType::TILE);
		tile->position.x = pt.x * dfTILE_W;
		tile->position.y = pt.y * dfTILE_H;
	}
	
	
}
