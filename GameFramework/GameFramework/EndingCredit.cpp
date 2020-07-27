#include "pch.h"
#include "EndingCredit.h"

EndingCredit::EndingCredit()
{
	y1 = 400.f;
	y2 = y1 + 60;
	y3 = y2 + 30;
}

EndingCredit::~EndingCredit()
{
}

void EndingCredit::Update()
{
	float dt = TimeManager::DeltaTime();
	y1 -= 30.f * dt;
	y2 -= 30.f * dt;
	y3 -= 30.f * dt;

	if (y1 < 170)
	{
		y1 = 600;
	}
	if (y2 < 170)
	{
		y2 = 600;
	}
	if (y3 < 170)
	{
		y3 = 600;
	}
}

void EndingCredit::Render()
{

	RenderManager::DrawString(L"���� : �ڰ���", 250, y1, 15, RGB(254, 254, 254));
	RenderManager::DrawString(L"���� : �ں��� ������", 250, y2, 15, RGB(254, 254, 254));
	RenderManager::DrawString(L"       : ��� ���� ��ī����", 250, y3, 15, RGB(254, 254, 254));
}
