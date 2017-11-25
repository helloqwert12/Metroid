#pragma once
#include "GameObject.h"

class Collision
{
public:
	Collision();
	~Collision();

	static bool isColliding(GameObject* objectA , GameObject* objectB);
	static float sweptAABB(GameObject* objectA, GameObject* objectB, float& normalx, float& normaly);
};

