#pragma once
#include "GameObject.h"
class EndingCredit :
    public GameObject
{
public:
    EndingCredit();
    ~EndingCredit();
    // GameObject��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

    float y1 = 0.f;
    float y2 = 0.f;
    float y3 = 0.f;
};

