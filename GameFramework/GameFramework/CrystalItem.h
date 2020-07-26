#pragma once
#include "Character.h"
class CrystalItem :
    public Character
{
public:
	CrystalItem();
	~CrystalItem();

	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* _other);
};

