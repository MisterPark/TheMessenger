#include "pch.h"
#include "SelectBox.h"

SelectBox::SelectBox()
{
	position.x = 0;
	position.y = 0;
}

SelectBox::~SelectBox()
{
}

void SelectBox::Update()
{
}

void SelectBox::Render()
{
	size_t size = selectList.size();
	// 임시 요소당 사이즈
	int elementW = 50;
	int elementH = 15;
	int i = 0;

	for (auto s : selectList)
	{
		RenderManager::DrawString(s, position.x + elementW * i, position.y + elementH * i);
		i++;
	}
}

void SelectBox::AddSelector(const WCHAR * _selector)
{
	selectList.push_back(_selector);
}
