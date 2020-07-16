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
	int w = RenderManager::GetWidth() / dfTILE_W;
	int h = RenderManager::GetHeight() / dfTILE_H;
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			
		}
	}
}
