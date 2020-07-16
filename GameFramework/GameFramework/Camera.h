#pragma once
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
	static int GetX();
	static int GetY();

	Transform position;
};

