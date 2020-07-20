#include "pch.h"
#include "Camera.h"
#include "GameObject.h"

Camera* pCamera = nullptr;

Camera::Camera()
{
	position = { 0,0 };
}

Camera::~Camera()
{
}

Camera* Camera::GetInstance()
{
	if (pCamera == nullptr)
	{
		pCamera = new Camera;
	}
	return pCamera;
}

void Camera::Release()
{
	delete pCamera;
}

void Camera::Update()
{
	if (InputManager::GetKey(VK_NUMPAD4))
	{
		pCamera->position.x -= 1;
	}
	if (InputManager::GetKey(VK_NUMPAD6))
	{
		pCamera->position.x += 1;
	}
	if (InputManager::GetKey(VK_NUMPAD8))
	{
		pCamera->position.y -= 1;
	}
	if (InputManager::GetKey(VK_NUMPAD5))
	{
		pCamera->position.y += 1;
	}
	if (InputManager::GetKey(VK_NUMPAD7))
	{
		SetPosition(0, 0);
	}

	FollowTarget();
}

void Camera::SetPosition(int _x, int _y)
{
	pCamera->position.x = _x;
	pCamera->position.y = _y;
}

void Camera::SetTarget(GameObject* _target)
{
	pCamera->target = _target;
}

int Camera::GetX()
{
	return pCamera->position.x;
}

int Camera::GetY()
{
	return pCamera->position.y;
}

void Camera::FollowTarget()
{
	if (pCamera->target == nullptr)return;

	pCamera->position.x = pCamera->target->position.x - (RenderManager::GetWidth() / 2);
}
