#pragma once


class MainGame
{
private:
	MainGame();
	~MainGame();

public:

	static MainGame* GetInstance();
	static void Initialize();
	static void Release();
	static void Run();
	static void Pause();
	static void Resume();
	static void Shutdown();
	static void FullScreen();
	static void ChangeScreenMode(bool _isFullScreen);

	static int GetClientWidth();
	static int GetClientHeight();

	bool isPause = false;
private:
	bool isShutdown = false;
	bool isFullScreen = false;
	
	int width = 0;
	int height = 0;
	DEVMODE windowMode;
	DEVMODE fullMode;
};

