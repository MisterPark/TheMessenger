#include "pch.h"
#include "Camera.h"

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


}

void Camera::SetPosition(int _x, int _y)
{
	pCamera->position.x = _x;
	pCamera->position.y = _y;
}

int Camera::GetX()
{
	return pCamera->position.x;
}

int Camera::GetY()
{
	return pCamera->position.y;
}
