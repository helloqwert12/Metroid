#pragma once
#ifndef _METROID_H_
#define _METROID_H_

#define SAMUS_SPEED 0.4f



#include "Game.h"
#include "Samus.h"
class Metroid : public Game
{
protected:
	LPDIRECT3DSURFACE9 Background;
	Samus * samus;

private:
	void _InitBackground();
	void _InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void _InitPositions();

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
	