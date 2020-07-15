#include "pch.h"
#include "MainGame.h"
#include "IntroScene.h"
#include "TitleScene.h"

MainGame* pMainGame = nullptr;

MainGame::MainGame()
{
	// 시작은 창모드로
	width = dfCLIENT_WIDTH;
	height = dfCLIENT_HEIGHT;

	// 풀스크린 모드 세팅
	fullMode.dmSize = sizeof(DEVMODE);
	fullMode.dmPelsWidth = GetSystemMetrics(SM_CXSCREEN);
	fullMode.dmPelsHeight = GetSystemMetrics(SM_CYSCREEN);
	fullMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;

	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &windowMode);
	// 창모드 (윈도우 크기랑, 작업영역 크기 저장)
	RECT windowRect;
	GetWindowRect(g_hwnd, &windowRect);
	windowWidth = windowRect.right - windowRect.left;
	windowHeight = windowRect.bottom - windowRect.top;
	RECT clientRect;
	GetClientRect(g_hwnd, &clientRect);
	windowClientWidth = clientRect.right - clientRect.left;
	windowClientHeight = clientRect.bottom - clientRect.top;

}

MainGame::~MainGame()
{
}

MainGame * MainGame::GetInstance()
{
	if (pMainGame == nullptr)
	{
		pMainGame = new MainGame();
	}
	return pMainGame;
}

void MainGame::Initialize()
{
	TimeManager::GetInstance();
	TimeManager::SetFrame(dfFPS);

	InputManager::GetInstance();
	ObjectManager::GetInstance();
	RenderManager::GetInstance();
	SceneManager::GetInstance();
	CollisionManager::GetInstance();

	RenderManager::LoadSprite(SpriteIndex::INTRO, "Sprites\\CutScene\\Intro.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::CUT_SCENE1, "Sprites\\CutScene\\CutScene1.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::CUT_SCENE2, "Sprites\\CutScene\\CutScene2.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::CUT_SCENE3, "Sprites\\CutScene\\CutScene3.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::CUT_SCENE4, "Sprites\\CutScene\\CutScene4.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::CUT_SCENE5, "Sprites\\CutScene\\CutScene5.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::CUT_SCENE6, "Sprites\\CutScene\\CutScene6.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::CUT_SCENE7, "Sprites\\CutScene\\CutScene7.bmp", 0, 0);

	RenderManager::LoadSprite(SpriteIndex::TITLE_BG, "Sprites\\Title\\TitleBackGround.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::TITLE_LOGO, "Sprites\\Title\\TitleLogo.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::GAMEOVER1, "Sprites\\Title\\GameOver1.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::GAMEOVER2, "Sprites\\Title\\GameOver2.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::UI_FRAME1, "Sprites\\Title\\ui_Frame1.bmp", 0, 0);

	RenderManager::LoadSprite(SpriteIndex::BLACKSCREEN, "Sprites\\BlackScreen.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::NINJA_BG_1, "Sprites\\Stage1\\NinjaVillage_Skybox_8.bmp", 0, 0);

	RenderManager::LoadSprite(SpriteIndex::PLAYER_IDLE_R, "Sprites\\Player\\player_idle_R.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_IDLE_L, "Sprites\\Player\\player_idle_L.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACKED_R, "Sprites\\Player\\player_attacked_R.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACKED_L, "Sprites\\Player\\player_attacked_L.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SITDOWN_R, "Sprites\\Player\\player_sitdown_R.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SITDOWN_L, "Sprites\\Player\\player_sitdown_L.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R1, "Sprites\\Player\\player_jump_R1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R2, "Sprites\\Player\\player_jump_R2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R3, "Sprites\\Player\\player_jump_R3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R4, "Sprites\\Player\\player_jump_R4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R5, "Sprites\\Player\\player_jump_R5.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R6, "Sprites\\Player\\player_jump_R6.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L1, "Sprites\\Player\\player_jump_L1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L2, "Sprites\\Player\\player_jump_L2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L3, "Sprites\\Player\\player_jump_L3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L4, "Sprites\\Player\\player_jump_L4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L5, "Sprites\\Player\\player_jump_L5.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L6, "Sprites\\Player\\player_jump_L6.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_BODY_R, "Sprites\\Player\\player_runbody_R.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_BODY_L, "Sprites\\Player\\player_runbody_L.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_R1, "Sprites\\Player\\player_runleg_R1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_R2, "Sprites\\Player\\player_runleg_R2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_R3, "Sprites\\Player\\player_runleg_R3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_R4, "Sprites\\Player\\player_runleg_R4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_L1, "Sprites\\Player\\player_runleg_L1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_L2, "Sprites\\Player\\player_runleg_L2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_L3, "Sprites\\Player\\player_runleg_L3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_L4, "Sprites\\Player\\player_runleg_L4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_R1, "Sprites\\Player\\player_runattack_R1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_R2, "Sprites\\Player\\player_runattack_R2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_R3, "Sprites\\Player\\player_runattack_R3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_R4, "Sprites\\Player\\player_runattack_R4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_L1, "Sprites\\Player\\player_runattack_L1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_L2, "Sprites\\Player\\player_runattack_L2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_L3, "Sprites\\Player\\player_runattack_L3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_L4, "Sprites\\Player\\player_runattack_L4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_R1, "Sprites\\Player\\player_jumpattack_R1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_R2, "Sprites\\Player\\player_jumpattack_R2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_R3, "Sprites\\Player\\player_jumpattack_R3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_R4, "Sprites\\Player\\player_jumpattack_R4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_L1, "Sprites\\Player\\player_jumpattack_L1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_L2, "Sprites\\Player\\player_jumpattack_L2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_L3, "Sprites\\Player\\player_jumpattack_L3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_L4, "Sprites\\Player\\player_jumpattack_L4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_R1, "Sprites\\Player\\player_attack1_R1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_R2, "Sprites\\Player\\player_attack1_R2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_R3, "Sprites\\Player\\player_attack1_R3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_R4, "Sprites\\Player\\player_attack1_R4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_L1, "Sprites\\Player\\player_attack1_L1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_L2, "Sprites\\Player\\player_attack1_L2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_L3, "Sprites\\Player\\player_attack1_L3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_L4, "Sprites\\Player\\player_attack1_L4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_R1, "Sprites\\Player\\player_attack2_R1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_R2, "Sprites\\Player\\player_attack2_R2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_R3, "Sprites\\Player\\player_attack2_R3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_R4, "Sprites\\Player\\player_attack2_R4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_L1, "Sprites\\Player\\player_attack2_L1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_L2, "Sprites\\Player\\player_attack2_L2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_L3, "Sprites\\Player\\player_attack2_L3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_L4, "Sprites\\Player\\player_attack2_L4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_R1, "Sprites\\Player\\player_sitdown_attack_R1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_R2, "Sprites\\Player\\player_sitdown_attack_R2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_R3, "Sprites\\Player\\player_sitdown_attack_R3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_R4, "Sprites\\Player\\player_sitdown_attack_R4.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_L1, "Sprites\\Player\\player_sitdown_attack_L1.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_L2, "Sprites\\Player\\player_sitdown_attack_L2.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_L3, "Sprites\\Player\\player_sitdown_attack_L3.bmp", 29, 59);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_L4, "Sprites\\Player\\player_sitdown_attack_L4.bmp", 29, 59);


	SceneManager::LoadScene<IntroScene>();
}

void MainGame::Release()
{
	SceneManager::Release();
	TimeManager::Release();
	ObjectManager::Release();
	RenderManager::Release();
	InputManager::Release();
	CollisionManager::Release();
}

void MainGame::Run()
{

	InputManager::Update();
	if (pMainGame->isPause == false)
	{
		ObjectManager::Update();
	}
	ObjectManager::LateUpdate();
	CollisionManager::Update();
	if (!TimeManager::SkipFrame())
	{
		RenderManager::Clear();
		ObjectManager::Render();
		//RenderManager::Present();
		RenderManager::Flip();
	}
	
	SceneManager::Update();
}

void MainGame::Pause()
{
	pMainGame->isPause = true;
}

void MainGame::Resume()
{
	pMainGame->isPause = false;
}

void MainGame::Shutdown()
{
	PostQuitMessage(0);
}

bool MainGame::IsFullScreen()
{
	return pMainGame->isFullScreen;
}

void MainGame::WindowMode()
{
	ChangeScreenMode(false);
}

void MainGame::FullScreen()
{
	ChangeScreenMode(true);
	
}

void MainGame::ChangeScreenMode(bool _isFullScreen)
{
	RECT rect;
	pMainGame->isFullScreen = _isFullScreen;
	if (_isFullScreen)
	{
		SetWindowLong(g_hwnd, GWL_STYLE, WS_POPUP);
		pMainGame->width = GetSystemMetrics(SM_CXSCREEN);
		pMainGame->height = GetSystemMetrics(SM_CYSCREEN);
		RenderManager::SetClientSize(pMainGame->width, pMainGame->height);
		SetWindowPos(g_hwnd, 0, 0, 0, pMainGame->width, pMainGame->height, SWP_SHOWWINDOW);
		ChangeDisplaySettings(&pMainGame->fullMode, CDS_FULLSCREEN);
	}
	else {
		// ChangeDisplaySettings(NULL, 0);
		SetWindowLong(g_hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);
		SetRect(&rect, 0, 0, dfCLIENT_WIDTH, dfCLIENT_HEIGHT);
		constexpr int WIDOW_STYLE = WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX;
		AdjustWindowRect(&rect, WIDOW_STYLE, false);
		//AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

		pMainGame->width = pMainGame->windowClientWidth;
		pMainGame->height = pMainGame->windowClientHeight;
		RenderManager::SetClientSize(pMainGame->width, pMainGame->height);

		// 윈도우 크기 설정
		
		SetWindowPos(g_hwnd, 0, 0, 0, pMainGame->windowWidth, pMainGame->windowHeight, SWP_SHOWWINDOW);
		ChangeDisplaySettings(&pMainGame->fullMode, CDS_RESET);
	}
}

int MainGame::GetClientWidth()
{
	return pMainGame->width;
}

int MainGame::GetClientHeight()
{
	return pMainGame->height;
}
