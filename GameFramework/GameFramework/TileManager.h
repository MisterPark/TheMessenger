#pragma once

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
};

