#pragma once
#include "Monster.h"

enum LeafMonsterState
{
    LM_BORN,
    LM_IDLE,
    LM_WALK,
    LM_JUMP,
    LM_ATTACK1,
    LM_ATTACK2,
    LM_ATTACKED,
};

class LeafMonster :
    public Monster
{
public:
    LeafMonster();
    virtual ~LeafMonster();

    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* _other);

    void AnimationProcess();

    LeafMonsterState lmState = LM_BORN;
    bool bornFlag = false;
    bool attack2Ready = false;
    bool attack1Flag = false;
    bool attack2Flag = false;
    bool JumpUpFlag = false;
    bool JumpDownFlag = false;
    bool isNotPushed = false;
    bool attack2Once = false;
    float attack2Delay = 2.5f;
    float attack2Tick = 0.f;
    float jumpDelay = 1.f;
    float jumpTick = 0.f;
    
};

