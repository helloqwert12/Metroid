#pragma once
#include "Sprite.h"
#include "Enemy.h"
#define ENEMY_SHEET_PATH L"sprites\\enemy\\metroid_enemies_sheet.png"

#define ENEMY_STICK_BOTTOM "sprites\\enemy\\ENEMY_STICK_BOTTOM.txt"

#define ENEMY_STICK_BOTTOM_WIDTH 64
#define ENEMY_STICK_BOTTOM_HEIGHT 64

#define ENEMY_STICK_BOTTOM_COUNT 2

class Enemy_Stick_Bottom :
	public Enemy
{
protected:
	Sprite* enemy_stick_bottom;
public:
	Enemy_Stick_Bottom();
	~Enemy_Stick_Bottom();

	void InitPostition();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void _Render(int samus_pos_x);
	void Update(int t, int samus_pos_x);
};

