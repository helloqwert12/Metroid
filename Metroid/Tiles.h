#pragma once
#ifndef _TILES_H
#define _TILES_H
#include "Sprite.h"
#include "GameObject.h"
#include "Samus.h"

#define TILES_SHEET_PATH L"background\\TILES.png"

#define BRICK "background\\BRICK.txt"
#define GROUND_MIDDLE "background\\GROUND_MIDDLE.txt"

#define BRICK_WIDTH 16
#define BRICK_HEIGHT 16
#define GROUND_MIDDLE_WIDTH 16
#define GROUND_MIDDLE_HEIGHT 16

#define TILES_COUNT 1
#define SPRITE_PER_ROW 1

#define VIEW_PORT_Y 600
class Tiles : public GameObject
{
protected:
	LPD3DXSPRITE _SpriteHandler;

	Sprite * brick;
	Sprite * ground_middle;

public:
	Tiles();
	~Tiles();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);

	void _Render(int xc, int samus_pos_x);

};
#endif // !_TILES_H