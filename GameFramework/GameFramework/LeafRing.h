#pragma once
#include "Monster.h"
class LeafRing :
    public Monster
{
public:
    LeafRing();
    virtual ~LeafRing();

    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* _other);

    bool isAttack1 = true;
    bool isComeback = false;
    bool isComeback2 = false;
};

