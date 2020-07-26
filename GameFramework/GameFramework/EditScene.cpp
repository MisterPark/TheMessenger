#include "pch.h"
#include "EditScene.h"
#include "TitleScene.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "Label.h"
#include "Player.h"

void EditScene::OnLoaded()
{
	TileManager::SetEditMode(true);
	BackGround::SetStretch(false);
	RenderManager::SetBufferSize(dfEDIT_WIDTH, dfEDIT_HEIGHT);
	BackGround::SetAnimation(SpriteIndex::BLACKSCREEN);
	SkyBox::SetAnimation(SpriteIndex::NINJA_BG_1, SpriteIndex::NINJA_BG_1);

	Player* p = (Player*)ObjectManager::CreateObject(ObjectType::PLAYER);
	p->useGravity = false;
	p->isEnable = false;
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

	if (InputManager::GetKeyDown('O')) // 알파벳 오
	{
		TileManager::ShowTileSet();
	}

	if (InputManager::GetKey(VK_LBUTTON))
	{
		// 여기 수정해야함
		if (TileManager::GetInstance()->isShowTileSet)
		{
			// 타일 선택

			// 타일 선택창 범위 안에서
			if (TileManager::IsMouseOnTileSet())
			{
				// 타일 선택창 범위로부터 타일셋의 타일 인덱스를 계산
				POINT idx = TileManager::GetTileSetIndex();
				// 그 인덱스로 타일을 표시
				TileManager::SelectTileFromTileSet(idx);
			}
			else
			{
				// 타일 삽입
				POINT pt;
				InputManager::GetTileIndex(&pt);
				int offset = TileManager::GetInstance()->selectedTileIndex;

				TileManager::CreateTile(pt.x, pt.y, offset);
			}
			
		}
		else
		{
			// 타일 삽입
			POINT pt;
			InputManager::GetTileIndex(&pt);
			int offset = TileManager::GetInstance()->selectedTileIndex;

			TileManager::CreateTile(pt.x, pt.y, offset);
		}
		
	}

	if (InputManager::GetKey(VK_RBUTTON))
	{
		// 타일 삭제
		POINT pt;
		InputManager::GetTileIndex(&pt);

		TileManager::DeleteTile(pt.x, pt.y);
	}
	if (InputManager::GetKeyDown('S'))
	{
		TileManager::Save("Stage2_1.dat");
	}
	if (InputManager::GetKeyDown('L'))
	{
		TileManager::Load("Stage2_1.dat");
	}
	
	if (InputManager::GetKeyDown('1'))
	{
		POINT pt;
		InputManager::GetTileIndex(&pt);
		Tile* tile = TileManager::FindTile(pt.x, pt.y);
		if (tile != nullptr)
		{
			tile->option |= dfTILE_OPTION_COLLISION_TOP;
		}
	}
	if (InputManager::GetKeyDown('2'))
	{
		POINT pt;
		InputManager::GetTileIndex(&pt);
		Tile* tile = TileManager::FindTile(pt.x, pt.y);
		if (tile != nullptr)
		{
			tile->option |= dfTILE_OPTION_COLLISION_BOTTOM;
		}
	}
	if (InputManager::GetKeyDown('3'))
	{
		POINT pt;
		InputManager::GetTileIndex(&pt);
		Tile* tile = TileManager::FindTile(pt.x, pt.y);
		if (tile != nullptr)
		{
			tile->option |= dfTILE_OPTION_COLLISION_LEFT;
		}
	}
	if (InputManager::GetKeyDown('4'))
	{
		POINT pt;
		InputManager::GetTileIndex(&pt);
		Tile* tile = TileManager::FindTile(pt.x, pt.y);
		if (tile != nullptr)
		{
			tile->option |= dfTILE_OPTION_COLLISION_RIGHT;
		}
	}
	if (InputManager::GetKeyDown('5'))
	{
		POINT pt;
		InputManager::GetTileIndex(&pt);
		Tile* tile = TileManager::FindTile(pt.x, pt.y);
		if (tile != nullptr)
		{
			tile->option |= dfTILE_OPTION_STICK;
		}
	}
	if (InputManager::GetKeyDown('6'))
	{
		POINT pt;
		InputManager::GetTileIndex(&pt);
		Tile* tile = TileManager::FindTile(pt.x, pt.y);
		if (tile != nullptr)
		{
			tile->option |= dfTILE_OPTION_JUMP_DOWN;
		}
	}
	if (InputManager::GetKeyDown('7'))
	{
		POINT pt;
		InputManager::GetTileIndex(&pt);
		Tile* tile = TileManager::FindTile(pt.x, pt.y);
		if (tile != nullptr)
		{
			tile->option |= dfTILE_OPTION_FALL_DOWN;
		}
	}
	if (InputManager::GetKeyDown('8'))
	{
		POINT pt;
		InputManager::GetTileIndex(&pt);
		Tile* tile = TileManager::FindTile(pt.x, pt.y);
		if (tile != nullptr)
		{
			tile->option |= dfTILE_OPTION_DAMAGE;
		}
	}
	if (InputManager::GetKeyDown('9'))
	{
		POINT pt;
		InputManager::GetTileIndex(&pt);
		Tile* tile = TileManager::FindTile(pt.x, pt.y);
		if (tile != nullptr)
		{
			tile->option |= dfTILE_OPTION_MOVE;
		}
	}
	if (InputManager::GetKeyDown('0')) // 숫자 영
	{
		POINT pt;
		InputManager::GetTileIndex(&pt);
		Tile* tile = TileManager::FindTile(pt.x, pt.y);
		if (tile != nullptr)
		{
			tile->option |= dfTILE_OPTION_DEATH;
		}
	}
	if (InputManager::GetKeyDown(VK_F2))
	{
		TileManager::SetTileSet(SpriteIndex::STAGE1_TILE_SET);
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		TileManager::SetTileSet(SpriteIndex::STAGE2_TILE_SET);
	}
}
