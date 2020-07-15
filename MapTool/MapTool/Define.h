#pragma once

#define dfCLIENT_WIDTH 1280
#define dfCLIENT_HEIGHT 720
#define dfFPS 60


template<typename EnumT>
constexpr int MaxOfEnum()
{
	return (int)EnumT::END;
}