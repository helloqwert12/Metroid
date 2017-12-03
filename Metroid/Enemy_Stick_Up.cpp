#include "Enemy_Stick_Up.h"



Enemy_Stick_Up::Enemy_Stick_Up()
{
	enemy_stick_up = NULL;
}


Enemy_Stick_Up::~Enemy_Stick_Up()
{
	delete(enemy_stick_up);
}
void Enemy_Stick_Up::InitPostition()
{
	Enemy::InitPostition();
	pos_x = 100;
	pos_y = 50;
}
void Enemy_Stick_Up::_Render(int samus_pos_x)
{
	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	enemy_stick_up->Render(pos_x, 50, samus_pos_x - 700, 600);
	_SpriteHandler->End();
}

void Enemy_Stick_Up::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	Enemy::InitSprites(d3ddv);
	enemy_stick_up = new Sprite(_SpriteHandler, ENEMY_SHEET_PATH, ENEMY_STICK_UP, ENEMY_STICK_UP_WIDTH, ENEMY_STICK_UP_HEIGHT, ENEMY_STICK_UP_COUNT, SPRITE_PER_ROW);
}
void Enemy_Stick_Up::Update(int t, int samus_pos_x)
{
	pos_x += vx*t;
	pos_y += vy*t;
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		enemy_stick_up->Next();
		last_time = now;
	}
	_Render(samus_pos_x);
}