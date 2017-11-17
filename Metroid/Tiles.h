#pragma once
#ifndef _TILES_H
#define _TILES_H
#include "Sprite.h"
#include "GameObject.h"

#define TILES_SHEET_PATH L"background\\TILES.png"

#define BRICK "background\\BRICK.txt"
#define GROUND_MIDDLE "background\\GROUND_MIDDLE.txt"

#define BRICK_WIDTH 16
#define BRICK_HEIGHT 16
#define GROUND_MIDDLE_WIDTH 16
#define GROUND_MIDDLE_HEIGHT 16

#define TILES_COUNT 1
#define SPRITE_PER_ROW 1

#define ANIMATE_RATE 15

#define GROUND_Y 450
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
	void InitPostition();

	void SetVelocityX(float value);
	float GetVelocityX();

	void SetVelocityY(float value);
	float GetVelocityY();

	void SetPosX(int value);
	int GetPosX();
	void SetPosY(int value);
	int GetPosY();

	void SetVelocityXLast(float value);
	float GetVelocityXLast();

	void _Render(int xc);
	void ResetAllSprites();

};
#endif // !_TILES_H