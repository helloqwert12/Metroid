#pragma once
#ifndef _TILES_H
#define _TILES_H
#include "Sprite.h"
#include "GameObject.h"
#include "Samus.h"


#define TILES_SHEET_PATH L"background\\Metroid_-_NES_-_Samus_Appears_bank.png"

#define S1 "background\\S1.txt"
#define S2 "background\\S2.txt"
#define S3 "background\\S3.txt"
#define S4 "background\\S4.txt"
#define S5 "background\\S5.txt"
#define S6 "background\\S6.txt"
#define S7 "background\\S7.txt"
#define S8 "background\\S8.txt"
#define S9 "background\\S9.txt"
#define S10 "background\\S10.txt"
#define S11 "background\\S11.txt"


#define S1_WIDTH 16
#define S1_HEIGHT 16
#define S2_WIDTH 16
#define S2_HEIGHT 16
#define S3_WIDTH 16
#define S3_HEIGHT 16
#define S4_WIDTH 16
#define S4_HEIGHT 16
#define S5_WIDTH 16
#define S5_HEIGHT 16
#define S6_WIDTH 16
#define S6_HEIGHT 16
#define S7_WIDTH 16
#define S7_HEIGHT 16
#define S8_WIDTH 16
#define S8_HEIGHT 16
#define S9_WIDTH 16
#define S9_HEIGHT 16
#define S10_WIDTH 16
#define S10_HEIGHT 16
#define S11_WIDTH 16
#define S11_HEIGHT 16


#define TILES_COUNT 1
#define SPRITE_PER_ROW 1

#define VIEW_PORT_Y 600

#define VIEW_PORT_Y1 410
#define VIEW_PORT_Y2 510
class Tiles : public GameObject
{
protected:
	LPD3DXSPRITE _SpriteHandler;



	Sprite * s1;
	Sprite * s2;
	Sprite * s3;
	Sprite * s4;
	Sprite * s5;
	Sprite * s6;
	Sprite * s7;
	Sprite * s8;
	Sprite * s9;
	Sprite * s10;
	Sprite * s11;

public:
	Tiles();
	~Tiles();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);

	 void _Render(int xc, int samus_pos_x);

	 void Check(int a[], int vpx, int vpy, int c, int d);

	 void ImportFile();



};
#endif // !_TILES_H


