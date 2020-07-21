#pragma once
#include "Monster.h"
class GreenKappa :
    public Monster
{
public:
    GreenKappa();
    virtual ~GreenKappa();

    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject * _other);
};

