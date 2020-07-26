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

	CollisionManager::GetInstance();
	InputManager::GetInstance();
	ObjectManager::GetInstance();
	RenderManager::GetInstance();
	SceneManager::GetInstance();
	
	Camera::GetInstance();
	TileManager::GetInstance();
	FileManager::GetInstance();

	RenderManager::LoadSprite(SpriteIndex::STAGE1_TILE_SET, "Sprites\\Stage1\\NinjaVillageTileset_8.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::STAGE2_TILE_SET, "Sprites\\Stage2\\AutumnHillsTileset_8.bmp", 0, 0);

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
	RenderManager::LoadSprite(SpriteIndex::STAGE2_BG1, "Sprites\\Stage2\\AutumnHills_RoomBackground01A_8.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::STAGE2_BG2, "Sprites\\Stage2\\AutumnHills_RoomBackground01B_8.bmp", 0, 0);


	RenderManager::LoadSprite(SpriteIndex::PLAYER_IDLE_R, "Sprites\\Player\\player_idle_R.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_IDLE_L, "Sprites\\Player\\player_idle_L.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACKED_R, "Sprites\\Player\\player_attacked_R.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACKED_L, "Sprites\\Player\\player_attacked_L.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SITDOWN_R, "Sprites\\Player\\player_sitdown_R.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SITDOWN_L, "Sprites\\Player\\player_sitdown_L.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R1, "Sprites\\Player\\player_jump_R1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R2, "Sprites\\Player\\player_jump_R2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R3, "Sprites\\Player\\player_jump_R3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R4, "Sprites\\Player\\player_jump_R4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R5, "Sprites\\Player\\player_jump_R5.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_R6, "Sprites\\Player\\player_jump_R6.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L1, "Sprites\\Player\\player_jump_L1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L2, "Sprites\\Player\\player_jump_L2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L3, "Sprites\\Player\\player_jump_L3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L4, "Sprites\\Player\\player_jump_L4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L5, "Sprites\\Player\\player_jump_L5.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_L6, "Sprites\\Player\\player_jump_L6.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_BODY_R, "Sprites\\Player\\player_runbody_R.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_BODY_L, "Sprites\\Player\\player_runbody_L.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_R1, "Sprites\\Player\\player_runleg_R1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_R2, "Sprites\\Player\\player_runleg_R2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_R3, "Sprites\\Player\\player_runleg_R3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_R4, "Sprites\\Player\\player_runleg_R4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_L1, "Sprites\\Player\\player_runleg_L1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_L2, "Sprites\\Player\\player_runleg_L2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_L3, "Sprites\\Player\\player_runleg_L3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_LEG_L4, "Sprites\\Player\\player_runleg_L4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_R1, "Sprites\\Player\\player_runattack_R1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_R2, "Sprites\\Player\\player_runattack_R2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_R3, "Sprites\\Player\\player_runattack_R3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_R4, "Sprites\\Player\\player_runattack_R4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_L1, "Sprites\\Player\\player_runattack_L1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_L2, "Sprites\\Player\\player_runattack_L2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_L3, "Sprites\\Player\\player_runattack_L3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_RUN_ATTACK_L4, "Sprites\\Player\\player_runattack_L4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_R1, "Sprites\\Player\\player_jumpattack_R1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_R2, "Sprites\\Player\\player_jumpattack_R2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_R3, "Sprites\\Player\\player_jumpattack_R3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_R4, "Sprites\\Player\\player_jumpattack_R4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_L1, "Sprites\\Player\\player_jumpattack_L1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_L2, "Sprites\\Player\\player_jumpattack_L2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_L3, "Sprites\\Player\\player_jumpattack_L3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_JUMP_ATTACK_L4, "Sprites\\Player\\player_jumpattack_L4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_R1, "Sprites\\Player\\player_attack1_R1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_R2, "Sprites\\Player\\player_attack1_R2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_R3, "Sprites\\Player\\player_attack1_R3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_R4, "Sprites\\Player\\player_attack1_R4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_L1, "Sprites\\Player\\player_attack1_L1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_L2, "Sprites\\Player\\player_attack1_L2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_L3, "Sprites\\Player\\player_attack1_L3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK1_L4, "Sprites\\Player\\player_attack1_L4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_R1, "Sprites\\Player\\player_attack2_R1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_R2, "Sprites\\Player\\player_attack2_R2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_R3, "Sprites\\Player\\player_attack2_R3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_R4, "Sprites\\Player\\player_attack2_R4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_L1, "Sprites\\Player\\player_attack2_L1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_L2, "Sprites\\Player\\player_attack2_L2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_L3, "Sprites\\Player\\player_attack2_L3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_ATTACK2_L4, "Sprites\\Player\\player_attack2_L4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_R1, "Sprites\\Player\\player_sitdown_attack_R1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_R2, "Sprites\\Player\\player_sitdown_attack_R2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_R3, "Sprites\\Player\\player_sitdown_attack_R3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_R4, "Sprites\\Player\\player_sitdown_attack_R4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_L1, "Sprites\\Player\\player_sitdown_attack_L1.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_L2, "Sprites\\Player\\player_sitdown_attack_L2.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_L3, "Sprites\\Player\\player_sitdown_attack_L3.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_SIT_ATTACK_L4, "Sprites\\Player\\player_sitdown_attack_L4.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_L1, "Sprites\\Player\\PlayerStickL_04.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_L2, "Sprites\\Player\\PlayerStickL_03.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_L3, "Sprites\\Player\\PlayerStickL_02.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_L4, "Sprites\\Player\\PlayerStickL_01.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_L5, "Sprites\\Player\\PlayerStickL_08.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_L6, "Sprites\\Player\\PlayerStickL_07.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_L7, "Sprites\\Player\\PlayerStickL_06.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_L8, "Sprites\\Player\\PlayerStickL_05.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_R1, "Sprites\\Player\\PlayerStickR_01.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_R2, "Sprites\\Player\\PlayerStickR_02.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_R3, "Sprites\\Player\\PlayerStickR_03.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_R4, "Sprites\\Player\\PlayerStickR_04.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_R5, "Sprites\\Player\\PlayerStickR_05.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_R6, "Sprites\\Player\\PlayerStickR_06.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_R7, "Sprites\\Player\\PlayerStickR_07.bmp", 30, 60);
	RenderManager::LoadSprite(SpriteIndex::PLAYER_STICK_R8, "Sprites\\Player\\PlayerStickR_08.bmp", 30, 60);


	RenderManager::LoadSprite(SpriteIndex::GREEN_KAPPA_L1, "Sprites\\Monster\\GreenKappaL_01.bmp", 16, 64);
	RenderManager::LoadSprite(SpriteIndex::GREEN_KAPPA_L2, "Sprites\\Monster\\GreenKappaL_02.bmp", 16, 64);
	RenderManager::LoadSprite(SpriteIndex::GREEN_KAPPA_L3, "Sprites\\Monster\\GreenKappaL_03.bmp", 16, 64);
	RenderManager::LoadSprite(SpriteIndex::GREEN_KAPPA_L4, "Sprites\\Monster\\GreenKappaL_04.bmp", 16, 64);
	RenderManager::LoadSprite(SpriteIndex::GREEN_KAPPA_R1, "Sprites\\Monster\\GreenKappaR_04.bmp", 16, 64);
	RenderManager::LoadSprite(SpriteIndex::GREEN_KAPPA_R2, "Sprites\\Monster\\GreenKappaR_03.bmp", 16, 64);
	RenderManager::LoadSprite(SpriteIndex::GREEN_KAPPA_R3, "Sprites\\Monster\\GreenKappaR_02.bmp", 16, 64);
	RenderManager::LoadSprite(SpriteIndex::GREEN_KAPPA_R4, "Sprites\\Monster\\GreenKappaR_01.bmp", 16, 64);

	RenderManager::LoadSprite(SpriteIndex::SCURUBU_L1, "Sprites\\Monster\\Scurubu_01.bmp", 11, 22);
	RenderManager::LoadSprite(SpriteIndex::SCURUBU_L2, "Sprites\\Monster\\Scurubu_02.bmp", 11, 22);
	RenderManager::LoadSprite(SpriteIndex::SCURUBU_L3, "Sprites\\Monster\\Scurubu_03.bmp", 11, 22);
	RenderManager::LoadSprite(SpriteIndex::SCURUBU_L4, "Sprites\\Monster\\Scurubu_04.bmp", 11, 22);

	RenderManager::LoadSprite(SpriteIndex::FIRE_BALL_L1, "Sprites\\Monster\\FireBallL_01.bmp", 8, 8);
	RenderManager::LoadSprite(SpriteIndex::FIRE_BALL_L2, "Sprites\\Monster\\FireBallL_02.bmp", 8, 8);
	RenderManager::LoadSprite(SpriteIndex::FIRE_BALL_L3, "Sprites\\Monster\\FireBallL_03.bmp", 8, 8);
	RenderManager::LoadSprite(SpriteIndex::FIRE_BALL_L4, "Sprites\\Monster\\FireBallL_04.bmp", 8, 8);
	RenderManager::LoadSprite(SpriteIndex::FIRE_BALL_R1, "Sprites\\Monster\\FireBallR_01.bmp", 8, 8);
	RenderManager::LoadSprite(SpriteIndex::FIRE_BALL_R2, "Sprites\\Monster\\FireBallR_02.bmp", 8, 8);
	RenderManager::LoadSprite(SpriteIndex::FIRE_BALL_R3, "Sprites\\Monster\\FireBallR_03.bmp", 8, 8);
	RenderManager::LoadSprite(SpriteIndex::FIRE_BALL_R4, "Sprites\\Monster\\FireBallR_04.bmp", 8, 8);

	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_L1, "Sprites\\Monster\\RangedKappaL_01.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_L2, "Sprites\\Monster\\RangedKappaL_02.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_L3, "Sprites\\Monster\\RangedKappaL_03.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_L4, "Sprites\\Monster\\RangedKappaL_04.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_L5, "Sprites\\Monster\\RangedKappaL_05.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_L6, "Sprites\\Monster\\RangedKappaL_06.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_L7, "Sprites\\Monster\\RangedKappaL_07.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_L8, "Sprites\\Monster\\RangedKappaL_08.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_R1, "Sprites\\Monster\\RangedKappaR_04.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_R2, "Sprites\\Monster\\RangedKappaR_03.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_R3, "Sprites\\Monster\\RangedKappaR_02.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_R4, "Sprites\\Monster\\RangedKappaR_01.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_R5, "Sprites\\Monster\\RangedKappaR_08.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_R6, "Sprites\\Monster\\RangedKappaR_07.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_R7, "Sprites\\Monster\\RangedKappaR_06.bmp", 20, 40);
	RenderManager::LoadSprite(SpriteIndex::RANGED_KAPPA_R8, "Sprites\\Monster\\RangedKappaR_05.bmp", 20, 40);

	RenderManager::LoadSprite(SpriteIndex::RUN_KAPPA_L1, "Sprites\\Monster\\RunKappaL_01.bmp", 24, 48);
	RenderManager::LoadSprite(SpriteIndex::RUN_KAPPA_L2, "Sprites\\Monster\\RunKappaL_02.bmp", 24, 48);
	RenderManager::LoadSprite(SpriteIndex::RUN_KAPPA_L3, "Sprites\\Monster\\RunKappaL_03.bmp", 24, 48);
	RenderManager::LoadSprite(SpriteIndex::RUN_KAPPA_L4, "Sprites\\Monster\\RunKappaL_04.bmp", 24, 48);
	RenderManager::LoadSprite(SpriteIndex::RUN_KAPPA_L5, "Sprites\\Monster\\RunKappaL_05.bmp", 24, 48);

	RenderManager::LoadSprite(SpriteIndex::BLUE_BALL, "Sprites\\Monster\\BlueBall.bmp", 10, 10);

	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L1, "Sprites\\Monster\\BlueKappaL_01.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L2, "Sprites\\Monster\\BlueKappaL_02.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L3, "Sprites\\Monster\\BlueKappaL_03.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L4, "Sprites\\Monster\\BlueKappaL_04.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L5, "Sprites\\Monster\\BlueKappaL_05.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L6, "Sprites\\Monster\\BlueKappaL_06.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L7, "Sprites\\Monster\\BlueKappaL_07.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L8, "Sprites\\Monster\\BlueKappaL_08.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L9, "Sprites\\Monster\\BlueKappaL_09.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L10, "Sprites\\Monster\\BlueKappaL_10.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L11, "Sprites\\Monster\\BlueKappaL_11.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_L12, "Sprites\\Monster\\BlueKappaL_12.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R1, "Sprites\\Monster\\BlueKappaR_04.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R2, "Sprites\\Monster\\BlueKappaR_03.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R3, "Sprites\\Monster\\BlueKappaR_02.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R4, "Sprites\\Monster\\BlueKappaR_01.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R5, "Sprites\\Monster\\BlueKappaR_08.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R6, "Sprites\\Monster\\BlueKappaR_07.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R7, "Sprites\\Monster\\BlueKappaR_06.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R8, "Sprites\\Monster\\BlueKappaR_05.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R9, "Sprites\\Monster\\BlueKappaR_09.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R10, "Sprites\\Monster\\BlueKappaR_10.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R11, "Sprites\\Monster\\BlueKappaR_11.bmp", 20, 64);
	RenderManager::LoadSprite(SpriteIndex::BLUE_KAPPA_R12, "Sprites\\Monster\\BlueKappaR_12.bmp", 20, 64);

	RenderManager::LoadSprite(SpriteIndex::EFFECT01_L1, "Sprites\\Effect\\Effect01_L_01.bmp", 16, 8);
	RenderManager::LoadSprite(SpriteIndex::EFFECT01_L2, "Sprites\\Effect\\Effect01_L_02.bmp", 16, 8);
	RenderManager::LoadSprite(SpriteIndex::EFFECT01_L3, "Sprites\\Effect\\Effect01_L_03.bmp", 16, 8);
	RenderManager::LoadSprite(SpriteIndex::EFFECT01_L4, "Sprites\\Effect\\Effect01_L_04.bmp", 16, 8);
	RenderManager::LoadSprite(SpriteIndex::EFFECT01_R1, "Sprites\\Effect\\Effect01_R_01.bmp", 16, 8);
	RenderManager::LoadSprite(SpriteIndex::EFFECT01_R2, "Sprites\\Effect\\Effect01_R_02.bmp", 16, 8);
	RenderManager::LoadSprite(SpriteIndex::EFFECT01_R3, "Sprites\\Effect\\Effect01_R_03.bmp", 16, 8);
	RenderManager::LoadSprite(SpriteIndex::EFFECT01_R4, "Sprites\\Effect\\Effect01_R_04.bmp", 16, 8);

	RenderManager::LoadSprite(SpriteIndex::EFFECT_EXPLOSION1, "Sprites\\Effect\\ExplosionEffect_01.bmp", 15, 15);
	RenderManager::LoadSprite(SpriteIndex::EFFECT_EXPLOSION2, "Sprites\\Effect\\ExplosionEffect_02.bmp", 15, 15);
	RenderManager::LoadSprite(SpriteIndex::EFFECT_EXPLOSION3, "Sprites\\Effect\\ExplosionEffect_03.bmp", 15, 15);
	RenderManager::LoadSprite(SpriteIndex::EFFECT_EXPLOSION4, "Sprites\\Effect\\ExplosionEffect_04.bmp", 15, 15);
	RenderManager::LoadSprite(SpriteIndex::EFFECT_EXPLOSION5, "Sprites\\Effect\\ExplosionEffect_05.bmp", 15, 15);
	RenderManager::LoadSprite(SpriteIndex::EFFECT_EXPLOSION6, "Sprites\\Effect\\ExplosionEffect_06.bmp", 15, 15);
	
	RenderManager::LoadSprite(SpriteIndex::HUD_HP_01, "Sprites\\UI\\HP_HUD_01.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::HUD_HP_02, "Sprites\\UI\\HP_HUD_02.bmp", 0, 0);
	RenderManager::LoadSprite(SpriteIndex::HUD_CRISTAL, "Sprites\\UI\\Crystal_HUD.bmp", 0, 0);

	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_01, "Sprites\\Boss\\LeafMonsterL_01.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_02, "Sprites\\Boss\\LeafMonsterL_02.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_03, "Sprites\\Boss\\LeafMonsterL_03.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_04, "Sprites\\Boss\\LeafMonsterL_04.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_05, "Sprites\\Boss\\LeafMonsterL_05.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_06, "Sprites\\Boss\\LeafMonsterL_06.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_07, "Sprites\\Boss\\LeafMonsterL_07.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_08, "Sprites\\Boss\\LeafMonsterL_08.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_09, "Sprites\\Boss\\LeafMonsterL_09.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_10, "Sprites\\Boss\\LeafMonsterL_10.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_11, "Sprites\\Boss\\LeafMonsterL_11.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_12, "Sprites\\Boss\\LeafMonsterL_12.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_13, "Sprites\\Boss\\LeafMonsterL_13.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_14, "Sprites\\Boss\\LeafMonsterL_14.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_15, "Sprites\\Boss\\LeafMonsterL_15.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_16, "Sprites\\Boss\\LeafMonsterL_16.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_17, "Sprites\\Boss\\LeafMonsterL_17.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_18, "Sprites\\Boss\\LeafMonsterL_18.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_19, "Sprites\\Boss\\LeafMonsterL_19.bmp",60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_BORN_20, "Sprites\\Boss\\LeafMonsterL_20.bmp",60,120);

	RenderManager::LoadSprite(SpriteIndex::LEAF_IDLE_L1, "Sprites\\Boss\\LeafMonsterL_21.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_IDLE_L2, "Sprites\\Boss\\LeafMonsterL_22.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_IDLE_L3, "Sprites\\Boss\\LeafMonsterL_23.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_IDLE_L4, "Sprites\\Boss\\LeafMonsterL_24.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_IDLE_R1, "Sprites\\Boss\\LeafMonsterR_24.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_IDLE_R2, "Sprites\\Boss\\LeafMonsterR_23.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_IDLE_R3, "Sprites\\Boss\\LeafMonsterR_22.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_IDLE_R4, "Sprites\\Boss\\LeafMonsterR_21.bmp", 60,120);

	RenderManager::LoadSprite(SpriteIndex::LEAF_WALK_L1, "Sprites\\Boss\\LeafMonsterL_25.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_WALK_L2, "Sprites\\Boss\\LeafMonsterL_26.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_WALK_L3, "Sprites\\Boss\\LeafMonsterL_27.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_WALK_L4, "Sprites\\Boss\\LeafMonsterL_28.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_WALK_R1, "Sprites\\Boss\\LeafMonsterR_28.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_WALK_R2, "Sprites\\Boss\\LeafMonsterR_27.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_WALK_R3, "Sprites\\Boss\\LeafMonsterR_26.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_WALK_R4, "Sprites\\Boss\\LeafMonsterR_25.bmp", 60,120);

	RenderManager::LoadSprite(SpriteIndex::LEAF_JUMP_L1, "Sprites\\Boss\\LeafMonsterL_29.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_JUMP_L2, "Sprites\\Boss\\LeafMonsterL_30.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_JUMP_L3, "Sprites\\Boss\\LeafMonsterL_31.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_JUMP_L4, "Sprites\\Boss\\LeafMonsterL_33.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_JUMP_R1, "Sprites\\Boss\\LeafMonsterR_32.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_JUMP_R2, "Sprites\\Boss\\LeafMonsterR_31.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_JUMP_R3, "Sprites\\Boss\\LeafMonsterR_30.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_JUMP_R4, "Sprites\\Boss\\LeafMonsterR_36.bmp", 60,120);

	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK1_L1, "Sprites\\Boss\\LeafMonsterL_34.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK1_L2, "Sprites\\Boss\\LeafMonsterL_35.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK1_L3, "Sprites\\Boss\\LeafMonsterL_36.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK1_L4, "Sprites\\Boss\\LeafMonsterL_37.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK1_R1, "Sprites\\Boss\\LeafMonsterR_35.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK1_R2, "Sprites\\Boss\\LeafMonsterR_34.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK1_R3, "Sprites\\Boss\\LeafMonsterR_33.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK1_R4, "Sprites\\Boss\\LeafMonsterR_40.bmp", 60,120);
	
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK2_L1, "Sprites\\Boss\\LeafMonsterL_45.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK2_L2, "Sprites\\Boss\\LeafMonsterL_46.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK2_L3, "Sprites\\Boss\\LeafMonsterL_47.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK2_L4, "Sprites\\Boss\\LeafMonsterL_48.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK2_L5, "Sprites\\Boss\\LeafMonsterL_49.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK2_R1, "Sprites\\Boss\\LeafMonsterR_48.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK2_R2, "Sprites\\Boss\\LeafMonsterR_47.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK2_R3, "Sprites\\Boss\\LeafMonsterR_46.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK2_R4, "Sprites\\Boss\\LeafMonsterR_45.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACK2_R5, "Sprites\\Boss\\LeafMonsterR_52.bmp", 60,120);

	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACKED_L1, "Sprites\\Boss\\LeafMonsterL_38.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACKED_L2, "Sprites\\Boss\\LeafMonsterL_39.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACKED_R1, "Sprites\\Boss\\LeafMonsterR_39.bmp", 60,120);
	RenderManager::LoadSprite(SpriteIndex::LEAF_ATTACKED_R2, "Sprites\\Boss\\LeafMonsterR_38.bmp", 60,120);

	RenderManager::LoadSprite(SpriteIndex::LEAF_RING_01, "Sprites\\Boss\\LeafMonsterZ_01.bmp",60,60);
	RenderManager::LoadSprite(SpriteIndex::LEAF_RING_02, "Sprites\\Boss\\LeafMonsterZ_02.bmp",60,60);
	RenderManager::LoadSprite(SpriteIndex::LEAF_RING_03, "Sprites\\Boss\\LeafMonsterZ_03.bmp",60,60);
	RenderManager::LoadSprite(SpriteIndex::LEAF_RING_04, "Sprites\\Boss\\LeafMonsterZ_04.bmp",60,60);

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
	Camera::Release();
	TileManager::Release();
	FileManager::Release();
}

void MainGame::Run()
{
	
	InputManager::Update();
	if (pMainGame->isPause == false)
	{
		ObjectManager::Update();
	}
	Camera::Update();
	CollisionManager::Update();
	ObjectManager::LateUpdate();
	
	if (!TimeManager::SkipFrame())
	{
		RenderManager::Clear();
		ObjectManager::Render();
		TileManager::Render();
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
