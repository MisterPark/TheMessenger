#pragma once
#include "UI.h"

class SelectElement
{
public:
	int stringX = 0;
	int stirngY = 0;
	int x = 0;
	int y = 0;
	int width = 100;
	int height = 25;
	void (*func)();
	WCHAR title[32];
};

class SelectBox : public UI
{
public:
	SelectBox();
	virtual ~SelectBox();

	virtual void Update() override;
	virtual void Render() override;

	void AddSelector(const WCHAR* _selector, void(*_func)());
	void ClearSelector();

private:
	vector<SelectElement*> selectList;
	int selectedIndex = 0;
};

