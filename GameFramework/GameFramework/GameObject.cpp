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


