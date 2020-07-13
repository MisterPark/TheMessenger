#include "pch.h"
#include "MainGame.h"
#include "IntroScene.h"
#include "TitleScene.h"

MainGame* pMainGame = nullptr;

MainGame::MainGame()
{
	width = dfCLIENT_WIDTH;
	height = dfCLIENT_HEIGHT;

	fullMode.dmSize = sizeof(DEVMODE);
	fullMode.dmPelsWidth = GetSystemMetrics(SM_CXSCREEN);
	fullMode.dmPelsHeight = GetSystemMetrics(SM_CYSCREEN);
	fullMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;

	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &windowMode);

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

	RenderManager::LoadSprite(0, "Sprites\\CutScene\\Intro.bmp", 0, 0);
	//RenderManager::LoadSprite(0, "Sprites\\_Map.bmp", 0, 0);


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

void MainGame::FullScreen()
{
	if (!pMainGame->isFullScreen)
	{
		ChangeScreenMode(true);
		//pMainGame->width = GetSystemMetrics(SM_CXSCREEN);
		//pMainGame->height = GetSystemMetrics(SM_CYSCREEN);
		//RECT rt = { 0,0,pMainGame->width,pMainGame->height };
		//RenderManager::SetClientSize(pMainGame->width, pMainGame->height);
		//SetWindowPos(g_hwnd, HWND_TOPMOST, 0, 0, pMainGame->width, pMainGame->height, SWP_SHOWWINDOW);
		//

		//HWND taskbar = FindWindowW(L"Shell_TrayWnd", NULL);
		//if (taskbar != NULL) {
		//	ShowWindow(taskbar, SW_HIDE);
		//	UpdateWindow(taskbar);
		//}

		//DEVMODE dm;
		//dm.dmSize = sizeof(DEVMODE);
		//dm.dmBitsPerPel = 32;
		//dm.dmPelsWidth = pMainGame->width;
		//dm.dmPelsHeight = pMainGame->height;
		//dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
		//ChangeDisplaySettings(&dm, CDS_FULLSCREEN);
	}
	else
	{
		ChangeScreenMode(false);
		//pMainGame->width = dfCLIENT_WIDTH;
		//pMainGame->height = dfCLIENT_HEIGHT;
		//RenderManager::SetClientSize(pMainGame->width, pMainGame->height);
		//SetWindowPos(g_hwnd, HWND_TOP, 0, 0, pMainGame->width, pMainGame->height, SWP_FRAMECHANGED);

		//HWND taskbar = FindWindowW(L"Shell_TrayWnd", NULL);
		//if (taskbar != NULL) {
		//	ShowWindow(taskbar, SW_SHOW);
		//	UpdateWindow(taskbar);
		//}
	}

	pMainGame->isFullScreen = !pMainGame->isFullScreen;
	
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
		pMainGame->width = dfCLIENT_WIDTH;
		pMainGame->height = dfCLIENT_HEIGHT;
		RenderManager::SetClientSize(pMainGame->width, pMainGame->height);

		// 윈도우 크기 설정
		//SetRect(&rect, 0, 0, pMainGame->width, pMainGame->height);
		//AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
		SetWindowPos(g_hwnd, HWND_TOP, 0, 0, dfCLIENT_WIDTH, dfCLIENT_HEIGHT, SWP_SHOWWINDOW);
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
