#include "pch.h"
#include "Monster.h"

void Monster::Update()
{
}

void Monster::Render()
{
}

void Monster::OnCollision(GameObject* _other)
{
}

void Monster::SetSpawnPosition(int x, int y)
{
	spawnPos.x = x;
	spawnPos.y = y;
	position.x = x;
	position.y = y;
}

void Monster::SetBackAndForth(int x, int y)
{
	backAndForthPos.x = x;
	backAndForthPos.y = y;
}

void Monster::BackAndForth()
{
	int distance = 0;

	if (backAndForthFlag)
	{
		distance = spawnPos.x - position.x;
	}
	else
	{
		distance = backAndForthPos.x - position.x;
	}

	
	if (distance == 0) // ����
	{
		backAndForthFlag = !backAndForthFlag;

	}
	else if (distance < 0) // �������� ������
	{
		direction = Direction::LEFT;
		position.x -= speed * TimeManager::DeltaTime();
	}
	else // ���������� ������
	{
		direction = Direction::RIGHT;
		position.x += speed * TimeManager::DeltaTime();
	}
}
