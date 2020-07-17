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
	RenderManager::DrawTile(SpriteType::NORMAL, SpriteIndex::STAGE1_TILE_SET, 0, position.x, position.y);
	//RenderManager::DrawSprite(SpriteType::NORMAL, SpriteIndex::STAGE1_TILE_SET, position.x, position.y);
}
