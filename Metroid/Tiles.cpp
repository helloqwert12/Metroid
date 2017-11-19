#include "Tiles.h"
#include "trace.h"

Tiles::Tiles()
{
	brick = NULL;
	ground_middle = NULL;
}


Tiles::~Tiles()
{
	delete(brick);
	delete(ground_middle);
}

void Tiles::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &_SpriteHandler);
	if (result != D3D_OK) return;

	//Create instance of sprites
	brick = new Sprite(_SpriteHandler, TILES_SHEET_PATH, BRICK, BRICK_WIDTH, BRICK_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
	ground_middle = new Sprite(_SpriteHandler, TILES_SHEET_PATH, GROUND_MIDDLE, GROUND_MIDDLE_WIDTH, GROUND_MIDDLE_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
}

void Tiles::_Render(int xc, int samus_pos_x)
{
	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	int vpx = samus_pos_x - 400;
	//int vpx = xc;
	//if (vpx <= 0) vpx = 0;
	//xc += 1;

	int i = 0;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;

	i += 32;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;
	ground_middle->Render(16 + i, 16, vpx, VIEW_PORT_Y); i += 16;


	int j = 0;
	brick->Render(165 + j, 32, vpx, VIEW_PORT_Y);
	brick->Render(100, 47, vpx, VIEW_PORT_Y);

	_SpriteHandler->End();
}