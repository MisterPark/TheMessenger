#pragma once
#include "Monster.h"
class Scurubu :
    public Monster
{
public:
    Scurubu();
    virtual ~Scurubu();

    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* _other);
};

