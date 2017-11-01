#include "Sprite.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "trace.h"
using namespace std;

Sprite::Sprite()
{
}

Sprite::Sprite(LPD3DXSPRITE SpriteHandler, LPWSTR ImagePath, char* infoFilePath, int Width, int Height, int Count, int SpritePerRow)
{
	//
	//Init array posSprite
	//
	spriteInfo = new SpriteInfo[Count];

	//Read file info of file
	fstream f;
	try
	{
		f.open(infoFilePath, ios::in);
	}
	catch (std::fstream::failure e)
	{
		//--TO DO: log failure

		return;
	}
	string line;
	int id = 0;
	while (!f.eof())
	{
		vector<string> pos;
		string split;
		getline(f, line);
		istringstream iss(line);
		
		while (getline(iss, split, ' '))
		{
			pos.push_back(split);
		}
		
		spriteInfo[id].pos_x = stoi(pos[0]);
		spriteInfo[id].pos_y = stoi(pos[1]);
		id++;
	}
	f.close();

	//
	//Init sprite with DirectX
	//
	D3DXIMAGE_INFO info;
	HRESULT result;

	_Image = NULL;
	_SpriteHandler = SpriteHandler;
	_Width = Width;
	_Height = Height;
	_Count = Count;
	_SpritePerRow = SpritePerRow;
	_Index = 0;

	result = D3DXGetImageInfoFromFile(ImagePath, &info);
	if (result != D3D_OK)
	{
		trace(L"[ERROR] Failed to get information from image file '%s'", ImagePath);
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv;
	SpriteHandler->GetDevice(&d3ddv);

	result = D3DXCreateTextureFromFileEx(
		d3ddv,
		ImagePath,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(0, 0, 0),
		&info,
		NULL,
		&_Image);

	if (result != D3D_OK)
	{
		trace(L"[ERROR] Failed to create texture from file '%s'", ImagePath);
		return;
	}

}	


Sprite::~Sprite()
{
	delete(spriteInfo);
	_Image->Release();
}

void Sprite::Next()
{
	_Index = (_Index + _Count - 1) % _Count;
}

void Sprite::Reset()
{
	_Index = 0;
}

void Sprite::Render(int X, int Y, int vpx, int vpy)
{
	RECT rect;
	rect.left = spriteInfo[_Index].pos_x;
	rect.top = spriteInfo[_Index].pos_y;
	rect.right = spriteInfo[_Index].pos_x + _Width;
	rect.bottom = spriteInfo[_Index].pos_y + _Height;

	D3DXVECTOR3 position((float)X, (float)Y, 0);

	_SpriteHandler->Draw(
		_Image,
		&rect,
		NULL,
		&position,
		D3DCOLOR_XRGB(255, 255, 255)
	);
}
