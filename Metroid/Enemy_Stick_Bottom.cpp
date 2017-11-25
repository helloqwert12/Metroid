#include "Enemy_Stick_Bottom.h"



Enemy_Stick_Bottom::Enemy_Stick_Bottom()
{
	enemy_stick_bottom = NULL;
}


Enemy_Stick_Bottom::~Enemy_Stick_Bottom()
{
	delete(enemy_stick_bottom);
}
void Enemy_Stick_Bottom::InitPostition()
{
	Enemy::InitPostition();
}
void Enemy_Stick_Bottom::_Render(int samus_pos_x)
{
	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	enemy_stick_bottom->Render(100, 100, samus_pos_x - 470, 510);
	_SpriteHandler->End();
}

void Enemy_Stick_Bottom::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	Enemy::InitSprites(d3ddv);
	enemy_stick_bottom = new Sprite(_SpriteHandler, ENEMY_SHEET_PATH, ENEMY_STICK_BOTTOM, ENEMY_STICK_BOTTOM_WIDTH, ENEMY_STICK_BOTTOM_HEIGHT, ENEMY_STICK_BOTTOM_COUNT, SPRITE_PER_ROW);
}
void Enemy_Stick_Bottom::Update(int t, int samus_pos_x)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		enemy_stick_bottom->Next();
		last_time = now;
	}
	_Render(samus_pos_x);
}