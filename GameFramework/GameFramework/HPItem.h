#pragma once
#include "Character.h"
class HPItem :
    public Character
{
public:
	HPItem();
	~HPItem();

	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* _other);
};

