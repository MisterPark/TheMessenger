#include "pch.h"
#include "Tile.h"
#include "Player.h"
#include "Monster.h"
#include "LeafMonster.h"

Tile::Tile()
{
	position = { 0,0 };
	simpleCollider = { 0,0,dfTILE_W,dfTILE_H };
}

Tile::~Tile()
{
}

void Tile::Update()
{
	if (option & dfTILE_OPTION_MOVE)
	{
		int destX = ePoint.x * dfTILE_W;
		int destY = ePoint.y * dfTILE_H;

	}
}

void Tile::Render()
{
	Transform pos = GetPositionFromCamera();
	RenderManager::DrawTile(SpriteType::NORMAL, tileset, offsetIndex, pos.x, pos.y);
	//RenderManager::DrawSprite(SpriteType::NORMAL, SpriteIndex::STAGE1_TILE_SET, position.x, position.y);

	if (ObjectManager::IsVisibleCollider())
	{
		RenderManager::DrawSimpleCollider(pos + simpleCollider, RGB(0, 255, 0));
	}
	
}

void Tile::OnCollision(GameObject* _other)
{
	if (dynamic_cast<Player*>(_other))
	{
		PushOut((Character*)_other, option);
	}
	else if (dynamic_cast<Monster*>(_other))
	{
		if (_other->type == ObjectType::BLUE_BALL) return;
		if (_other->type == ObjectType::LEAF_RING)return;
		if (_other->type == ObjectType::LEAF_MONSTER)
		{
			if (dynamic_cast<LeafMonster*>(_other)->isNotPushed) return;
		}
		PushOut((Character*)_other, option);
	}
	
	

}
