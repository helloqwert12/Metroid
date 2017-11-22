#pragma once
#ifndef _BULLET_H_
#define _BULLET_H_

#include "GameObject.h"

#define BULLET_SPRITE_PATH L" "
#define BULLET_WIDTH 0
#define BULLET_HEIGHT 0
#define BULLET_COUNT 1
#define SPRITE_PER_ROW 1

enum BULLET_DIRECTION 
{
	ON_LEFT,
	ON_RIGHT,
	ON_UP
};

class Bullet : public GameObject
{
private:
	BULLET_DIRECTION direction;
	
public:
	Bullet();
	~Bullet();

	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void InitPostition();

	BULLET_DIRECTION GetDirection();
	void SetDirection(BULLET_DIRECTION value);

	void ResetAllSprites();
};

#endif // !_BULLET_H
