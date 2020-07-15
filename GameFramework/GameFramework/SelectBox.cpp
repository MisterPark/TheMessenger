#include "pch.h"
#include "SelectBox.h"

SelectBox::SelectBox()
{
	position.x = 270;
	position.y = 250;
	isEnable = true;
	isVisible = true;
}

SelectBox::~SelectBox()
{
	ClearSelector();
}

void SelectBox::Update()
{
	if (InputManager::GetKeyDown(VK_UP))
	{
		if (selectList.size() != 0)
		{
			if (selectedIndex == 0)
			{
				selectedIndex = selectList.size()-1;
			}
			else
			{
				selectedIndex = ((selectedIndex - 1) % selectList.size());
			}

		}
			
	}
	if (InputManager::GetKeyDown(VK_DOWN))
	{
		if (selectList.size() != 0)
			selectedIndex = ((selectedIndex + 1) % selectList.size());
	}
	if (InputManager::GetKeyDown(VK_SPACE))
	{
		selectList[selectedIndex]->func();
	}
}

void SelectBox::Render()
{
	int i = 0;

	for (auto s : selectList)
	{
		if (i == selectedIndex)
		{
			RenderManager::DrawSprite(SpriteType::NORMAL, SpriteIndex::UI_FRAME1, position.x, position.y + s->y, s->width, s->height);
		}
		RenderManager::DrawString(s->title, position.x + s->stringX, position.y + s->stirngY + s->y, 11, RGB(254, 254, 254));
		i++;
	}
}

void SelectBox::AddSelector(const WCHAR * _selector, void(*_func)())
{
	int count = selectList.size();

	SelectElement* element = new SelectElement;
	wcscpy_s(element->title, _selector);
	element->y = element->height * count;
	element->stringX = (element->width - wcslen(_selector) * 11) / 2;
	element->stirngY = (element->height - 11) / 2;
	element->func = _func;
	selectList.push_back(element);
}

void SelectBox::ClearSelector()
{
	auto iter = selectList.begin();
	auto end = selectList.end();
	for (; iter != end; ++iter)
	{
		delete (*iter);
	}
	selectList.clear();
}
