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
	
	// Ÿ��
	RenderTile();
	// ����
	RenderCrossLine();
	// ��ǥ(Ÿ�� �ε���)
	RenderMousePosition();
	// Ÿ�� ����â
	RenderTileSet();
	// Ÿ�� ���ÿ���
	RenderTileSelector();
	// ���õ� Ÿ�� ǥ��
	RenderSelectedTile();
}

void TileManager::RenderTile()
{
	for (auto iter : pTileManager->tileMap)
	{
		Tile* tile = iter.second;
		Transform pos = tile->GetPositionFromCamera();
		RenderManager::DrawTile(SpriteType::NORMAL, tile->tileset, tile->offsetIndex, pos.x, pos.y);
	}
}

void TileManager::RenderCrossLine()
{
	int w = RenderManager::GetWidth() / dfTILE_W + 1;
	int h = RenderManager::GetHeight() / dfTILE_H + 1;
	int offsetX = Camera::GetX() % dfTILE_W;
	int offsetY = Camera::GetY() % dfTILE_H;

	// ���μ�
	for (int row = 0; row < h; row++)
	{
		int sy = row * dfTILE_H - offsetY;

		if (row % 18 == 0) // ���Ӿ� ȭ�� ũ�⸸ŭ�̸� ( 340 �� ���)
		{
			RenderManager::DrawLine(0, sy, RenderManager::GetWidth(), sy, RGB(200, 0, 0));
		}
		else
		{
			RenderManager::DrawLine(0, sy, RenderManager::GetWidth(), sy);
		}
		
		
	}
	// ���μ�
	for (int col = 0; col < w; col++)
	{
		int sx = col * dfTILE_W - offsetX;

		if (col % 32 == 0) // ���Ӿ� ȭ�� ũ�⸸ŭ�̸� (640 �� ���)
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
	// ��ǥ(Ÿ�� �ε���)
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
	POINT pt; // Ŭ���̾�Ʈ ���� ���콺 ��ġ
	GetCursorPos(&pt);
	ScreenToClient(g_hwnd, &pt);

	// Ÿ�ϼ�â ��ġ
	int offsetX = pt.x - pTileManager->tileSetArea.left;
	int offsetY = pt.y - pTileManager->tileSetArea.top;

	POINT idx; // Ÿ�� �ε��� 
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
