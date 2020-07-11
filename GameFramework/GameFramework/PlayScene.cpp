#include "pch.h"
#include "PlayScene.h"

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
