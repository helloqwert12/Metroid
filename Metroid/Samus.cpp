#include "Samus.h"
#include "trace.h"


void Samus::_Render()
{
	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	if (vx > 0)
		running_right->Render(pos_x, pos_y, pos_x - 400, 600);
	else if (vx < 0)
		running_left->Render(pos_x, pos_y, pos_x - 400, 600);
	else if (vx_last < 0)
		running_left->Render(pos_x, pos_y, pos_x - 400, 600);
	else
		running_right->Render(pos_x, pos_y, pos_x - 400, 600);

	_SpriteHandler->End();
}

Samus::Samus()
{
	appearing = NULL;
	running_left = NULL;
	running_right = NULL;
	jump_left = NULL;
	jump_right = NULL;
}


Samus::~Samus()
{
	delete(appearing);
	delete(running_left);
	delete(running_right);
	delete(jump_left);
	delete(jump_right);
}

void Samus::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result =  D3DXCreateSprite(d3ddv, &_SpriteHandler);
	if (result != D3D_OK) return;

	//Create instance of sprites
	appearing = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, APPEARING, APPEARING_WIDTH, APPEARING_HEIGHT, APPEARING_COUNT, SPRITE_PER_ROW);
	running_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUNNING_LEFT, RUNNING_WIDTH, RUNNING_HEIGHT, RUNNING_COUNT, SPRITE_PER_ROW);
	running_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUNNING_RIGHT, RUNNING_WIDTH, RUNNING_HEIGHT, RUNNING_COUNT, SPRITE_PER_ROW);
	jump_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, JUMP_LEFT, JUMP_WIDTH, JUMP_HEIGHT, JUMP_COUNT, SPRITE_PER_ROW);
	jump_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, JUMP_LEFT, JUMP_WIDTH, JUMP_HEIGHT, JUMP_COUNT, SPRITE_PER_ROW);
}

void Samus::InitPostition()
{
	//--TO DO: This code will be edited soon
	pos_x = 50;
	pos_y = 450;

	vx = 0;
	vx_last = 1.0f;
	vy = 0;

}

void Samus::SetVelocityX(float value)
{
	vx = value;
}

float Samus::GetVelocityX()
{
	return vx;
}

void Samus::SetVelocityXLast(float value)
{
	vx_last = value;
}

void Samus::ResetAllSprites()
{
	appearing->Reset();
	running_left->Reset();
	running_right->Reset();
	jump_left->Reset();
	jump_right->Reset();
}


void Samus::Update(int t)
{
	//
	// Update mario status
	//
	pos_x += vx*t;
	pos_y += vy*t;

	// Animate samus if he is running
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		if (vx > 0) running_right->Next();
		if (vx < 0) running_left->Next();

		last_time = now;
	}

	//Render
	_Render();

}
