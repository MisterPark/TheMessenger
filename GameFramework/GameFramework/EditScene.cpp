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
		// ���� �����ؾ���
		if (TileManager::GetInstance()->isShowTileSet)
		{
			// Ÿ�� ����

			// Ÿ�� ����â ���� �ȿ���
			if (TileManager::IsMouseOnTileSet())
			{
				// Ÿ�� ����â �����κ��� Ÿ�ϼ��� Ÿ�� �ε����� ���
				POINT idx = TileManager::GetTileSetIndex();
				// �� �ε����� Ÿ���� ǥ��
				TileManager::SelectTileFromTileSet(idx);
			}
			else
			{
				// Ÿ�� ����
				POINT pt;
				InputManager::GetTileIndex(&pt);
				int offset = TileManager::GetInstance()->selectedTileIndex;

				TileManager::CreateTile(pt.x, pt.y, SpriteIndex::STAGE1_TILE_SET, offset);
			}
			
		}
		else
		{
			// Ÿ�� ����
			POINT pt;
			InputManager::GetTileIndex(&pt);
			int offset = TileManager::GetInstance()->selectedTileIndex;

			TileManager::CreateTile(pt.x, pt.y, SpriteIndex::STAGE1_TILE_SET, offset);
		}
		
	}

	if (InputManager::GetKey(VK_RBUTTON))
	{
		// Ÿ�� ����
		POINT pt;
		InputManager::GetTileIndex(&pt);

		TileManager::DeleteTile(pt.x, pt.y);
	}
	
}
