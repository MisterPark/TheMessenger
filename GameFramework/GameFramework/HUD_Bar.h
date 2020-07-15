#pragma once
#include "UI.h"
class HUD_Bar : public UI
{
public:
	HUD_Bar();
	virtual ~HUD_Bar();

	virtual void Update() override;
	virtual void Render() override;
};

