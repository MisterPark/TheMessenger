#include "pch.h"
#include "GameObject.h"
#include "Animation.h"

GameObject::GameObject()
{
	anim = new Animation;
}

GameObject::~GameObject()
{
	delete anim;
}

void GameObject::Die()
{
	isDead = true;
}

void GameObject::SetPosition(float _x, float _y)
{
	position.x = _x;
	position.y = _y;
}

void GameObject::SetTarget(GameObject* _target)
{
	this->target = _target;
}

void GameObject::SetAnimation(SpriteIndex _index)
{
	anim->SetAnimation(_index);
}

void GameObject::SetAnimation(SpriteIndex _startIndex, SpriteIndex _endIndex)
{
	anim->SetAnimation(_startIndex, _endIndex);
}

Transform GameObject::GetPositionFromCamera()
{
	Transform pos = position;
	pos.x -= Camera::GetX();
	pos.y -= Camera::GetY();
	return pos;
}

void GameObject::FollowTarget()
{
	if (target == nullptr)return;

	// 수정해야함(몬스터 따라가기)
}

void GameObject::TakeDamage(int _damage)
{
	hp -= _damage;

	if (hp <= 0)
	{
		Die();
	}
}

bool GameObject::KnockBack()
{
	if (isAttacked)
	{
		knockbackTick += TimeManager::DeltaTime();
		if (knockbackDelay < knockbackTick)
		{
			knockbackTick = 0.f;
			isAttacked = false;
			return false;
		}

		if (knockbackDirection == Direction::LEFT)
		{
			position.x -= 50.f * TimeManager::DeltaTime();
			position.y -= 150.f * TimeManager::DeltaTime();
		}
		else if(knockbackDirection == Direction::RIGHT)
		{
			position.x += 50.f * TimeManager::DeltaTime();
			position.y -= 150.f * TimeManager::DeltaTime();
		}

		return true;
	}

	return false;
}



