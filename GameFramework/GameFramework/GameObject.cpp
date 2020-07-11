#include "pch.h"
#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
	
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


