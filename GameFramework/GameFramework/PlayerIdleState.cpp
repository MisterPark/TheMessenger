#include "pch.h"
#include "PlayerIdleState.h"

void PlayerIdleState::Update(GameObject* pObj)
{
	if (pObj->direction == Direction::LEFT)
	{
		pObj->anim->SetAnimation(SpriteIndex::PLAYER_IDLE_L);
	}
	else
	{
		pObj->anim->SetAnimation(SpriteIndex::PLAYER_IDLE_R);
	}
	
}
