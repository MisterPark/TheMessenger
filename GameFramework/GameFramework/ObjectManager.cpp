#include "pch.h"
#include "ObjectManager.h"
#include "Character.h"
#include "Player.h"
#include "UI.h"
#include "BackGround.h"
#include "SkyBox.h"
#include "SkyBox2.h"
#include "Logo.h"
#include "SelectBox.h"
#include "HUD_Bar.h"
#include "Label.h"
#include "BackTile.h"
#include "Tile.h"
#include "Monster.h"
#include "Effect.h"
#include "GreenKappa.h"
#include "BlueKappa.h"
#include "RunKappa.h"
#include "Scurubu.h"
#include "BlueBall.h"
#include "RangedKappa.h"
#include "Fireball.h"
#include "ExplosionEffect.h"
#include "LeafMonster.h"
#include "LeafRing.h"
#include "MultiExplosionEffect.h"
#include "CrystalItem.h"
#include "HPItem.h"
#include "EndingCredit.h"

ObjectManager* pObjectManager = nullptr;
int lastUid = 0;

ObjectManager::ObjectManager()
{
	player = Player::GetInstance();
	CollisionManager::RegisterObject(player);
	BackGround::GetInstance();
	SkyBox::GetInstance();
	SkyBox2::GetInstance();
}

ObjectManager::~ObjectManager()
{
	Player::Release();
	player = nullptr;
	CollisionManager::DisregisterObject(player);
	BackGround::Release();
	SkyBox::Release();
	SkyBox2::Release();
}

ObjectManager * ObjectManager::GetInstance()
{
	if (pObjectManager == nullptr)
	{
		pObjectManager = new ObjectManager;
	}
	return pObjectManager;
}

GameObject * ObjectManager::CreateObject(ObjectType _type)
{
	GameObject* pObj = nullptr;
	switch (_type)
	{
	case ObjectType::BACK_TILE:
		pObj = new BackTile;
		break;
	case ObjectType::TILE:
		pObj = new Tile;
		break;
	case ObjectType::MONSTER:
		pObj = new Monster;
		break;
	case ObjectType::GREEN_KAPPA:
		pObj = new GreenKappa;
		break;
	case ObjectType::BLUE_BALL:
		pObj = new BlueBall;
		break;
	case ObjectType::BLUE_KAPPA:
		pObj = new BlueKappa;
		break;
	case ObjectType::RUN_KAPPA:
		pObj = new RunKappa;
		break;
	case ObjectType::FIRE_BALL:
		pObj = new Fireball;
		break;
	case ObjectType::RANGED_KAPPA:
		pObj = new RangedKappa;
		break;
	case ObjectType::SCURUBU:
		pObj = new Scurubu;
		break;
	case ObjectType::ITEM_CRYSTAL:
		pObj = new CrystalItem;
		break;
	case ObjectType::ITEM_HP:
		pObj = new HPItem;
		break;
	case ObjectType::PLAYER:
		return Player::GetInstance();
	case ObjectType::LEAF_RING:
		pObj = new LeafRing;
		break;
	case ObjectType::LEAF_MONSTER:
		pObj = new LeafMonster;
		break;
	case ObjectType::EFFECT:
		pObj = new Effect;
		break;
	case ObjectType::EFFECT_EXPLOSION:
		pObj = new ExplosionEffect;
		break;
	case ObjectType::EFFECT_MULTI_EXPLOSION:
		pObj = new MultiExplosionEffect;
		break;
	case ObjectType::UI:
		pObj = new UI();
		break;
	case ObjectType::LOGO:
		pObj = new Logo();
		break;
	case ObjectType::SELECT_BOX:
		pObj = new SelectBox();
		break;
	case ObjectType::HUD_BAR:
		pObj = new HUD_Bar();
		break;
	
	case ObjectType::LABEL:
		pObj = new Label;
		break;
	case ObjectType::ENDING_CREDIT:
		pObj = new EndingCredit;
		break;
	default:
		return nullptr;
	}

	pObj->type = _type;
	pObj->uid = ++lastUid;
	pObjectManager->objectTable[(int)_type].push_back(pObj);

	if (dynamic_cast<Character*>(pObj) != nullptr)
	{
		CollisionManager::RegisterObject(pObj);
	}

	return pObj;
}

bool ObjectManager::DeleteObject(GameObject * _target)
{
	auto& objList = pObjectManager->objectTable[(int)_target->type];
	
	auto target = find(objList.begin(), objList.end(), _target);
	if (target != objList.end())
	{
		_target->Die();
		return true;
	}
	return false;
}

void ObjectManager::DestroyAll()
{
	auto& objTable = pObjectManager->objectTable;
	for (auto&objList  : objTable)
	{
		for (auto& iter : objList)
		{
			iter->Die();
		}
	}
}

void ObjectManager::DestroyAll(ObjectType _type)
{
	auto& objList = pObjectManager->objectTable[(int)_type];
	for (auto iter : objList)
	{
		iter->Die();
	}
}


int ObjectManager::FindTopStickTileY(GameObject* _stickTile)
{
	if (_stickTile == nullptr) return 0;

	int minY = 999999;
	auto& tileList = pObjectManager->objectTable[(int)ObjectType::TILE];
	auto iter = tileList.begin();
	auto end = tileList.end();
	for (; iter != end; ++iter)
	{
		Tile* tile = (Tile*)(*iter);
		if ((tile->option & dfTILE_OPTION_STICK) == false) continue;
		if (_stickTile->position.x != tile->position.x) continue;
		minY = min(minY, tile->position.y);
	}

	return minY;
}

void ObjectManager::Release()
{
	delete pObjectManager;
	pObjectManager = nullptr;
}

void ObjectManager::Update()
{
	BackGround::GetInstance()->Update();
	SkyBox::GetInstance()->Update();
	SkyBox2::GetInstance()->Update();
	Player::GetInstance()->Update();

	auto& objTable = pObjectManager->objectTable;
	for (auto& objList : objTable)
	{
		for (auto& iter : objList)
		{
			if (!iter->isEnable) continue;
			iter->Update();
		}
	}
	
}

void ObjectManager::LateUpdate()
{
	GameObject* target = nullptr;

	auto& objTable = pObjectManager->objectTable;
	for (auto& objList : objTable)
	{
			auto iter = objList.begin();
			auto end = objList.end();
			for (; iter != end;)
			{
				target = *iter;
				if (target->isDead)
				{
					iter = objList.erase(iter);

					if (dynamic_cast<Character*>(target) != nullptr)
					{
						CollisionManager::DisregisterObject(target);
					}

					delete target;
				}
				else
				{
					++iter;
				}
			}
	}

	
	
	
}

void ObjectManager::Render()
{
	BackGround::GetInstance()->Render();
	SkyBox::GetInstance()->Render();
	SkyBox2::GetInstance()->Render();
	Player::GetInstance()->Render();

	auto& objTable = pObjectManager->objectTable;
	for (auto& objList : objTable)
	{
		for (auto& iter : objList)
		{
			if (!iter->isVisible)continue;
			iter->Render();
		}
	}

	// ����׿�
	TimeManager::RenderFPS();
	Player::RenderPlayerInfo();
}

bool ObjectManager::IsVisibleCollider()
{
	return pObjectManager->isVisibleCollider;
}

void ObjectManager::SetVisibleCollider(bool _isVisible)
{
	pObjectManager->isVisibleCollider = _isVisible;
}
