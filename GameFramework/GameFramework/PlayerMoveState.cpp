#include "pch.h"
#include "PlayerMoveState.h"
#include "Player.h"

void PlayerMoveState::Update(GameObject* pObj)
{
	Player* p = dynamic_cast<Player*>(pObj);
	if (p == nullptr)
	{
		return;
	}

	

	if (p->direction == Direction::LEFT)
	{
		p->anim->SetAnimation(SpriteIndex::PLAYER_RUN_LEG_L1, SpriteIndex::PLAYER_RUN_LEG_L4);
		p->anim2->SetAnimation(SpriteIndex::PLAYER_RUN_BODY_L);
		
	}
	else
	{
		p->anim->SetAnimation(SpriteIndex::PLAYER_RUN_LEG_R1, SpriteIndex::PLAYER_RUN_LEG_R4);
		p->anim2->SetAnimation(SpriteIndex::PLAYER_RUN_BODY_R);
	}

	p->anim->SetFrameDelay(10);
	p->anim->SetLoop(true);
}
