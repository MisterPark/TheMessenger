#pragma once
#include "GameObject.h"
class Tile : public GameObject
{
public:
	Tile();
	virtual ~Tile();

	// GameObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

};

