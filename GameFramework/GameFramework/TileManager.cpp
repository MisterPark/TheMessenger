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
	delete pTileManager;
}

void TileManager::Render()
{
	if (pTileManager->isEditMode == false) return;
	// 격자
	RenderCrossLine();
	// 좌표(타일 인덱스)
	RenderMousePosition();
	// 타일 선택창
	RenderTileSet();
	// 타일 선택영역
	RenderTileSelector();
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
		RenderManager::DrawLine(0, sy, RenderManager::GetWidth(), sy);
	}
	// 세로선
	for (int col = 0; col < w; col++)
	{
		int sx = col * dfTILE_W - offsetX;
		RenderManager::DrawLine(sx, 0, sx, RenderManager::GetHeight());
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
	RenderManager::DrawSprite(SpriteType::NORMAL, SpriteIndex::STAGE1_TILE_SET, tileSetX + Camera::GetX(), tileSetY + Camera::GetY());

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

void TileManager::ShowTileSet()
{
	pTileManager->isShowTileSet = !pTileManager->isShowTileSet;

}

void TileManager::SetEditMode(bool _isEdit)
{
	pTileManager->isEditMode = _isEdit;
}
