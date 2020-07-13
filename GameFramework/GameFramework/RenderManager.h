#pragma once
#include <Windows.h>

enum class SpriteIndex
{
	INTRO,
	CUT_SCENE1,
	CUT_SCENE2,
	CUT_SCENE3,
	CUT_SCENE4,
	CUT_SCENE5,
	CUT_SCENE6,
	CUT_SCENE7,
	TITLE_BG,
	TITLE_LOGO,
	GAMEOVER1,
	GAMEOVER2,


	END
};

enum class SpriteType
{
	NORMAL = 0,
	TONEDOWN_RED,
	TONEDOWN_GREEN,
	TONEDOWN_BLUE,
	TONEUP_RED,
	TONEUP_GREEN,
	TONEUP_BLUE,
	ALPHA50,
	CLOAKING,
	TRANSPARENTS,

	END
};

typedef struct Sprite
{
	BYTE* buffer = nullptr; // 스프라이트 이미지 포인터.
	int width = 0;
	int height = 0;
	int pitch = 0;

	int centerX = 0;
	int centerY = 0;

}SPRITE;

class RenderManager
{
private:
	RenderManager();
	~RenderManager();

public:
	static RenderManager* GetInstance();
	static void Release();
	static void Present();
	static void Clear();

	static void SetClientSize(int _w, int _h);

	// 기본 도형
	static void DrawRect(const RECT& _rc);
	static void DrawRect(const RECT& _rc, COLORREF _innerColor);
	static void DrawRect(const RECT& _rc, COLORREF _innerColor, COLORREF _outlineColor);
	static void DrawSimpleCollider(const RECT& _rc, COLORREF _outlineColor);
	static void DrawCircle(const RECT& _rc);
	static void DrawCircle(const RECT& _rc, COLORREF _innerColor, COLORREF _outlineColor);
	static void DrawString(const WCHAR* _str, int _x, int _y);
	static void DrawString(const WCHAR* _str, int _x, int _y, COLORREF _color);
	static void DrawString(const WCHAR* _str, int _x, int _y, const WCHAR* _font, int _fontSize, COLORREF _color);
	static void DrawLine(float _startX, float _startY, float _endX, float _endY);
	
	// 이미지 스프라이트
	static bool LoadSprite(int _index, const char* _fileName, int _centerX, int _centerY);
	static void ReleaseSprite(int _index);
	static void DrawSprite(SpriteType _type, SpriteIndex _index, int destX, int destY, int len = 100);
	//특정 메모리 위치에 이미지를 출력한다(클리핑 처리)
	static void DrawImage(SpriteIndex spriteIndex, int destX, int destY, int len = 100);
	// 버퍼 스왑
	static void Flip();

	
private:
	HDC hdc;
	HBITMAP hBitmap;
	HDC hBackBufferDC;
	RECT area = { 0,0,dfCLIENT_WIDTH,dfCLIENT_HEIGHT };

	Sprite* pSprite = nullptr;
	DWORD colorKey = 0x00FFFFFF; // 투명색
	BYTE* buffer = nullptr;
	BITMAPINFO backBufferInfo;
	int width = 0;
	int height = 0;
	int pitch = 0;
	int bitCount = 0;

	int clientWidth = dfCLIENT_WIDTH;
	int clientHeight = dfCLIENT_HEIGHT;
};

