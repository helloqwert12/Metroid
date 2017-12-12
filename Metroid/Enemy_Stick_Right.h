#pragma once
#include "Enemy.h"

#define ENEMY_SHEET_PATH L"sprites\\enemy\\metroid_enemies_sheet.png"

#define ENEMY_STICK_RIGHT "sprites\\enemy\\ENEMY_STICK_RIGHT.txt"

#define ENEMY_STICK_RIGHT_WIDTH 64
#define ENEMY_STICK_RIGHT_HEIGHT 64

#define ENEMY_STICK_RIGHT_COUNT 2

class Enemy_Stick_Right :
	public Enemy
{
protected:
	Sprite* enemy_stick_right;
public:
	Enemy_Stick_Right();
	~Enemy_Stick_Right();
	void InitPostition();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void _Render(int samus_pos_x);
	void Update(int t, int samus_pos_x);
};

