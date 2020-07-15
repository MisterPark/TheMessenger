#pragma once
#include "UI.h"
class SelectBox : public UI
{
public:
	SelectBox();
	virtual ~SelectBox();

	virtual void Update() override;
	virtual void Render() override;

	void AddSelector(const WCHAR* _selector);

private:
	list<const WCHAR*> selectList;
};

