#include "pch.h"
#include "Character.h"

void Character::Update()
{
	
}

void Character::Render()
{
}

bool Character::IsCollided(const GameObject* _target)
{
	const Character* target = dynamic_cast<const Character*>(_target);
	if (target == nullptr) return false;
	if (target->type == type) return false;

	RECT myBox = this->simpleCollider + this->position;
	RECT targetBox = target->simpleCollider + target->position;
	RECT outBox;

	if (!IntersectRect(&outBox, &myBox, &targetBox)) return false;

	for (const RECT& collider : colliders)
	{
		auto relativedCollider = collider + position;

		for (const RECT& targetCollider : target->colliders)
		{
			auto relativedTargetCollider = targetCollider + target->position;

			if (IntersectRect(&outBox, &relativedCollider, &relativedTargetCollider))
			{
				return true;
			}
		}
	}
	


	return false;
}

void Character::SetColliderSize(LONG left, LONG top, LONG right, LONG bottom)
{
	simpleCollider.left = left;
	simpleCollider.top = top;
	simpleCollider.right = right;
	simpleCollider.bottom = bottom;
}

void Character::PushOut(Character* target, float _force)
{
	float dx = fabs(target->position.x - position.x);
	float dy = fabs(target->position.y - position.y);

	
	RECT targetRect = target->simpleCollider + target->position;
	RECT myRect = simpleCollider + position;

	if (target->position.x < myRect.left) return;
	if (target->position.x > myRect.right) return;


	LONG distance = targetRect.bottom - myRect.top;
	if (distance > 0 && distance <30)
	{
		target->position.y -= targetRect.bottom - myRect.top;
		target->gravityCount = 0;
		target->jumpFlag = true;
	}
	//else if (targetRect.right >= myRect.left)
	//{

	//}
	//else if (targetRect.top <= myRect.bottom)
	//{

	//}
	//else if (targetRect.left <= myRect.right)
	//{

	//}
	
	

}



