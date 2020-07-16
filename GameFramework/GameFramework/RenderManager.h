#pragma once
#include <Windows.h>

enum class SpriteIndex
{
	NONE,
	// 인트로씬
	INTRO,
	CUT_SCENE1,
	CUT_SCENE2,
	CUT_SCENE3,
	CUT_SCENE4,
	CUT_SCENE5,
	CUT_SCENE6,
	CUT_SCENE7,
	// 타이틀씬
	TITLE_BG,
	TITLE_LOGO,
	GAMEOVER1,
	GAMEOVER2,
	UI_FRAME1,
	// 스테이지1
	BLACKSCREEN,
	NINJA_BG_1,

	// 플레이어
	PLAYER_IDLE_R,
	PLAYER_IDLE_L,
	PLAYER_ATTACKED_R,
	PLAYER_ATTACKED_L,
	PLAYER_SITDOWN_R,
	PLAYER_SITDOWN_L,
	PLAYER_JUMP_R1,
	PLAYER_JUMP_R2,
	PLAYER_JUMP_R3,
	PLAYER_JUMP_R4,
	PLAYER_JUMP_R5,
	PLAYER_JUMP_R6,
	PLAYER_JUMP_L1,
	PLAYER_JUMP_L2,
	PLAYER_JUMP_L3,
	PLAYER_JUMP_L4,
	PLAYER_JUMP_L5,
	PLAYER_JUMP_L6,
	PLAYER_RUN_BODY_R,
	PLAYER_RUN_BODY_L,
	PLAYER_RUN_LEG_R1,
	PLAYER_RUN_LEG_R2,
	PLAYER_RUN_LEG_R3,
	PLAYER_RUN_LEG_R4,
	PLAYER_RUN_LEG_L1,
	PLAYER_RUN_LEG_L2,
	PLAYER_RUN_LEG_L3,
	PLAYER_RUN_LEG_L4,
	PLAYER_RUN_ATTACK_R1,
	PLAYER_RUN_ATTACK_R2,
	PLAYER_RUN_ATTACK_R3,
	PLAYER_RUN_ATTACK_R4,
	PLAYER_RUN_ATTACK_L1,
	PLAYER_RUN_ATTACK_L2,
	PLAYER_RUN_ATTACK_L3,
	PLAYER_RUN_ATTACK_L4,
	PLAYER_JUMP_ATTACK_R1,
	PLAYER_JUMP_ATTACK_R2,
	PLAYER_JUMP_ATTACK_R3,
	PLAYER_JUMP_ATTACK_R4,
	PLAYER_JUMP_ATTACK_L1,
	PLAYER_JUMP_ATTACK_L2,
	PLAYER_JUMP_ATTACK_L3,
	PLAYER_JUMP_ATTACK_L4,
	PLAYER_ATTACK1_R1,
	PLAYER_ATTACK1_R2,
	PLAYER_ATTACK1_R3,
	PLAYER_ATTACK1_R4,
	PLAYER_ATTACK1_L1,
	PLAYER_ATTACK1_L2,
	PLAYER_ATTACK1_L3,
	PLAYER_ATTACK1_L4,
	PLAYER_ATTACK2_R1,
	PLAYER_ATTACK2_R2,
	PLAYER_ATTACK2_R3,
	PLAYER_ATTACK2_R4,
	PLAYER_ATTACK2_L1,
	PLAYER_ATTACK2_L2,
	PLAYER_ATTACK2_L3,
	PLAYER_ATTACK2_L4,
	PLAYER_SIT_ATTACK_R1,
	PLAYER_SIT_ATTACK_R2,
	PLAYER_SIT_ATTACK_R3,
	PLAYER_SIT_ATTACK_R4,
	PLAYER_SIT_ATTACK_L1,
	PLAYER_SIT_ATTACK_L2,
	PLAYER_SIT_ATTACK_L3,
	PLAYER_SIT_ATTACK_L4,

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
	HDC memDC;
	HBITMAP hBitmap = (HBITMAP)INVALID_HANDLE_VALUE;
	HBITMAP hOldBitmap = (HBITMAP)INVALID_HANDLE_VALUE;
	int width = 0;
	int height = 0;
	int centerX = 0;
	int centerY = 0;
	bool isLoaded = false;

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

	static bool GetSpriteSize(SpriteIndex _index, int* _outW, int* _outH);
	static int GetWidth();
	static int GetHeight();
	static void SetBufferSize(int _w, int _h);
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
	static void DrawString(const WCHAR* _str, int _x, int _y, int _fontSize, COLORREF _color);
	static void DrawString(const WCHAR* _str, int _x, int _y, const WCHAR* _font, int _fontSize, COLORREF _color);
	static void DrawLine(float _startX, float _startY, float _endX, float _endY);
	
	// 이미지 스프라이트
	static bool LoadSprite(SpriteIndex _index, const char* _fileName, int _centerX, int _centerY);
	static void ReleaseSprite(int _index);
	static void DrawSprite(SpriteType _type, SpriteIndex _index, int destX, int destY);
	static void DrawSprite(SpriteType _type, SpriteIndex _index, int destX, int destY, int destW, int destH);
	//특정 메모리 위치에 이미지를 출력한다(클리핑 처리)
	static void DrawImage(SpriteIndex spriteIndex, int destX, int destY, int len = 100);
	// 버퍼 스왑
	static void Flip();

	
private:
	HDC hdc;
	HBITMAP hBackBitmap;
	HDC hBackBufferDC;
	RECT area = { 0,0,dfCLIENT_WIDTH,dfCLIENT_HEIGHT };

	Sprite* pSprite = nullptr;
	DWORD colorKey = 0x00FFFFFF; // 투명색
	int width = 0;
	int height = 0;
	int pitch = 0;
	int bitCount = 0;

	// 늘어날 or 줄어들 사이즈
	int clientWidth = dfCLIENT_WIDTH;
	int clientHeight = dfCLIENT_HEIGHT;

	// 카메라 테스트용
	int x = 0;
	int y = 0;
};

