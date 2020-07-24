#pragma once
#include "Tile.h"
#include "BackTile.h"

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
	static void RenderTile();
	static void RenderCrossLine();
	static void RenderMousePosition();
	static void RenderTileSet();
	static void RenderTileSelector();
	static void RenderSelectedTile();
public:
	static void ShowTileSet();
	static void SetEditMode(bool _isEdit);
	static RECT GetTileSetArea();
	static bool IsMouseOnTileSet();
	static POINT GetTileSetIndex();
	static void SelectTileFromTileSet(POINT pt);
	static void SetTileSet(SpriteIndex _tileset);

	static void CreateTile(int indexX, int indexY, int offset);
	static void CreateTile(int indexX, int indexY,SpriteIndex tileSet, int offset, DWORD option, Point movePoint);
	static void DeleteTile(int indexX, int indexY);
	static void DeleteAllTiles();
	static Tile* FindTile(int indexX, int indexY);

	static void Save(const char* _fileName);
	static void Load(const char* _fileName);
	static void LoadToGameScene(const char* _fileName);
	static void LoadToGameSceneBack(const char* _fileName);

public:
	
	int selectedTileIndex = 0;
	SpriteIndex curTileSet = SpriteIndex::STAGE1_TILE_SET;
	bool isEditMode = false;
	bool isShowTileSet = false;
	RECT tileSetArea;
	map<Point, Tile*> tileMap;
};

