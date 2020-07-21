#pragma once
#include "Character.h"
class Monster :
    public Character
{
public:
    Monster() = default;
    virtual ~Monster() = default;

    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* _other);

    void SetSpawnPosition(int x, int y);
    void SetBackAndForth(int x, int y);

    // 패턴
    void BackAndForth(); // 왔다리갔다리

public:
    Transform spawnPos{ 0.f,0.f };
    Transform backAndForthPos{ 0.f,0.f };
    bool backAndForthFlag = false;
};

