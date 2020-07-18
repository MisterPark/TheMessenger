#pragma once
#include "GameObject.h"

enum TileType
{
	TILE_1_
};

class Tile : public GameObject
{
public:
	Tile();
	virtual ~Tile();

	// GameObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

	SpriteIndex tileset = SpriteIndex::STAGE1_TILE_SET;
	int offsetIndex = 0;
};

