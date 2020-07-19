#include "pch.h"
#include "TileManager.h"

TileManager* pTileManager = nullptr;

TileManager::TileManager()
{
}

TileManager::~TileManager()
{
}

TileManager * TileManager::GetInstance()
{
	if (pTileManager == nullptr)
	{
		pTileManager = new TileManager;
	}
	return pTileManager;
}

void TileManager::Release()
{
	DeleteAllTiles();
	delete pTileManager;
}

void TileManager::Render()
{
	if (pTileManager->isEditMode == false) return;
	
	// 타일
	RenderTile();
	// 격자
	RenderCrossLine();
	// 좌표(타일 인덱스)
	RenderMousePosition();
	// 타일 선택창
	RenderTileSet();
	// 타일 선택영역
	RenderTileSelector();
	// 선택된 타일 표시
	RenderSelectedTile();
}

void TileManager::RenderTile()
{
	for (auto iter : pTileManager->tileMap)
	{
		Tile* tile = iter.second;
		Transform pos = tile->GetPositionFromCamera();
		RenderManager::DrawTile(SpriteType::NORMAL, tile->tileset, tile->offsetIndex, pos.x, pos.y);

		RECT rt = { pos.x + 1,pos.y + 1,pos.x + dfTILE_W - 1,pos.y + dfTILE_H - 1 };

		if (tile->option & dfTILE_OPTION_COLLISION_TOP)
		{
			RenderManager::DrawLine(rt.left, rt.top, rt.right, rt.top, RGB(255, 0, 0));
		}
		if (tile->option & dfTILE_OPTION_COLLISION_BOTTOM)
		{
			RenderManager::DrawLine(rt.left, rt.bottom, rt.right, rt.bottom, RGB(255, 0, 0));
		}
		if (tile->option & dfTILE_OPTION_COLLISION_LEFT)
		{
			RenderManager::DrawLine(rt.left, rt.top, rt.left, rt.bottom, RGB(255, 0, 0));
		}
		if (tile->option & dfTILE_OPTION_COLLISION_RIGHT)
		{
			RenderManager::DrawLine(rt.right, rt.top, rt.right, rt.bottom, RGB(255, 0, 0));
		}
		if (tile->option & dfTILE_OPTION_STICK)
		{

		}

	}
}

void TileManager::RenderCrossLine()
{
	int w = RenderManager::GetWidth() / dfTILE_W + 1;
	int h = RenderManager::GetHeight() / dfTILE_H + 1;
	int offsetX = Camera::GetX() % dfTILE_W;
	int offsetY = Camera::GetY() % dfTILE_H;

	// 가로선
	for (int row = 0; row < h; row++)
	{
		int sy = row * dfTILE_H - offsetY;

		if (row % 18 == 0) // 게임씬 화면 크기만큼이면 ( 340 의 배수)
		{
			RenderManager::DrawLine(0, sy, RenderManager::GetWidth(), sy, RGB(200, 0, 0));
		}
		else
		{
			RenderManager::DrawLine(0, sy, RenderManager::GetWidth(), sy);
		}
		
		
	}
	// 세로선
	for (int col = 0; col < w; col++)
	{
		int sx = col * dfTILE_W - offsetX;

		if (col % 32 == 0) // 게임씬 화면 크기만큼이면 (640 의 배수)
		{
			RenderManager::DrawLine(sx, 0, sx, RenderManager::GetHeight(), RGB(200, 0, 0));
		}
		else
		{
			RenderManager::DrawLine(sx, 0, sx, RenderManager::GetHeight());
		}
	}
}

void TileManager::RenderMousePosition()
{
	// 좌표(타일 인덱스)
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hwnd, &pt);

	POINT idx;
	idx.x = (pt.x + Camera::GetX()) / dfTILE_W;
	idx.y = (pt.y + Camera::GetY()) / dfTILE_H;

	WCHAR wstr[64];
	wsprintf(wstr, L"X:%d Y:%d (%d,%d) CX:%d CY:%d", pt.x, pt.y, idx.y, idx.x,Camera::GetX(),Camera::GetY());
	RenderManager::DrawString(wstr, 100, 0, RGB(254, 254, 254));
}

void TileManager::RenderTileSet()
{
	if (!pTileManager->isShowTileSet) return;

	int tileSetWidth;
	int tileSetHeight;
	RenderManager::GetSpriteSize(SpriteIndex::STAGE1_TILE_SET, &tileSetWidth, &tileSetHeight);
	int tileSetX = dfEDIT_WIDTH - tileSetWidth;
	int tileSetY = dfEDIT_HEIGHT - tileSetHeight;

	pTileManager->tileSetArea.left = tileSetX;
	pTileManager->tileSetArea.top = tileSetY;
	pTileManager->tileSetArea.right = tileSetX + tileSetWidth;
	pTileManager->tileSetArea.bottom = tileSetY + tileSetHeight;
	RenderManager::DrawRect(pTileManager->tileSetArea, RGB(255, 0, 255));
	RenderManager::DrawSprite(SpriteType::NORMAL, SpriteIndex::STAGE1_TILE_SET, tileSetX, tileSetY);

}

void TileManager::RenderTileSelector()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hwnd, &pt);

	if (pTileManager->isShowTileSet)
	{
		if (pTileManager->tileSetArea.left > pt.x) return;
		if (pTileManager->tileSetArea.right < pt.x) return;
		if (pTileManager->tileSetArea.top > pt.y) return;
		if (pTileManager->tileSetArea.bottom < pt.y) return;

		POINT idx;
		idx.x = (pt.x) / dfTILE_W;
		idx.y = (pt.y) / dfTILE_H;

		RECT rect;
		rect.left = idx.x * dfTILE_W;
		rect.top = idx.y * dfTILE_H;
		rect.right = rect.left + dfTILE_W;
		rect.bottom = rect.top + dfTILE_H;

		RenderManager::DrawSimpleCollider(rect, RGB(0, 255, 0));
	}
	else
	{
		POINT idx;
		idx.x = (pt.x + (Camera::GetX() % dfTILE_W)) / dfTILE_W;
		idx.y = (pt.y + (Camera::GetY() % dfTILE_H)) / dfTILE_H;

		int offsetX = Camera::GetX() % dfTILE_W;
		int offsetY = Camera::GetY() % dfTILE_H;

		RECT rect;
		rect.left = idx.x * dfTILE_W - offsetX;
		rect.top = idx.y * dfTILE_H - offsetY;
		rect.right = rect.left + dfTILE_W;
		rect.bottom = rect.top + dfTILE_H;

		RenderManager::DrawSimpleCollider(rect, RGB(0, 255, 0));
	}
}

void TileManager::RenderSelectedTile()
{
	RenderManager::DrawTile(SpriteType::NORMAL, SpriteIndex::STAGE1_TILE_SET, pTileManager->selectedTileIndex, 600, 0);
}

void TileManager::ShowTileSet()
{
	pTileManager->isShowTileSet = !pTileManager->isShowTileSet;

}

void TileManager::SetEditMode(bool _isEdit)
{
	pTileManager->isEditMode = _isEdit;
}

RECT TileManager::GetTileSetArea()
{
	return pTileManager->tileSetArea;
}

bool TileManager::IsMouseOnTileSet()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hwnd, &pt);

	if (pTileManager->tileSetArea.left > pt.x) return false;
	if (pTileManager->tileSetArea.right < pt.x) return false;
	if (pTileManager->tileSetArea.top > pt.y) return false;
	if (pTileManager->tileSetArea.bottom < pt.y) return false;

	return true;
}

POINT TileManager::GetTileSetIndex()
{
	POINT pt; // 클라이언트 기준 마우스 위치
	GetCursorPos(&pt);
	ScreenToClient(g_hwnd, &pt);

	// 타일셋창 위치
	int offsetX = pt.x - pTileManager->tileSetArea.left;
	int offsetY = pt.y - pTileManager->tileSetArea.top;

	POINT idx; // 타일 인덱스 
	idx.x = offsetX / dfTILE_W;
	idx.y = offsetY / dfTILE_H;

	

	return idx;
}

void TileManager::SelectTileFromTileSet(POINT pt)
{
	int w, h;
	RenderManager::GetSpriteSize(SpriteIndex::STAGE1_TILE_SET, &w, &h);
	int colCount = w / dfTILE_W;

	pTileManager->selectedTileIndex = colCount * pt.y + pt.x;
}

void TileManager::CreateTile(int indexX, int indexY, SpriteIndex tileset, int offset)
{
	auto target = pTileManager->tileMap.find(Point(indexX, indexY));

	if (target != pTileManager->tileMap.end())
	{
		return;
	}

	Tile* tile = new Tile;
	tile->position.x = indexX * dfTILE_W;
	tile->position.y = indexY * dfTILE_H;
	tile->tileset = tileset;
	tile->offsetIndex = offset;

	pTileManager->tileMap.insert(make_pair(Point(indexX, indexY), tile));
}

void TileManager::CreateTile(int indexX, int indexY, SpriteIndex tileset, int offset, DWORD option, Point movePoint)
{
	auto target = pTileManager->tileMap.find(Point(indexX, indexY));

	if (target != pTileManager->tileMap.end())
	{
		return;
	}

	Tile* tile = new Tile;
	tile->position.x = indexX * dfTILE_W;
	tile->position.y = indexY * dfTILE_H;
	tile->tileset = tileset;
	tile->offsetIndex = offset;
	tile->option = option;
	tile->ePoint = movePoint;
	tile->sPoint = { indexX,indexY };

	pTileManager->tileMap.insert(make_pair(Point(indexX, indexY), tile));
}

void TileManager::DeleteTile(int indexX, int indexY)
{
	auto target = pTileManager->tileMap.find(Point(indexX, indexY));
	
	if (target != pTileManager->tileMap.end())
	{
		delete target->second;
		pTileManager->tileMap.erase(target);
	}
	
}

void TileManager::DeleteAllTiles()
{
	auto iter = pTileManager->tileMap.begin();
	auto end = pTileManager->tileMap.end();
	for (; iter != end;)
	{
		delete iter->second;
		iter = pTileManager->tileMap.erase(iter);
	}
}

Tile* TileManager::FindTile(int indexX, int indexY)
{
	auto iter = pTileManager->tileMap.find(Point(indexX, indexY));
	if (iter != pTileManager->tileMap.end())
	{
		return iter->second;
	}
	return nullptr;
}

void TileManager::Save()
{
	FileManager::MakeDirectory("SaveData");
	FileManager::SetDirectory("SaveData/TileData.dat");
	FileManager::OpenFile("wb");

	// 헤더
	int tileCount = pTileManager->tileMap.size();
	FileManager::WriteFile(&tileCount, sizeof(int), 1);

	// 데이터
	for (auto iter : pTileManager->tileMap)
	{
		Point index = iter.first;
		Tile* tile = iter.second;

		FileManager::WriteFile(&index.x, sizeof(int), 1);
		FileManager::WriteFile(&index.y, sizeof(int), 1);
		FileManager::WriteFile(&tile->tileset, sizeof(SpriteIndex), 1);
		FileManager::WriteFile(&tile->offsetIndex, sizeof(int), 1);
		FileManager::WriteFile(&tile->option, sizeof(DWORD), 1);
		FileManager::WriteFile(&tile->ePoint, sizeof(Point), 1);
	}

	FileManager::CloseFile();
}

void TileManager::Load()
{
	DeleteAllTiles();

	FileManager::MakeDirectory("SaveData");
	FileManager::SetDirectory("SaveData/TileData.dat");
	FileManager::OpenFile("rb");

	// 헤더
	int tileCount;
	FileManager::ReadFile(&tileCount, sizeof(int), 1);

	// 데이터
	for (int i = 0; i < tileCount; i++)
	{
		Point index;
		SpriteIndex tileSet;
		int offsetIndex;
		DWORD option;
		Point movePoint;

		FileManager::ReadFile(&index.x, sizeof(int), 1);
		FileManager::ReadFile(&index.y, sizeof(int), 1);
		FileManager::ReadFile(&tileSet, sizeof(SpriteIndex), 1);
		FileManager::ReadFile(&offsetIndex, sizeof(int), 1);
		FileManager::ReadFile(&option, sizeof(DWORD), 1);
		FileManager::ReadFile(&movePoint, sizeof(Point), 1);

		CreateTile(index.x, index.y, tileSet, offsetIndex, option, movePoint);
	}

	FileManager::CloseFile();
}

void TileManager::LoadToGameScene()
{
	ObjectManager::DestroyAll(ObjectType::TILE);

	FileManager::MakeDirectory("SaveData");
	FileManager::SetDirectory("SaveData/TileData.dat");
	FileManager::OpenFile("rb");

	// 헤더
	int tileCount;
	FileManager::ReadFile(&tileCount, sizeof(int), 1);

	// 데이터
	for (int i = 0; i < tileCount; i++)
	{
		Point index;
		SpriteIndex tileSet;
		int offsetIndex;
		DWORD option;
		Point movePoint;

		FileManager::ReadFile(&index.x, sizeof(int), 1);
		FileManager::ReadFile(&index.y, sizeof(int), 1);
		FileManager::ReadFile(&tileSet, sizeof(SpriteIndex), 1);
		FileManager::ReadFile(&offsetIndex, sizeof(int), 1);
		FileManager::ReadFile(&option, sizeof(DWORD), 1);
		FileManager::ReadFile(&movePoint, sizeof(Point), 1);

		Tile* tile = (Tile*)ObjectManager::CreateObject(ObjectType::TILE);
		tile->position.x = index.x * dfTILE_W;
		tile->position.y = index.y * dfTILE_H;
		tile->tileset = tileSet;
		tile->offsetIndex = offsetIndex;
		tile->option = option;
		tile->ePoint = movePoint;
		tile->sPoint = { index.x,index.y };
	}

	FileManager::CloseFile();
}
