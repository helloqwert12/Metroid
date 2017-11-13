#include "Collision.h"
#include <limits>


Collision::Collision()
{
}


Collision::~Collision()
{
}
// hàm kiểm tra va chạm giữa 2 đi61 tượng
bool Collision::isColliding(GameObject objectA, GameObject objectB)
{
	float left = objectB.getPos_x() - (objectA.getPos_x + objectA.getWidth);
	float right = (objectB.getPos_x() + objectB.getWidth()) - objectA.getPos_x;
	float top = objectB.getPos_y() - (objectA.getPos_y + objectA.getHeight);
	float bottom = (objectB.getPos_y() + objectB.getHeight()) - objectA.getPos_y;

	return !(left > 0 || right < 0 || top < 0 || bottom > 0);
}
// hàm kiểm tra 2 đối tượng có va chạm ko . Nếu có thì tính thời gian va chạm và thay đổi hướng
float Collision::sweptAABB(GameObject object, GameObject other ,float& normalx , float& normaly)
{
	float dxEntry, dxExit;
	float dyEntry, dyExit;

	// khoảng cách tới vật thể
	if (object.getPos_x() > 0.0f)
	{
		dxEntry = other.getPos_x() - (object.getPos_x() + object.getWidth());
		dxExit = (other.getPos_x() + other.getWidth()) - object.getPos_x();
	}
	else
	{
		dxEntry = (other.getPos_x() + other.getWidth()) - object.getPos_x();
		dxExit = other.getPos_x() - (object.getPos_x() + object.getWidth());
	}
	if (object.getPos_y() > 0.0f)
	{
		dyEntry = other.getPos_y() - (object.getPos_y() + object.getHeight());
		dyExit = (other.getPos_y() + other.getHeight()) - object.getPos_y();
	}
	else
	{
		dyEntry = (other.getPos_y() + other.getHeight()) - object.getPos_y();
		dyExit = other.getPos_y() - (object.getPos_y() + object.getHeight());
	}
	// tính thời gian va chạm theo trục
	float txEntry, txExit;
	float tyEntry, tyExit;

	if (object.getVx() == 0.0f) // đang đứng yên nên thời gian va chạm = vô cực
	{
		txEntry = -std::numeric_limits<float>::infinity();
		txExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		txEntry = dxEntry / object.getVx();
		txExit = dxExit / object.getVx();
	}
	if (object.getVy() == 0.0f)
	{
		tyEntry = -std::numeric_limits<float>::infinity();
		tyExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		tyEntry = dyEntry / object.getVy;
		tyExit = dyExit / object.getVy();
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
