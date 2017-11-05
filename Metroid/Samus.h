#pragma once
#ifndef _SAMUS_H
#define _SAMUS_H_
#include "Sprite.h"

#define SAMUS_SPRITES_PATH L"sprites\\samus_sprites.png"

#define APPEARING "sprites\\APPEARING.txt"
#define RUNNING_LEFT "sprites\\RUNNING_LEFT.txt"
#define RUNNING_RIGHT "sprites\\RUNNING_RIGHT.txt"
#define JUMP_LEFT "sprites\\JUMP_LEFT.txt"
#define JUMP_RIGHT "sprites\\JUMP_RIGHT.txt"

#define APPEARING_WIDTH 16
#define APPEARING_HEIGHT 32
#define RUNNING_WIDTH 18
#define RUNNING_HEIGHT 32
#define JUMP_WIDTH 18
#define JUMP_HEIGHT 25

#define APPEARING_COUNT 5
#define RUNNING_COUNT 3
#define JUMP_COUNT 1

#define SPRITE_PER_ROW 1

#define ANIMATE_RATE 30

#include "GameObject.h"
class Samus : public GameObject
{
protected:
	LPD3DXSPRITE _SpriteHandler;

	Sprite * appearing;
	Sprite * running_left;
	Sprite * running_right;
	Sprite * jump_left;
	Sprite * jump_right;

private:
	void _Render();
public:
	Samus();
	~Samus();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void InitPostition();

	void SetVelocityX(float value);
	float GetVelocityX();
	void SetVelocityY(float value);
	void SetVelocityXLast(float value);

	void ResetAllSprites();
	
	//Update every frame of game	
	void Update(int t);
};
#endif // !_SAMUS_H

