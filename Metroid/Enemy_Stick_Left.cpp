#include "Enemy_Stick_Left.h"



Enemy_Stick_Left::Enemy_Stick_Left()
{
	enemy_stick_left = NULL;
}


Enemy_Stick_Left::~Enemy_Stick_Left()
{
	delete(enemy_stick_left);
}
void Enemy_Stick_Left::_Render(int samus_pos_x)
{
	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	enemy_stick_left->Render(100, 100, samus_pos_x - 405, 500);
	_SpriteHandler->End();
}
void Enemy_Stick_Left::InitPostition()
{
	Enemy::InitPostition();
}
void Enemy_Stick_Left::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	Enemy::InitSprites(d3ddv);
	enemy_stick_left = new Sprite(_SpriteHandler, ENEMY_SHEET_PATH, ENEMY_STICK_LEFT, ENEMY_STICK_LEFT_WIDTH, ENEMY_STICK_LEFT_HEIGHT, ENEMY_STICK_LEFT_COUNT, SPRITE_PER_ROW);
}
void Enemy_Stick_Left::Update(int t, int samus_pos_x)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		enemy_stick_left->Next();
		last_time = now;
	}
	_Render(samus_pos_x);
}
