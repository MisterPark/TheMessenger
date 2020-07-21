#pragma once
#include "Monster.h"
class BlueBall :
    public Monster
{
public:
    BlueBall();
    virtual ~BlueBall();

    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* _other);
};

