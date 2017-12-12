#pragma once
#include "Sprite.h"
#include "GameObject.h"
#include "Enemy.h"

#define ENEMY_SHEET_PATH L"sprites\\enemy\\metroid_enemies_sheet.png"

#define ENEMY_FLY_1 "sprites\\enemy\\ENEMY_FLY_1.txt"

#define ENEMY_FLY_1_WIDTH 32
#define ENEMY_FLY_1_HEIGHT 64

#define ENEMY_FLY_1_COUNT 3

class Enemy_Fly : public Enemy
{
protected:
	Sprite* enemy_fly_1;
public:
	Enemy_Fly();
	~Enemy_Fly();
	void InitPostition();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void _Render(int samus_pos_x);
	void Update(int t, int samus_pos_x);
};

