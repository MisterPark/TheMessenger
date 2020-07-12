#include "pch.h"
#include "PlayScene.h"
#include "BackGround.h"

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::OnLoaded()
{

}

void PlayScene::OnUnloaded()
{
    ObjectManager::DestroyAll();
}

void PlayScene::Update()
{
}
