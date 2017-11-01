#include <windows.h>
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Game rec(hInstance, L"Metroid game", GAME_SCREEN_RESOLUTION_800_600_24, 1, 24);

	rec.Init();
	rec.Run();

	return 0;
}