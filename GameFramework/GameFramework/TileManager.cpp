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

	//
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hwnd, &pt);

	POINT idx;
	idx.x = (pt.x + Camera::GetX()) / dfTILE_W;
	idx.y = (pt.y + Camera::GetY()) / dfTILE_H;

	WCHAR wstr[64];
	wsprintf(wstr, L"X:%d Y:%d (%d,%d)", pt.x, pt.y, idx.y, idx.x);
	RenderManager::DrawString(wstr, 100, 0,RGB(254,254,254));
}
