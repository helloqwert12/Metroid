#pragma once
#include "Enemy.h"

#define ENEMY_SHEET_PATH L"sprites\\enemy\\metroid_enemies_sheet.png"

#define ENEMY_STICK_UP "sprites\\enemy\\ENEMY_STICK_UP.txt"

#define ENEMY_STICK_UP_WIDTH 20
#define ENEMY_STICK_UP_HEIGHT 16

#define ENEMY_STICK_UP_COUNT 2

class Enemy_Stick_Up :
	public Enemy
{
protected:
	Sprite* enemy_stick_up;
public:
	Enemy_Stick_Up();
	~Enemy_Stick_Up();
	void InitPostition();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void _Render(int samus_pos_x);
	void Update(int t, int samus_pos_x);
};

