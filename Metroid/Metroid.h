#pragma once
#ifndef _METROID_H_
#define _METROID_H_

#define SAMUS_SPEED 0.4f
#define BACKGROUND_FILE L"background\\temp.png"


#include "Game.h"
#include "Samus.h"
#include "Tiles.h"
class Metroid : public Game
{
protected:
	LPDIRECT3DSURFACE9 Background;
	Samus * samus;
	Tiles * tiles;

private:
	void _InitBackground();
	void _InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void _InitPositions();

	DWORD start_jump;
	DWORD now_jump;
	DWORD tick_per_frame;

public:
	Metroid(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate);
	~Metroid();

	LPDIRECT3DSURFACE9 _Background;


	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);

	virtual void OnKeyDown(int KeyCode);
};

#endif // !_METROID_
	