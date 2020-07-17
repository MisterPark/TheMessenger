#pragma once
#include "Tile.h"

#define dfEDIT_WIDTH 1280
#define dfEDIT_HEIGHT 720

#define dfTILE_W 20
#define dfTILE_H 20

class TileManager
{
private:
	TileManager();
	~TileManager();

public:
	static TileManager* GetInstance();
	static void Release();

	static void Render();
private:
	static void RenderCrossLine();
	static void RenderMousePosition();
	static void RenderTileSet();
	static void RenderTileSelector();
public:
	static void ShowTileSet();
	static void SetEditMode(bool _isEdit);

public:
	bool isEditMode = false;
	bool isShowTileSet = false;
	RECT tileSetArea;
};

