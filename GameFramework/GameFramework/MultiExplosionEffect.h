#pragma once
#include "GameObject.h"
class MultiExplosionEffect :
    public GameObject
{
public:
    MultiExplosionEffect();
    virtual ~MultiExplosionEffect();
    virtual void Update() override;
    virtual void Render() override;

    float lifeTick = 0.f;
    float lifeDelay = 3.f;
    float effectTick = 0.f;
    float effectDelay = 0.1f;
};

