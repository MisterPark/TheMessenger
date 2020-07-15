#include "pch.h"
#include "HUD_Bar.h"

HUD_Bar::HUD_Bar()
{
	position = { 0,0 };
	area = { 0,0,640,30 };
}

HUD_Bar::~HUD_Bar()
{
}

void HUD_Bar::Update()
{
}

void HUD_Bar::Render()
{
	RenderManager::DrawRect(area,RGB(0,0,0));
}
