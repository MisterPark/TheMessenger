#pragma once

class GameObject;

class Camera
{
private:
	Camera();
	~Camera();

public:
	static Camera* GetInstance();
	static void Release();
	static void Update();

	static void SetPosition(int _x, int _y);
	static void SetTarget(GameObject* _target);
	static int GetX();
	static int GetY();

	static void FollowTarget();

	Transform position;
	GameObject* target = nullptr;
};

