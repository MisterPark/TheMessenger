#include "pch.h"
#include "Tile.h"

Tile::Tile()
{
	position = { 0,100 };
}

Tile::~Tile()
{
}

void Tile::Update()
{
}

void Tile::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawTile(SpriteType::NORMAL, tileset, offsetIndex, pos.x, pos.y);
	//RenderManager::DrawSprite(SpriteType::NORMAL, SpriteIndex::STAGE1_TILE_SET, position.x, position.y);
}
