#include "Game.h"
#include "trace.h"
#define KEY_DOWN(vk_code) ( (GetAsyncKeyState(vk_code)&0x8000)?1:0 )

SoundManager* Game::gameSound = NULL;

Game::Game()
{
}

Game::Game(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullscreen, int FrameRate)
{
	_d3d = NULL;
	_d3ddv = NULL;
	_BackBuffer = NULL;

	_di = NULL;
	_Keyboard = NULL;

	_Mode = Mode;
	_SetScreenDimension(Mode);
	_Name = Name;
	_IsFullScreen = IsFullscreen;
	_FrameRate = FrameRate;

	_hInstance = hInstance;

	Game::gameSound = new SoundManager();
}


Game::~Game()
{
	if (_d3ddv != NULL) _d3ddv->Release();
	if (_d3d != NULL) _d3d->Release();

	if (_Keyboard)
	{
		_Keyboard->Unacquire();
		_Keyboard->Release();
	}

	if (_di) _di->Release();
	Game::gameSound->shutdownDirectSound();
}

void Game::Init()
{
	_InitWindow();
	_InitDirectX();
	_InitKeyboard();
	Game::gameSound->LoadSound(_hWnd);
	LoadResources(_d3ddv);
}

void Game::Run()
{
	MSG msg;
	int done = 0;
	DWORD frame_start = GetTickCount();

	DWORD tick_per_frame = 1000 / _FrameRate;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;
			else if (msg.message == WM_ACTIVATE)
			{
				if (_Keyboard != NULL && _Keyboard->Poll() != DI_OK)
				{
					_Keyboard->Acquire();
				}
				msg.message = 0;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();
		_DeltaTime = now - frame_start;
		if (_DeltaTime >= (tick_per_frame))
		{
			frame_start = now;
			Update(_DeltaTime);
			_RenderFrame();		
			
		}
		else
		{
			Sleep(tick_per_frame - _DeltaTime);
		}
		
		_ProcessKeyBoard();
		ProcessInput(_d3ddv, _DeltaTime);
	}
}

void Game::_SetScreenDimension(int Mode)
{
	switch (Mode)
	{
	case GAME_SCREEN_RESOLUTION_640_480_24:
		_ScreenWidth = 640;
		_ScreenHeight = 480;
		_Depth = 24;
		_BackBufferFormat = D3DFMT_X8R8G8B8;
		break;

	case GAME_SCREEN_RESOLUTION_800_600_24:
		_ScreenWidth = 800;
		_ScreenHeight = 600;
		_Depth = 24;
		_BackBufferFormat = D3DFMT_X8R8G8B8;
		break;

	case GAME_SCREEN_RESOLUTION_1024_768_24:
		_ScreenWidth = 1024;
		_ScreenHeight = 768;
		_Depth = 24;
		_BackBufferFormat = D3DFMT_X8R8G8B8;
		break;

	default:
		break;
	}
}

LRESULT Game::_WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

void Game::_InitWindow()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = _hInstance;

	wc.lpfnWndProc = (WNDPROC)Game::_WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _Name;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	DWORD style;
	if (_IsFullScreen)
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	else
		style = WS_OVERLAPPEDWINDOW;

	_hWnd =
		CreateWindow(
			_Name,
			_Name,
			style,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			_ScreenWidth,
			_ScreenHeight,
			NULL,
			NULL,
			_hInstance,
			NULL);

	if (!_hWnd)
	{
		DWORD ErrCode = GetLastError();
	}

	ShowWindow(_hWnd, SW_SHOWNORMAL);
	UpdateWindow(_hWnd);
}

void Game::_InitDirectX()
{
	_d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = _IsFullScreen ? FALSE : TRUE;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	d3dpp.BackBufferFormat = _BackBufferFormat;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = _ScreenHeight;
	d3dpp.BackBufferWidth = _ScreenWidth;

	_d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&_d3ddv);

	if (_d3ddv == NULL)
	{

	}

	_d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &_BackBuffer);
}

void Game::_InitKeyboard()
{
	HRESULT
		hr = DirectInput8Create
		(
			_hInstance,
			DIRECTINPUT_VERSION,
			IID_IDirectInput8, (VOID**)&_di, NULL
		);

	// TO-DO: put in exception handling
	if (hr != DI_OK) return;

	trace(L"DirectInput has been created");

	hr = _di->CreateDevice(GUID_SysKeyboard, &_Keyboard, NULL);

	// TO-DO: put in exception handling
	if (hr != DI_OK) return;

	trace(L"DirectInput keyboard has been created");

	// Set the data format to "keyboard format" - a predefined data format 
	//
	// A data format specifies which controls on a device we
	// are interested in, and how they should be reported.
	//
	// This tells DirectInput that we will be passing an array
	// of 256 bytes to IDirectInputDevice::GetDeviceState.

	hr = _Keyboard->SetDataFormat(&c_dfDIKeyboard);

	trace(L"SetDataFormat for keyboard successfully");

	hr = _Keyboard->SetCooperativeLevel(_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	trace(L"SetCooperativeLevel for keyboard successfully");

	// IMPORTANT STEP TO USE BUFFERED DEVICE DATA!
	//
	// DirectInput uses unbuffered I/O (buffer size = 0) by default.
	// If you want to read buffered data, you need to set a nonzero
	// buffer size.
	//
	// Set the buffer size to DINPUT_BUFFERSIZE (defined above) elements.
	//
	// The buffer size is a DWORD property associated with the device.
	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE; // Arbitary buffer size

	trace(L"SetProperty for keyboard successfully");

	hr = _Keyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	if (hr != DI_OK) return;

	hr = _Keyboard->Acquire();
	if (hr != DI_OK) return;

	trace(L"Keyboard has been acquired successfully");
}

void Game::_ProcessKeyBoard()
{
	static HRESULT result;

	// Collect all key states first
	result = _Keyboard->GetDeviceState(sizeof(_KeyStates), _KeyStates);

	if (FAILED(result)) 
	{
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			_Keyboard->Acquire();
		}
	}
	if (IsKeyDown(DIK_ESCAPE))
	{
		trace(L"Escape key pressed!");
		PostMessage(_hWnd, WM_QUIT, 0, 0);
	}


	// Collect all buffered events
	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	HRESULT hr = _Keyboard->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), _KeyEvents, &dwElements, 0);

	// Scan through all data, check if the key is pressed or released
	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = _KeyEvents[i].dwOfs;
		int KeyState = _KeyEvents[i].dwData;
		if ((KeyState & 0x80) > 0)
			OnKeyDown(KeyCode);
		else
			OnKeyUp(KeyCode);
	}
}

int Game::IsKeyDown(int KeyCode)
{
	return (_KeyStates[KeyCode] & 0x80) > 0;
}

void Game::_RenderFrame()
{
	if (_d3ddv->BeginScene())
	{
		_d3ddv->ColorFill(_BackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));

		Render(_d3ddv);
		_d3ddv->EndScene();
	}
	_d3ddv->Present(NULL, NULL, NULL, NULL);
}

void Game::Update(float Delta)
{
}

void Game::Render(LPDIRECT3DDEVICE9 d3ddv)
{
	d3ddv->ColorFill(_BackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));
}

void Game::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
}

void Game::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
}

void Game::OnKeyDown(int KeyCode)
{
}

void Game::OnKeyUp(int KeyCode)
{
}
