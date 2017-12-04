#pragma once
#include "GameObject.h"
enum Direction
{
	UP,
	LEFT,
	RIGHT,
	DOWN
};
class Collision
{
public:
	Collision();
	~Collision();

	static bool isColliding(GameObject* objectA , GameObject* objectB);
	static float sweptAABB(GameObject* objectA, GameObject* objectB,Direction& direction);
	static void Resolve(GameObject* objectA, GameObject* objectB, Direction direction);
};

