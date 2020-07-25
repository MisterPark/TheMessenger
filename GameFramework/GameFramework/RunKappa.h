#pragma once
#include "Monster.h"
class RunKappa : public Monster
{
public:
    RunKappa();
    virtual ~RunKappa();

    virtual void Update() override;
    virtual void Render() override;
};

