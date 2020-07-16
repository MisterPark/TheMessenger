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

void GameObject::SetAnimation(SpriteIndex _index)
{
	anim->SetAnimation(_index);
}

void GameObject::SetAnimation(SpriteIndex _startIndex, SpriteIndex _endIndex)
{
	anim->SetAnimation(_startIndex, _endIndex);
}



