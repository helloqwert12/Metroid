#include "Collision.h"
#include <limits>


Collision::Collision()
{
}


Collision::~Collision()
{
}
 //hàm kiểm tra va chạm giữa 2 đi61 tượng
bool Collision::isColliding(GameObject& objectA, GameObject& objectB)
{
	float left = objectB.GetPosX() - (objectA.GetPosX() + objectA.GetWidth());
	float right = (objectB.GetPosX() + objectB.GetWidth()) - objectA.GetPosX();
	float top = objectB.GetPosY() - (objectA.GetPosY() + objectA.GetHeight());
	float bottom = (objectB.GetPosY() + objectB.GetHeight()) - objectA.GetPosY();

	return !(left > 0 || right < 0 || top < 0 || bottom > 0);
}
 //hàm kiểm tra 2 đối tượng có va chạm ko . Nếu có thì tính thời gian va chạm và thay đổi hướng
float Collision::sweptAABB(GameObject& object, GameObject& other ,float& normalx , float& normaly)
{
	float dxEntry=0, dxExit=0;
	float dyEntry=0, dyExit=0;

	// khoảng cách tới vật thể
	if (object.GetPosX() > 0.0f)
	{
		dxEntry = other.GetPosX() - (object.GetPosX() + object.GetWidth());
		dxExit = (other.GetPosX() + other.GetWidth()) - object.GetPosX();
	}
	else
	{
		dxEntry = (other.GetPosX() + other.GetWidth()) - object.GetPosX();
		dxExit = other.GetPosX() - (object.GetPosX() + object.GetWidth());
	}
	if (object.GetPosY() > 0.0f)
	{
		dyEntry = other.GetPosY() - (object.GetPosY() + object.GetHeight());
		dyExit = (other.GetPosY() + other.GetHeight()) - object.GetPosY();
	}
	else
	{
		dyEntry = (other.GetPosY() + other.GetHeight()) - object.GetPosY();
		dyExit = other.GetPosY() - (object.GetPosY() + object.GetHeight());
	}
	// tính thời gian va chạm theo trục
	float txEntry, txExit;
	float tyEntry, tyExit;

	if (object.GetVelocityX() == 0.0f) // đang đứng yên nên thời gian va chạm = vô cực
	{
		txEntry = -std::numeric_limits<float>::infinity();
		txExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		txEntry = dxEntry / object.GetVelocityX();
		txExit = dxExit / object.GetVelocityX();
	}
	if (object.GetVelocityY() == 0.0f)
	{
		tyEntry = -std::numeric_limits<float>::infinity();
		tyExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		tyEntry = dyEntry / object.GetVelocityY();
		tyExit = dyExit / object.GetVelocityY();
	}
	//thời gian va chạm là thời gian lớn nhất của 2 trục
	float entryTime = std::fmax(txEntry, tyEntry);
	// thời gian hết va chạm là thời gian nhỏ nhất
	float ExitTime = std::fmin(txExit, tyExit);

	// kiểm tra có thể va chạm không

	if (entryTime > ExitTime || (txEntry < 0.0f && tyEntry < 0.0f) || txEntry > 1.0f || tyEntry > 1.0f)
	{
		// đứng yên
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f; // ko va chạm trong frame này
	}
	// lấy hướng va chạm
	if (txEntry > tyEntry)
	{
		if (dxEntry > 0.0f)
		{
			normalx = 1.0f;
			normaly = 0.0f;
		}
		else
		{
			normalx = -1.0f;
			normaly = 0.0f;
		}
	}
	else
	{
		if (dyEntry > 0.0f)
		{
			normalx = 0.0f;
			normaly = 1.0f;
		}
		else
		{
			normalx = 0.0f;
			normaly = -1.0f;
		}
	}
	return entryTime;
}
