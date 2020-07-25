#pragma once
#include "GameObject.h"
class ExplosionEffect :
    public GameObject
{
public:
    ExplosionEffect();
    virtual ~ExplosionEffect();
    virtual void Update() override;
    virtual void Render() override;
};

