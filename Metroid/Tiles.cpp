#include "Tiles.h"
#include "trace.h"

Tiles::Tiles()
{

	s1 = NULL;
	s2 = NULL;
	s3 = NULL;
	s4 = NULL;
}


Tiles::~Tiles()
{
	delete(s1);
	delete(s2);
	delete(s3);
	delete(s4);
}

void Tiles::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &_SpriteHandler);
	if (result != D3D_OK) return;

	//Create instance of sprites
	s1 = new Sprite(_SpriteHandler, TILES_SHEET_PATH, S1, S1_WIDTH, S1_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
	s2 = new Sprite(_SpriteHandler, TILES_SHEET_PATH, S2, S2_WIDTH, S2_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
	s3 = new Sprite(_SpriteHandler, TILES_SHEET_PATH, S3, S3_WIDTH, S3_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
	s4 = new Sprite(_SpriteHandler, TILES_SHEET_PATH, S4, S4_WIDTH, S4_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);

}
void Tiles::Check(int a[], int vpx, int vpy)
{
	int j;
	int i = 0;
	for ( j = 0; j < 16; j++)
	{
		if (a[j] == 1)
		{
			s1->Render(16 + i, 16, vpx, vpy); i += 16;
		}
		else if (a[j] == 2)
		{
			s2->Render(16 + i, 16, vpx, vpy); i += 16;
		}
		else if (a[j] == 3)
		{
			s3->Render(16 + i, 16, vpx, vpy); i += 16;
		}
		else
		{
			s4->Render(16 + i, 16, vpx, vpy); i += 16;
		}
	}
	j = 0;
	i = 0;
}
void Tiles::_Render(int xc, int samus_pos_x)
{
	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	int vpx = samus_pos_x - 400;
	//int vpx = xc;
	//if (vpx <= 0) vpx = 0;
	//xc += 1;

	int i = 0;

	
	////Mang 1 chieu toa do 
	int a[] = { 1,2,3,2,4,4,1,1,1,2,3,2,4,4,1,1 };
	int b[] = { 1,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4};
	int c[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

	Check(a, vpx, VIEW_PORT_Y1);
	Check(b, vpx, VIEW_PORT_Y2);
	Check(c, vpx, VIEW_PORT_Y);

	_SpriteHandler->End();
}