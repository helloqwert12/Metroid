#pragma once
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <d3d9.h>
#include <d3dx9.h>
typedef struct SPRITEINFO
{
	int pos_x;
	int pos_y;
}SpriteInfo;

class Sprite
{
protected:
	LPDIRECT3DTEXTURE9 _Image;				// The container of all the sprites
	LPD3DXSPRITE _SpriteHandler;
		
	int _Index;								// Current sprite index
	int _Width;								// Sprite width
	int _Height;							// Sprite height
	int _Count;								// Number of sprites
	int _SpritePerRow;						// Number of sprites per row
	SpriteInfo* spriteInfo;				    // Array contain position of each sprite
public:
	Sprite();
	Sprite(LPD3DXSPRITE SpriteHandler, LPWSTR ImagePath, char* infoFilePath, int Width, int Height, int Count, int SpritePerRow);
	~Sprite();

	void Next();
	void Reset();

	// Render current sprite at location (X,Y)
	void Render(int X, int Y, int vpx, int vpy);
};
#endif
