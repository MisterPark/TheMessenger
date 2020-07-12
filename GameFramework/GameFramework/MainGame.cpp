#include "pch.h"
#include "MainGame.h"
#include "IntroScene.h"
#include "TitleScene.h"

MainGame* pMainGame = nullptr;

MainGame::MainGame()
{
	width = dfWINDOW_WIDTH;
	height = dfWINDOW_HEIGHT;
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

void MainGame::PullScreen()
{
	if (pMainGame->isPullScreen) return;

	RECT rt;

	pMainGame->width = GetSystemMetrics(SM_CXSCREEN);
	pMainGame->height = GetSystemMetrics(SM_CYSCREEN);

	

	SetRect(&rt, 0, 0, pMainGame->width, pMainGame->height);

	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, FALSE);

	SetWindowPos(g_hwnd, NULL, -10, -35, rt.right - rt.left, rt.bottom - rt.top, 0);



}

int MainGame::GetClientWidth()
{
	return pMainGame->width;
}

int MainGame::GetClientHeight()
{
	return pMainGame->height;
}
