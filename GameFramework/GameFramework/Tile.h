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

	int spriteIndex = 0;
	int offsetIndex = 0;
};

