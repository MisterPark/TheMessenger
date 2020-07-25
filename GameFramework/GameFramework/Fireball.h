#pragma once
#include "Monster.h"
class Fireball :
    public Monster
{
public:
    Fireball();
    virtual ~Fireball();

    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* _other);

    float lifeTime = 3.f;
    float lifeTick = 0.f;
};

