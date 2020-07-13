#include "pch.h"
#include "RenderManager.h"

RenderManager* pRenderManager = nullptr;

RenderManager::RenderManager()
{
	// ����� ����
	hdc = GetDC(g_hwnd);
	hBitmap = CreateCompatibleBitmap(hdc, dfCLIENT_WIDTH, dfCLIENT_HEIGHT);
	hBackBufferDC = CreateCompatibleDC(hdc);
	SelectObject(hBackBufferDC, hBitmap);
	SetBkMode(hBackBufferDC, TRANSPARENT);
	SetStretchBltMode(hdc, COLORONCOLOR);
	// ��������Ʈ �迭 ����
	pSprite = new Sprite[MaxOfEnum<SpriteIndex>()];
	// ��������Ʈ�� �����
	width = dfCLIENT_WIDTH;
	height = dfCLIENT_HEIGHT;
	bitCount = 32;
	pitch = ((width * (bitCount >>3)) + 3) & ~3;
	int bufferSize = pitch * height;
	backBufferInfo.bmiHeader.biSize = sizeof(BITMAPINFO);
	backBufferInfo.bmiHeader.biWidth = width;
	backBufferInfo.bmiHeader.biHeight = height;
	backBufferInfo.bmiHeader.biPlanes = 1;
	backBufferInfo.bmiHeader.biBitCount = bitCount;
	backBufferInfo.bmiHeader.biCompression = 0;
	backBufferInfo.bmiHeader.biSizeImage = bufferSize;
	backBufferInfo.bmiHeader.biXPelsPerMeter = 0;
	backBufferInfo.bmiHeader.biYPelsPerMeter = 0;
	backBufferInfo.bmiHeader.biClrUsed = 0;
	backBufferInfo.bmiHeader.biClrImportant = 0;

	buffer = new BYTE[bufferSize];
	memset(buffer, 0xff, bufferSize);
}

RenderManager::~RenderManager()
{
	// ����� ����
	ReleaseDC(g_hwnd, hdc);
	//�ϴ� ������ �ְ�
	if (hBackBufferDC != nullptr)
	{
		SelectObject(hBackBufferDC, nullptr);
		DeleteDC(hBackBufferDC);
	}
	//����۵� �����.
	if (hBitmap != nullptr)
	{
		DeleteObject(hBitmap);
	}

	// ��������Ʈ �޸� ����
	for (int index = 0; index < MaxOfEnum<SpriteIndex>(); index++)
	{
		ReleaseSprite(index);
	}
	delete[] pSprite;
	pSprite = nullptr;
}

RenderManager * RenderManager::GetInstance()
{
	if (pRenderManager == nullptr)
	{
		pRenderManager = new RenderManager;
	}
	return pRenderManager;
}

void RenderManager::Release()
{
	delete pRenderManager;
	pRenderManager = nullptr;
}

void RenderManager::Present()
{
	BitBlt(pRenderManager->hdc, 0, 0, dfCLIENT_WIDTH, dfCLIENT_HEIGHT,
		pRenderManager->hBackBufferDC, 0, 0, SRCCOPY);
}

void RenderManager::Clear()
{
	FillRect(pRenderManager->hBackBufferDC, &pRenderManager->area,
		(HBRUSH)GetStockObject(WHITE_BRUSH));
}

void RenderManager::SetClientSize(int _w, int _h)
{
	pRenderManager->clientWidth = _w;
	pRenderManager->clientHeight = _h;
}


void RenderManager::DrawRect(const RECT& _rc)
{
	Rectangle(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
}

void RenderManager::DrawRect(const RECT& _rc, COLORREF _innerColor)
{
	HBRUSH hBrush = CreateSolidBrush(_innerColor);
	HGDIOBJ oldBrush = SelectObject(pRenderManager->hBackBufferDC, hBrush);
	Rectangle(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
	SelectObject(pRenderManager->hBackBufferDC, oldBrush);
	DeleteObject(hBrush);
}

void RenderManager::DrawRect(const RECT& _rc, COLORREF _innerColor, COLORREF _outlineColor)
{
	HBRUSH hBrush = CreateSolidBrush(_innerColor);
	HPEN hPen = CreatePen(PS_SOLID, 1, _outlineColor);
	HGDIOBJ oldBrush = SelectObject(pRenderManager->hBackBufferDC, hBrush);
	HGDIOBJ oldPen = SelectObject(pRenderManager->hBackBufferDC, hPen);
	Rectangle(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
	SelectObject(pRenderManager->hBackBufferDC, oldBrush);
	SelectObject(pRenderManager->hBackBufferDC, oldPen);
	DeleteObject(hBrush);
	DeleteObject(hPen);
}

void RenderManager::DrawSimpleCollider(const RECT& _rc, COLORREF _outlineColor)
{
	HPEN hPen = CreatePen(PS_SOLID, 1, _outlineColor);
	HGDIOBJ oldPen = SelectObject(pRenderManager->hBackBufferDC, hPen);
	Rectangle(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
	SelectObject(pRenderManager->hBackBufferDC, oldPen);
	DeleteObject(hPen);
}

void RenderManager::DrawCircle(const RECT& _rc)
{
	Ellipse(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
}

void RenderManager::DrawCircle(const RECT& _rc, COLORREF _innerColor, COLORREF _outlineColor)
{
	HBRUSH hBrush = CreateSolidBrush(_innerColor);
	HPEN hPen = CreatePen(PS_SOLID, 1, _outlineColor);
	HGDIOBJ oldBrush = SelectObject(pRenderManager->hBackBufferDC, hBrush);
	HGDIOBJ oldPen = SelectObject(pRenderManager->hBackBufferDC, hPen);
	Ellipse(pRenderManager->hBackBufferDC, _rc.left, _rc.top, _rc.right, _rc.bottom);
	SelectObject(pRenderManager->hBackBufferDC, oldBrush);
	SelectObject(pRenderManager->hBackBufferDC, oldPen);
	DeleteObject(hBrush);
	DeleteObject(hPen);
}

void RenderManager::DrawString(const WCHAR* _str, int _x, int _y)
{
	TextOutW(pRenderManager->hBackBufferDC, _x, _y, _str, wcslen(_str));
}

void RenderManager::DrawString(const WCHAR* _str, int _x, int _y, COLORREF _color)
{
	COLORREF oldColor = SetTextColor(pRenderManager->hBackBufferDC, _color);
	TextOutW(pRenderManager->hBackBufferDC, _x, _y, _str, wcslen(_str));
	SetTextColor(pRenderManager->hBackBufferDC, oldColor);
}

void RenderManager::DrawString(const WCHAR* _str, int _x, int _y, const WCHAR* _font, int _fontSize, COLORREF _color)
{
	HFONT hFont = CreateFont(_fontSize, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, _font);
	HFONT oldFont = (HFONT)SelectObject(pRenderManager->hBackBufferDC, hFont);
	COLORREF oldColor = SetTextColor(pRenderManager->hBackBufferDC, _color);
	TextOutW(pRenderManager->hBackBufferDC, _x, _y, _str, wcslen(_str));
	SelectObject(pRenderManager->hBackBufferDC, oldFont);
	DeleteObject(hFont);
	SetTextColor(pRenderManager->hBackBufferDC, oldColor);
}

void RenderManager::DrawLine(float _startX, float _startY, float _endX, float _endY)
{
	POINT pt = {};
	MoveToEx(pRenderManager->hBackBufferDC, _startX, _startY, &pt);
	LineTo(pRenderManager->hBackBufferDC, _endX, _endY);
}

bool RenderManager::LoadSprite(int _index, const char* _fileName, int _centerX, int _centerY)
{
	HANDLE hFile;
	DWORD dwRead;
	int iPitch;
	int iImageSize;
	int iCount;
	BITMAPFILEHEADER stFileHeader;
	BITMAPINFOHEADER stInfoHeader;
	Sprite* pSprite = pRenderManager->pSprite;
	hFile = CreateFileA(_fileName, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		return false;
	}

	ReleaseSprite(_index);

	// ���� ��� �б�
	if (ReadFile(hFile, &stFileHeader, sizeof(BITMAPFILEHEADER), &dwRead, NULL) == false)
	{
		CloseHandle(hFile);
		return false;
	}
	
	// ��Ʈ�� �����ѹ� üũ 0x4D42
	if (stFileHeader.bfType != 0x4D42)
	{
		CloseHandle(hFile);
		return false;
	}
	
	//��������� �б�
	if (ReadFile(hFile, &stInfoHeader, sizeof(BITMAPINFOHEADER), &dwRead, NULL) == false)
	{
		CloseHandle(hFile);
		return false;
	}

	// 32��Ʈ ��Ʈ������ Ȯ��
	if (stInfoHeader.biBitCount != 32)
	{
		CloseHandle(hFile);
		return false;
	}
	//���� ������ ��ġ�� ���
	iPitch = (((stInfoHeader.biWidth *(stInfoHeader.biBitCount>>3)) + 3)& ~3);
	// ��������Ʈ ����ü�� ũ�� ����
	pSprite[_index].width = stInfoHeader.biWidth;
	pSprite[_index].height = stInfoHeader.biHeight;
	pSprite[_index].pitch = iPitch;

	// �̹��� ��ü ũ�� ���ϱ�, �޸� �Ҵ�.
	iImageSize = iPitch * stInfoHeader.biHeight;
	pSprite[_index].buffer = new BYTE[iImageSize];

	//�ӽù��� (����������)
	BYTE* bypTempBuffer = new BYTE[iImageSize];
	BYTE* bypSpriteTemp = pSprite[_index].buffer;
	BYTE* bypTurnTemp;

	if (ReadFile(hFile, bypTempBuffer, iImageSize, &dwRead, NULL) == false)
	{
		delete[] bypTempBuffer;
		return false;
	}
	//������
	//bypTurnTemp = bypTempBuffer + iPitch * (stInfoHeader.biHeight - 1);
	bypTurnTemp = bypTempBuffer;

	for (iCount = 0; iCount < stInfoHeader.biHeight; iCount++)
	{
		memcpy(bypSpriteTemp, bypTurnTemp, iPitch);
		bypSpriteTemp += iPitch;
		bypTurnTemp += iPitch;
	}
	delete[] bypTempBuffer;

	pSprite[_index].centerX = _centerX;
	pSprite[_index].centerY = _centerY;
	CloseHandle(hFile);
	return true;
	

	
	CloseHandle(hFile);
	return false;
}

void RenderManager::ReleaseSprite(int _index)
{
	//�ִ� �Ҵ�� ��������Ʈ�� �Ѿ�� ����
	if (MaxOfEnum<SpriteIndex>() <= _index)
	{
		return;
	}
	//���� �� �ʱ�ȭ
	if (pRenderManager->pSprite[_index].buffer != nullptr)
	{
		delete[] pRenderManager->pSprite[_index].buffer;
		pRenderManager->pSprite[_index].buffer = nullptr;
	}
}

void RenderManager::DrawSprite(SpriteType _type, SpriteIndex _index, int destX, int destY, int len)
{
	//�ִ� ��������Ʈ ���� �ʰ�
	if (MaxOfEnum<SpriteIndex>() <= (int)_index)
	{
		return;
	}
	//�ε���� �ʴ� ��������Ʈ
	if (pRenderManager->pSprite[(int)_index].buffer == NULL)
	{
		return;
	}

	Sprite* sprite = &pRenderManager->pSprite[(int)_index];

	// ��������Ʈ ����� ���� ������ ����.
	int iSpriteWidth = sprite->width;
	int iSpriteHeight = sprite->height;
	int iX, iY;

	// ��� ���� ����
	iSpriteWidth = iSpriteWidth * len / 100;
	DWORD* dwpDest = (DWORD*)pRenderManager->buffer;
	DWORD* dwpSprite = (DWORD*)(sprite->buffer);

	//����� ũ��
	int destW = pRenderManager->width;
	int destH = pRenderManager->height;
	int destP = pRenderManager->pitch;
	//��� ���� ó��
	destX = destX - sprite->centerX;
	destY = destY - sprite->centerY;

	// ��� Ŭ����
	if (destY < 0)
	{
		iSpriteHeight = iSpriteHeight - (-destY);
		dwpSprite = (DWORD*)(sprite->buffer + sprite->pitch * (-destY));
		//������ ©���� ���-> ��������Ʈ ������ġ�� �Ʒ��� ������
		destY = 0;
	}
	// �ϴ� Ŭ����
	if (destH <= destY + sprite->height)
	{
		iSpriteHeight -= ((destY + sprite->height) - destH);
	}
	// ���� Ŭ����
	if (destX < 0)
	{
		iSpriteWidth = iSpriteWidth - (-destX);
		dwpSprite = dwpSprite + (-destX);
		// ��� ���� ��ġ�� ���������� ��
		destX = 0;
	}
	// ���� Ŭ����
	if (destW <= destX + sprite->width)
	{
		iSpriteWidth -= ((destX + sprite->width) - destW);
	}

	// ���� �׸� ������ ����.
	if (iSpriteWidth <= 0 || iSpriteHeight <= 0)
	{
		return;
	}
	// ȭ�鿡 ���� ��ġ�� �̵�
	dwpDest = (DWORD*)(((BYTE*)(dwpDest + destX) + (destY * destP)));

	BYTE* bypDestOrigin = (BYTE*)dwpDest;
	BYTE* bypSpriteOrigin = (BYTE*)dwpSprite;
	DWORD temp, temp2;

	// ��ü ũ�⸦ ���鼭 ����� ó��
	for (iY = 0; iY < iSpriteHeight; iY++)
	{
		for (iX = 0; iX < iSpriteWidth; iX++, dwpDest++, dwpSprite++)
		{
			if (pRenderManager->colorKey == (*dwpSprite & 0x00ffffff)) { continue; }

			switch (_type)
			{
			case SpriteType::NORMAL:
				temp = *dwpSprite;
				break;
			case SpriteType::TONEDOWN_RED:
				temp = *dwpSprite & 0xffff0000;
				temp2 = ((*dwpSprite & 0x0000ffff) >> 1) & 0x7f7f7f7f;
				temp = temp | temp2;
				break;
			case SpriteType::TONEDOWN_GREEN:
				temp = *dwpSprite & 0xff00ff00;
				temp2 = ((*dwpSprite & 0x00ff00ff) >> 1) & 0x7f7f7f7f;
				temp = temp | temp2;
				break;
			case SpriteType::TONEDOWN_BLUE:
				temp = *dwpSprite & 0xff0000ff;
				temp2 = ((*dwpSprite & 0x00ffff00) >> 1) & 0x7f7f7f7f;
				temp = temp | temp2;
				break;
			case SpriteType::TONEUP_RED:
				temp = *dwpSprite & 0xff00ffff;
				temp = 0x00ff0000 | temp;
				break;
			case SpriteType::TONEUP_GREEN:
				temp = *dwpSprite & 0xffff00ff;
				temp = 0x0000ff00 | temp;
				break;
			case SpriteType::TONEUP_BLUE:
				temp = *dwpSprite & 0xffffff00;
				temp = 0x000000ff | temp;
				break;
			case SpriteType::ALPHA50:
				temp = (*dwpDest >> 1) & 0x7f7f7f7f;
				temp2 = (*dwpSprite >> 1) & 0x7f7f7f7f;
				temp = temp + temp2;
				break;
			case SpriteType::CLOAKING:
				temp = (*(dwpDest + 5) | 0x03030303);
				break;
			case SpriteType::TRANSPARENTS:
				temp = *dwpDest;
				break;
			default:
				temp = *dwpSprite;
				break;
			}

			*dwpDest = temp;

		}

		// �����ٷ� �̵�
		bypDestOrigin += destP;
		bypSpriteOrigin += sprite->pitch;

		dwpDest = (DWORD*)bypDestOrigin;
		dwpSprite = (DWORD*)bypSpriteOrigin;
	}
}

void RenderManager::DrawImage(SpriteIndex spriteIndex, int destX, int destY, int len)
{
	//�ִ� ��������Ʈ ���� �ʰ�
	if (MaxOfEnum<SpriteIndex>() <= (int)spriteIndex)
	{
		return;
	}
	//�ε���� �ʴ� ��������Ʈ
	if (pRenderManager->pSprite[(int)spriteIndex].buffer == NULL)
	{
		return;
	}

	SPRITE* pSprite = &pRenderManager->pSprite[(int)spriteIndex];

	// ��������Ʈ ����� ���� ������ ����.
	int iSpriteWidth = pSprite->width;
	int iSpriteHeight = pSprite->height;
	int iY;

	//����� ũ��
	int destW = pRenderManager->width;
	int destH = pRenderManager->height;
	int destP = pRenderManager->pitch;
	// ��� ���� ����
	iSpriteWidth = iSpriteWidth * len / 100;
	DWORD* dwpDest = (DWORD*)pRenderManager->buffer;
	DWORD* dwpSprite = (DWORD*)(pSprite->buffer);

	// ��� Ŭ����
	if (destY < 0)
	{
		iSpriteHeight = iSpriteHeight - (-destY);
		dwpSprite = (DWORD*)(pSprite->buffer + pSprite->pitch * (-destY));
		//������ ©���� ���-> ��������Ʈ ������ġ�� �Ʒ��� ������
		destY = 0;
	}
	// �ϴ� Ŭ����
	if (destH <= destY + pSprite->height)
	{
		iSpriteHeight -= ((destY + pSprite->height) - destH);
	}
	// ���� Ŭ����
	if (destX < 0)
	{
		iSpriteWidth = iSpriteWidth - (-destX);
		dwpSprite = dwpSprite + (-destX);
		// ��� ���� ��ġ�� ���������� ��
		destX = 0;
	}
	// ���� Ŭ����
	if (destW <= destX + pSprite->width)
	{
		iSpriteWidth -= ((destX + pSprite->width) - destW);
	}

	// ���� �׸� ������ ����.
	if (iSpriteWidth <= 0 || iSpriteHeight <= 0)
	{
		return;
	}

	// ȭ�� ���� ��ġ�� �̵�.
	dwpDest = (DWORD*)(((BYTE*)(dwpDest + destX) + (destY * destP)));

	// ��ü ũ�⸦ ���鼭 ����
	for (iY = 0; iY < iSpriteHeight; iY++)
	{
		memcpy(dwpDest, dwpSprite, iSpriteWidth * 4);
		//�����ٷ� �̵�. ȭ��� ��������Ʈ ���.
		dwpDest = (DWORD*)((BYTE*)dwpDest + destP);
		dwpSprite = (DWORD*)((BYTE*)dwpSprite + pSprite->pitch);

	}
}

void RenderManager::Flip()
{
	StretchDIBits(pRenderManager->hdc,
		0, 0, pRenderManager->clientWidth, pRenderManager->clientHeight,
		0, 0, dfCLIENT_WIDTH, dfCLIENT_HEIGHT, pRenderManager->buffer,
		&pRenderManager->backBufferInfo, DIB_RGB_COLORS, SRCCOPY);
	//StretchBlt(pRenderManager->hdc,
	//	0, 0, pRenderManager->clientWidth, pRenderManager->clientHeight,
	//	pRenderManager->hBackBufferDC,
	//	0, 0, dfCLIENT_WIDTH, dfCLIENT_HEIGHT,
	//	SRCCOPY);
	
}
