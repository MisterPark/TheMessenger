#pragma once
#include "Monster.h"
class BlueKappa :
    public Monster
{
public:
    BlueKappa();
    virtual ~BlueKappa();

    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* _other);

    void ShootTheBlueBall();

    bool reloadingFlag = false;
};


