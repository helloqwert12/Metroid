#include "Enemy.h"



Enemy::Enemy()
{
	width = 16;
	height = 16;
}


Enemy::~Enemy()
{
}
void Enemy::InitPostition()
{
	vx = 0;
	vx_last = 0.0f;
	vy = 0;
}
void Enemy::_Render(int samus_pos_x)
{
}

void Enemy::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &_SpriteHandler);
	if (result != D3D_OK) return;
}
void Enemy::Update(int t, int samus_pos_x)
{
}