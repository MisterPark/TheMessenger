#pragma once
#include "Monster.h"

enum BlueKappaState
{
    BK_IDLE,
    BK_READY,
    BK_SHOOT,
};

class BlueKappa :
    public Monster
{
public:
    BlueKappa();
    virtual ~BlueKappa();

    virtual void Update() override;
    virtual void Render() override;

    void AnimationProcess();

    void ShootTheBlueBall();


    BlueKappaState bkState = BK_IDLE;
    bool reloadingFlag = false;

};


