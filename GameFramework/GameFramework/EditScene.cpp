#include "pch.h"
#include "EditScene.h"
#include "TitleScene.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "Label.h"

void EditScene::OnLoaded()
{
	TileManager::SetEditMode(true);
	BackGround::SetStretch(false);
	RenderManager::SetBufferSize(dfEDIT_WIDTH, dfEDIT_HEIGHT);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::SetAnimation(SpriteIndex::NINJA_BG_1, SpriteIndex::NINJA_BG_1);

	ObjectManager::CreateObject(ObjectType::PLAYER);
	ObjectManager::CreateObject(ObjectType::HUD_BAR);

}

void EditScene::OnUnloaded()
{
	TileManager::SetEditMode(false);
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

	if (InputManager::GetKeyDown('O'))
	{
		TileManager::ShowTileSet();
	}

	if (InputManager::GetKey(VK_LBUTTON))
	{
		// 여기 수정해야함
		if (TileManager::GetInstance()->isShowTileSet)
		{
			// 타일 선택

			// 타일 선택창 범위 밖이면 리턴
			// 타일 선택창 범위로부터 타일셋의 타일 인덱스를 계산
			// 그 인덱스로 타일을 생성
		}
		else
		{
			// 타일 삽입

			// 선택된 인덱스의 타일을 생성
			
			POINT pt;
			InputManager::GetTileIndex(&pt);
			GameObject* tile = ObjectManager::CreateObject(ObjectType::TILE);
			tile->position.x = pt.x * dfTILE_W;
			tile->position.y = pt.y * dfTILE_H;
		}
		
	}
	
	
}
