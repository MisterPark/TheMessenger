#pragma once
#include "IScene.h"
class GameOverScene :
    public IScene
{
public:
    // IScene��(��) ���� ��ӵ�
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;
};

