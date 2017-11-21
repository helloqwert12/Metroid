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


#define S1_WIDTH 16
#define S1_HEIGHT 16
#define S2_WIDTH 16
#define S2_HEIGHT 16
#define S3_WIDTH 16
#define S3_HEIGHT 16
#define S4_WIDTH 16
#define S4_HEIGHT 16

#define TILES_COUNT 1
#define SPRITE_PER_ROW 1

#define VIEW_PORT_Y 600

#define VIEW_PORT_Y1 500
#define VIEW_PORT_Y2 510
class Tiles : public GameObject
{
protected:
	LPD3DXSPRITE _SpriteHandler;



	Sprite * s1;
	Sprite * s2;
	Sprite * s3;
	Sprite * s4;

public:
	Tiles();
	~Tiles();
	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	
	void _Render(int xc, int samus_pos_x);

	void Check(int a[],int vpx,int vpy);

};
#endif // !_TILES_H