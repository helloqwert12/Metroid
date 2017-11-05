#include "Metroid.h"
#include <time.h>

void Metroid::_InitBackground()
{
}

void Metroid::_InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	samus->InitSprites(d3ddv);
}

void Metroid::_InitPositions()
{
	samus->InitPostition();
}


Metroid::Metroid(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate):Game(hInstance, Name, Mode, IsFullScreen, FrameRate)
{
	samus = new Samus();
}


Metroid::~Metroid()
{
	delete(samus);
}

void Metroid::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	samus->Update(Delta);
}

void Metroid::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	if (IsKeyDown(DIK_RIGHT))
	{
		samus->SetVelocityXLast(samus->GetVelocityX());
		samus->SetVelocityX(SAMUS_SPEED);	
	}
	else
	{
		if (IsKeyDown(DIK_LEFT))
		{
			samus->SetVelocityXLast(samus->GetVelocityX());
			samus->SetVelocityX(-SAMUS_SPEED);		
		}
		else
		{
			samus->SetVelocityX(0);
			samus->ResetAllSprites();
		}
	}
}

void Metroid::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	srand((unsigned)time(NULL));
	_InitSprites(d3ddv);
	_InitPositions();
}

void Metroid::OnKeyDown(int KeyCode)
{
}
