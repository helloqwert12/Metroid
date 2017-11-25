#include "Enemy_Stick_Right.h"



Enemy_Stick_Right::Enemy_Stick_Right()
{
	enemy_stick_right = NULL;
}


Enemy_Stick_Right::~Enemy_Stick_Right()
{
	delete(enemy_stick_right);
}
void Enemy_Stick_Right::InitPostition()
{
	Enemy::InitPostition();
}
void Enemy_Stick_Right::_Render(int samus_pos_x)
{
	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	enemy_stick_right->Render(100, 100, samus_pos_x - 510, 500);
	_SpriteHandler->End();
}

void Enemy_Stick_Right::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	Enemy::InitSprites(d3ddv);
	enemy_stick_right = new Sprite(_SpriteHandler, ENEMY_SHEET_PATH, ENEMY_STICK_RIGHT, ENEMY_STICK_RIGHT_WIDTH, ENEMY_STICK_RIGHT_HEIGHT, ENEMY_STICK_RIGHT_COUNT, SPRITE_PER_ROW);
}
void Enemy_Stick_Right::Update(int t, int samus_pos_x)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		enemy_stick_right->Next();
		last_time = now;
	}
	_Render(samus_pos_x);
}