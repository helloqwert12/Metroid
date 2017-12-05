#include "Enemy_Fly.h"

Enemy_Fly::Enemy_Fly()
{
	enemy_fly_1 = NULL;
}

Enemy_Fly::~Enemy_Fly()
{
	delete(enemy_fly_1);
}
void Enemy_Fly::InitPostition()
{
	Enemy::InitPostition();
	pos_x = 70;
	pos_y = 80;
}
void Enemy_Fly::_Render(int samus_pos_x)
{
	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	enemy_fly_1->Render(pos_x, pos_y, samus_pos_x - 400, 600);
	_SpriteHandler->End();
}

void Enemy_Fly::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	Enemy::InitSprites(d3ddv);
	enemy_fly_1 = new Sprite(_SpriteHandler, ENEMY_SHEET_PATH, ENEMY_FLY_1, ENEMY_FLY_1_WIDTH, ENEMY_FLY_1_HEIGHT, ENEMY_FLY_1_COUNT, SPRITE_PER_ROW);
}
void Enemy_Fly::Update(int t, int samus_pos_x)
{
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		enemy_fly_1->Next();
		last_time = now;
	}
	_Render(samus_pos_x);
}