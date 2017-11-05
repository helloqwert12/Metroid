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
#define RUN_SHOOTING_LEFT "sprites\\RUN_SHOOTING_LEFT.txt"
#define RUN_SHOOTING_RIGHT "sprites\\RUN_SHOOTING_RIGHT.txt"
#define RUN_AIM_UP_LEFT "sprites\\RUN_AIM_UP_LEFT.txt"
#define RUN_AIM_UP_RIGHT "sprites\\RUN_AIM_UP_RIGHT.txt"
#define IDLE_AIM_UP_LEFT "sprites\\IDLE_AIM_UP_LEFT.txt"
#define IDLE_AIM_UP_RIGHT "sprites\\IDLE_AIM_UP_RIGHT.txt"
#define STANDING_LEFT "sprites\\STANDING_LEFT.txt"
#define STANDING_RIGHT "sprites\\STANDING_RIGHT.txt"

#define APPEARING_WIDTH 16
#define APPEARING_HEIGHT 32
#define RUNNING_WIDTH 18
#define RUNNING_HEIGHT 32
#define JUMP_WIDTH 18
#define JUMP_HEIGHT 25
#define RUN_SHOOTING_WIDTH 25
#define RUN_SHOOTING_HEIGHT 31
#define RUN_AIM_UP_WIDTH 19
#define RUN_AIM_UP_HEIGHT 38
#define IDLE_AIM_UP_WIDTH 14
#define IDLE_AIM_UP_HEIGHT 38
#define STANDING_WIDTH 21
#define STANDING_HEIGHT 32

#define APPEARING_COUNT 5
#define RUNNING_COUNT 3
#define JUMP_COUNT 1
#define RUN_SHOOTING_COUNT 3
#define RUN_AIM_UP_COUNT 3
#define IDLE_AIM_UP_COUNT 1
#define STANDING_COUNT 1

#define SPRITE_PER_ROW 1

#define ANIMATE_RATE 30

#include "GameObject.h"

enum SAMUS_STATE {
	IDLE_LEFT, 
	IDLE_RIGHT,
	LEFTING, 
	RIGHTING,
	IDLING_AIM_UP_LEFT,
	IDLING_AIM_UP_RIGHT,
	AIMING_UP_LEFT,
	AIMING_UP_RIGHT,
	MORPH_LEFT,
	MORPH_RIGHT,
};
class Samus : public GameObject
{
protected:
	LPD3DXSPRITE _SpriteHandler;

	Sprite * appearing;
	Sprite * running_left;
	Sprite * running_right;
	Sprite * jump_left;
	Sprite * jump_right;
	Sprite * run_shooting_left;
	Sprite * run_shooting_right;
	Sprite * run_aim_up_left;
	Sprite * run_aim_up_right;
	Sprite * idle_aim_up_left;
	Sprite * idle_aim_up_right;
	Sprite * idle_left;
	Sprite * idle_right;

	SAMUS_STATE state;

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
	float GetVelocityXLast();

	SAMUS_STATE GetState();
	void SetState(SAMUS_STATE value);

	void ResetAllSprites();
	
	//Update every frame of game	
	void Update(int t);
};
#endif // !_SAMUS_H

