#include "Tiles.h"
#include "trace.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 int a[500];
Tiles::Tiles()
{
	s1 = NULL;
	s2 = NULL;
	s3 = NULL;
	s4 = NULL;
	s5 = NULL;
	s6 = NULL;
	s7 = NULL;
	s8 = NULL;
	s9 = NULL;
	s10 = NULL;
	s11 = NULL;
}


Tiles::~Tiles()
{
	delete(s1);
	delete(s2);
	delete(s3);
	delete(s4);
	delete(s5);
	delete(s6);
	delete(s7);
	delete(s8);
	delete(s9);
	delete(s10);
	delete(s11);
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
	s5 = new Sprite(_SpriteHandler, TILES_SHEET_PATH, S5, S5_WIDTH, S5_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
	s6 = new Sprite(_SpriteHandler, TILES_SHEET_PATH, S6, S6_WIDTH, S6_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
	s7 = new Sprite(_SpriteHandler, TILES_SHEET_PATH, S7, S7_WIDTH, S7_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
	s8 = new Sprite(_SpriteHandler, TILES_SHEET_PATH, S8, S8_WIDTH, S8_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
	s9 = new Sprite(_SpriteHandler, TILES_SHEET_PATH, S9, S9_WIDTH, S9_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
	s10 = new Sprite(_SpriteHandler, TILES_SHEET_PATH, S10, S10_WIDTH, S10_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
	s11 = new Sprite(_SpriteHandler, TILES_SHEET_PATH, S11, S11_WIDTH, S11_HEIGHT, TILES_COUNT, SPRITE_PER_ROW);
}

void Tiles::ImportFile()
{
	
	string line;
	int j = 0,e,f;
	ifstream myfile("TILES.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (line.find("tile gid") != -1)
			{
			    e = line.find('"');
				f = line.find_last_of('"');
				string g = line.substr(e + 1, f-e-1);
				int value = atoi(g.c_str());
				a[j] = value;
				j++;
			}
		}
	}
}

void Tiles::Check(int a[], int vpx, int vpy, int c, int d)
{
	int j;
	int i = 0;
	for (j = d; j < c; j++)
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
		else if (a[j] == 5)
		{
			s5->Render(16 + i, 16, vpx, vpy); i += 16;
		}
		else if (a[j] == 6)
		{
			s6->Render(16 + i, 16, vpx, vpy); i += 16;
		}
		else if (a[j] == 7)
		{
			s7->Render(16 + i, 16, vpx, vpy); i += 16;
		}
		else if (a[j] == 8)
		{
			s8->Render(16 + i, 16, vpx, vpy); i += 16;
		}
		else if (a[j] == 9)
		{
			s9->Render(16 + i, 16, vpx, vpy); i += 16;
		}
		else if (a[j] == 10)
		{
			s10->Render(16 + i, 16, vpx, vpy); i += 16;
		}
		else if (a[j] == 11)
		{
			s11->Render(16 + i, 16, vpx, vpy); i += 16;
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

	ImportFile();

	int c = 16;
	int d = VIEW_PORT_Y1;
	int f = 0;
	for (int i = 0; i < 13; i++)
	{
		Check(a, vpx, d, c, f); c += 16; d += 16;  f += 16;
	}
	_SpriteHandler->End();
}