#pragma once
#include <Windows.h>

enum class SpriteIndex
{
	NONE,
	// 타일셋
	STAGE1_TILE_SET,
	STAGE2_TILE_SET,

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
	// 스테이지2
	STAGE2_BG1,
	STAGE2_BG2,

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

	PLAYER_STICK_L1,
	PLAYER_STICK_L2,
	PLAYER_STICK_L3,
	PLAYER_STICK_L4,
	PLAYER_STICK_L5,
	PLAYER_STICK_L6,
	PLAYER_STICK_L7,
	PLAYER_STICK_L8,
	PLAYER_STICK_R1,
	PLAYER_STICK_R2,
	PLAYER_STICK_R3,
	PLAYER_STICK_R4,
	PLAYER_STICK_R5,
	PLAYER_STICK_R6,
	PLAYER_STICK_R7,
	PLAYER_STICK_R8,

	// 몬스터
	GREEN_KAPPA_L1,
	GREEN_KAPPA_L2,
	GREEN_KAPPA_L3,
	GREEN_KAPPA_L4,
	GREEN_KAPPA_R1,
	GREEN_KAPPA_R2,
	GREEN_KAPPA_R3,
	GREEN_KAPPA_R4,

	SCURUBU_L1,
	SCURUBU_L2,
	SCURUBU_L3,
	SCURUBU_L4,

	FIRE_BALL_L1,
	FIRE_BALL_L2,
	FIRE_BALL_L3,
	FIRE_BALL_L4,
	FIRE_BALL_R1,
	FIRE_BALL_R2,
	FIRE_BALL_R3,
	FIRE_BALL_R4,

	RANGED_KAPPA_L1,
	RANGED_KAPPA_L2,
	RANGED_KAPPA_L3,
	RANGED_KAPPA_L4,
	RANGED_KAPPA_L5,
	RANGED_KAPPA_L6,
	RANGED_KAPPA_L7,
	RANGED_KAPPA_L8,
	RANGED_KAPPA_R1,
	RANGED_KAPPA_R2,
	RANGED_KAPPA_R3,
	RANGED_KAPPA_R4,
	RANGED_KAPPA_R5,
	RANGED_KAPPA_R6,
	RANGED_KAPPA_R7,
	RANGED_KAPPA_R8,

	RUN_KAPPA_L1,
	RUN_KAPPA_L2,
	RUN_KAPPA_L3,
	RUN_KAPPA_L4,
	RUN_KAPPA_L5,
	
	BLUE_BALL,
	BLUE_KAPPA_L1,
	BLUE_KAPPA_L2,
	BLUE_KAPPA_L3,
	BLUE_KAPPA_L4,
	BLUE_KAPPA_L5,
	BLUE_KAPPA_L6,
	BLUE_KAPPA_L7,
	BLUE_KAPPA_L8,
	BLUE_KAPPA_L9,
	BLUE_KAPPA_L10,
	BLUE_KAPPA_L11,
	BLUE_KAPPA_L12,

	BLUE_KAPPA_R1,
	BLUE_KAPPA_R2,
	BLUE_KAPPA_R3,
	BLUE_KAPPA_R4,
	BLUE_KAPPA_R5,
	BLUE_KAPPA_R6,
	BLUE_KAPPA_R7,
	BLUE_KAPPA_R8,
	BLUE_KAPPA_R9,
	BLUE_KAPPA_R10,
	BLUE_KAPPA_R11,
	BLUE_KAPPA_R12,

	// 이펙트
	EFFECT01_L1,
	EFFECT01_L2,
	EFFECT01_L3,
	EFFECT01_L4,
	EFFECT01_R1,
	EFFECT01_R2,
	EFFECT01_R3,
	EFFECT01_R4,

	EFFECT_EXPLOSION1,
	EFFECT_EXPLOSION2,
	EFFECT_EXPLOSION3,
	EFFECT_EXPLOSION4,
	EFFECT_EXPLOSION5,
	EFFECT_EXPLOSION6,
	
	// HUD
	HUD_HP_01,
	HUD_HP_02,
	HUD_CRISTAL,

	// 보스
	LEAF_BORN_01,
	LEAF_BORN_02,
	LEAF_BORN_03,
	LEAF_BORN_04,
	LEAF_BORN_05,
	LEAF_BORN_06,
	LEAF_BORN_07,
	LEAF_BORN_08,
	LEAF_BORN_09,
	LEAF_BORN_10,
	LEAF_BORN_11,
	LEAF_BORN_12,
	LEAF_BORN_13,
	LEAF_BORN_14,
	LEAF_BORN_15,
	LEAF_BORN_16,
	LEAF_BORN_17,
	LEAF_BORN_18,
	LEAF_BORN_19,
	LEAF_BORN_20,

	LEAF_IDLE_L1,
	LEAF_IDLE_L2,
	LEAF_IDLE_L3,
	LEAF_IDLE_L4,
	LEAF_IDLE_R1,
	LEAF_IDLE_R2,
	LEAF_IDLE_R3,
	LEAF_IDLE_R4,

	LEAF_WALK_L1,
	LEAF_WALK_L2,
	LEAF_WALK_L3,
	LEAF_WALK_L4,
	LEAF_WALK_R1,
	LEAF_WALK_R2,
	LEAF_WALK_R3,
	LEAF_WALK_R4,

	LEAF_JUMP_L1,
	LEAF_JUMP_L2,
	LEAF_JUMP_L3,
	LEAF_JUMP_L4,
	LEAF_ATTACK1_L1,
	LEAF_ATTACK1_L2,
	LEAF_ATTACK1_L3,
	LEAF_ATTACK1_L4,

	LEAF_JUMP_R1,
	LEAF_JUMP_R2,
	LEAF_JUMP_R3,
	LEAF_JUMP_R4,
	LEAF_ATTACK1_R1,
	LEAF_ATTACK1_R2,
	LEAF_ATTACK1_R3,
	LEAF_ATTACK1_R4,

	LEAF_ATTACK2_L1,
	LEAF_ATTACK2_L2,
	LEAF_ATTACK2_L3,
	LEAF_ATTACK2_L4,
	LEAF_ATTACK2_L5,
	LEAF_ATTACK2_R1,
	LEAF_ATTACK2_R2,
	LEAF_ATTACK2_R3,
	LEAF_ATTACK2_R4,
	LEAF_ATTACK2_R5,

	LEAF_ATTACKED_L1,
	LEAF_ATTACKED_L2,
	LEAF_ATTACKED_R1,
	LEAF_ATTACKED_R2,

	LEAF_RING_01,
	LEAF_RING_02,
	LEAF_RING_03,
	LEAF_RING_04,

	END,
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
	static bool GetSpriteCenter(SpriteIndex _index, int* _outX, int* _outY);
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
	static void DrawLine(float _startX, float _startY, float _endX, float _endY, COLORREF _color);
	
	// 이미지 스프라이트
	static bool LoadSprite(SpriteIndex _index, const char* _fileName, int _centerX, int _centerY);
	static void ReleaseSprite(int _index);
	static void DrawSprite(SpriteType _type, SpriteIndex _index, int destX, int destY);
	static void DrawSprite(SpriteType _type, SpriteIndex _index, int destX, int destY, int destW, int destH);
	static void DrawTile(SpriteType _type, SpriteIndex _index, int _tileOffset, int destX, int destY);
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

