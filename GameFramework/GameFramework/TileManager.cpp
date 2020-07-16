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
