#pragma once
class TileManager
{
private:
	TileManager();
	~TileManager();

public:
	static TileManager* GetInstance();
	static void Release();
};

