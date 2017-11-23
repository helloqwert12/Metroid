#pragma once
#include "Sprite.h"
#include "GameObject.h"

#define SPRITE_PER_ROW 1
#define ANIMATE_RATE 7

class Enemy : public GameObject
{
protected:
	LPD3DXSPRITE _SpriteHandler;
	Sprite* enemy_fly_1;
public:
	Enemy();
	~Enemy();
	virtual void InitPostition();
	virtual void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	virtual void _Render(int samus_pos_x);
	virtual void Update(int t, int samus_pos_x);
};

