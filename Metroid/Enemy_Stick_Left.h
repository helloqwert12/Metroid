#pragma once
#include "Enemy.h"

#define ENEMY_SHEET_PATH L"sprites\\enemy\\metroid_enemies_sheet.png"

#define ENEMY_STICK_LEFT "sprites\\enemy\\ENEMY_STICK_LEFT.txt"

#define ENEMY_STICK_LEFT_WIDTH 32
#define ENEMY_STICK_LEFT_HEIGHT 32

#define ENEMY_STICK_LEFT_COUNT 2

class Enemy_Stick_Left :
	public Enemy
{
protected:
	Sprite* enemy_stick_left;
public:
	Enemy_Stick_Left();
	~Enemy_Stick_Left();
	void InitPostition();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void _Render(int samus_pos_x);
	void Update(int t, int samus_pos_x);
};

