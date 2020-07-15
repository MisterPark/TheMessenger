#include "pch.h"
#include "Animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::Update()
{
	frameCount++;
	if (frameDelay <= frameCount)
	{
		frameCount = 0;
		// ��������Ʈ �ε��� �ѱ�� ( �̳�Ŭ���� ��������)
		
		if (curIndex == endIndex)
		{
			if (isLoop)
			{
				curIndex = startIndex;
				return;
			}
			return;
		}

		int index = (int)curIndex;
		index++;
		curIndex = (SpriteIndex)index;
	}
}

SpriteIndex Animation::GetCurrentSpriteIndex()
{
	return curIndex;
}

void Animation::SetAnimation(SpriteIndex _index)
{
	startIndex = _index;
	curIndex = _index;
	endIndex = _index;
}

void Animation::SetAnimation(SpriteIndex _start, SpriteIndex _end)
{
	startIndex = _start;
	curIndex = _start;
	endIndex = _end;
}

void Animation::SetFrameDelay(int _framePerSprite)
{
	frameCount = 0;
	frameDelay = _framePerSprite;
}

void Animation::SetLoop(bool _isLoop)
{
	isLoop = _isLoop;
}
