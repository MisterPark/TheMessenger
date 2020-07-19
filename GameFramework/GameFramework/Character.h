#pragma once
#include "GameObject.h"
class Character : public GameObject
{
public:
	Character() = default;
	~Character() = default;

	virtual void Update() override;
	virtual void Render() override;


	bool IsCollided(const GameObject* _target);
	void SetColliderSize(LONG left, LONG top, LONG right, LONG bottom);

	// �浹 �ɼ���
	void PushOut(Character* target, DWORD option);

public:
	float speed = 0.f;
	RECT simpleCollider; // ��ü�� ���δ� Ŀ�ٶ� �簢����
	vector<RECT> colliders; // ���� �浹����
	// �߷�
	bool useGravity = false;
	bool isFalldown = false;
	int gravityCount = 0;
	int jumpCount = 0;
};
