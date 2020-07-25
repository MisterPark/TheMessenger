#pragma once
#include "Monster.h"


class RangedKappa :
    public Monster
{
public:
    RangedKappa();
    virtual ~RangedKappa();

    virtual void Update() override;
    virtual void Render() override;

    void AnimationProcess();

    void FireBall();
    void FireBallUpdate();

    bool isShoot = false;
    float waitTick = 0.f;
    float waitDelay = 3.f;
    bool fireOnceFlag = false;
};

