#include "Metroid.h"
#include <time.h>
#include "trace.h"
#include "utils.h"
#include "Collision.h"
int xc = 0; ////////////////////////////

void Metroid::_InitBackground()
{
}

void Metroid::_InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	samus->InitSprites(d3ddv);
	tiles->InitSprites(d3ddv);
	enemy_fly->InitSprites(d3ddv);
	enemy_stick_bottom->InitSprites(d3ddv);
	enemy_stick_up->InitSprites(d3ddv);
	enemy_stick_left->InitSprites(d3ddv);
	enemy_stick_right->InitSprites(d3ddv);

	bulletManager->InitSprites(d3ddv);
}

void Metroid::_InitPositions()
{
	samus->InitPostition();
	enemy_fly->InitPostition();
	enemy_stick_bottom->InitPostition();
	enemy_stick_up->InitPostition();
	enemy_stick_left->InitPostition();
	enemy_stick_right->InitPostition();

	bulletManager->InitPosition(samus->GetPosX(), samus->GetPosY());
}


void Metroid::_Shoot(BULLET_DIRECTION dir)
{
	now_shoot = GetTickCount();
	if (start_shoot <= 0) //if shooting is active
	{
		start_shoot = GetTickCount();
		bulletManager->Next(dir);
	}
	else if ((now_shoot - start_shoot) > SHOOTING_SPEED * tick_per_frame)
	{
		//Reset start_shoot
		start_shoot = 0;
	}
}

Metroid::Metroid(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate):Game(hInstance, Name, Mode, IsFullScreen, FrameRate)
{
	samus = new Samus();
	tiles = new Tiles();
	enemy_stick_bottom = new Enemy_Stick_Bottom();
	enemy_stick_up = new Enemy_Stick_Up();
	enemy_stick_left = new Enemy_Stick_Left();
	enemy_stick_right = new Enemy_Stick_Right();
	enemy_fly = new Enemy_Fly();
	tick_per_frame = 1000 / _FrameRate;
	start_shoot = 0;

	bulletManager = new BulletManager();
}


Metroid::~Metroid()
{
	delete(samus);
	delete(tiles);
	delete(enemy_fly);
	delete(enemy_stick_bottom);
	delete(enemy_stick_up);
	delete(enemy_stick_right);
	delete(enemy_stick_left);
	
	delete(bulletManager);
}

void Metroid::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	// Background
		d3ddv->StretchRect(
			Background,			// from 
			NULL,				// which portion?
			_BackBuffer,		// to 
			NULL,				// which portion?
			D3DTEXF_NONE);
		
		if (Collision::isColliding(samus, enemy_fly)
			|| Collision::isColliding(samus, enemy_stick_up))
		{
			MessageBox(
				NULL,
				(LPCWSTR)L"asdas",
				NULL,
				NULL
			);

		}

	samus->Update(Delta);
	tiles->_Render(xc, samus->GetPosX());
	enemy_fly->Update(Delta, samus->GetPosX());
	//enemy_stick_bottom->Update(Delta, samus->GetPosX());
	enemy_stick_up->Update(Delta, samus->GetPosX());
	//enemy_stick_left->Update(Delta, samus->GetPosX());
	//enemy_stick_right->Update(Delta, samus->GetPosX());

	bulletManager->Update(Delta, samus->GetPosX(), samus->GetPosY());
	
}

void Metroid::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	
	if (IsKeyDown(DIK_RIGHT))
	{
		samus->SetVelocityXLast(samus->GetVelocityX());
		samus->SetVelocityX(SAMUS_SPEED);	
		if (samus->GetState() != ON_MORPH_LEFT && samus->GetState() != ON_MORPH_RIGHT
			&& samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT
			&& samus->GetState() != ON_JUMPING_SHOOTING_LEFT && samus->GetState() != ON_JUMPING_SHOOTING_RIGHT
			&& samus->GetState() != ON_SOMERSAULT_LEFT /*&& samus->GetState() != ON_SOMERSAULT_RIGHT*/)
		{
			if (IsKeyDown(DIK_X))
			{
				if (samus->GetState() != ON_SOMERSAULT_RIGHT /*&& samus->GetState() != ON_JUMP_AIM_UP_RIGHT*/)
				{
					start_jump = GetTickCount();
					now_jump = GetTickCount();
					samus->SetState(ON_SOMERSAULT_RIGHT);
					samus->SetVelocityY(samus->GetVelocityY() + JUMP_VELOCITY_BOOST_FIRST);
				}
				else
				{
					now_jump = GetTickCount();
					if ((now_jump - start_jump) <= 20 * tick_per_frame)
					{
						samus->SetVelocityY(samus->GetVelocityY() + JUMP_VELOCITY_BOOST);
					}
				}
			}
			else if (samus->GetState() != ON_SOMERSAULT_RIGHT)
				samus->SetState(RIGHTING);
		}
	}
	else if (IsKeyDown(DIK_LEFT))
	{
		samus->SetVelocityXLast(samus->GetVelocityX());
		samus->SetVelocityX(-SAMUS_SPEED);
		if (samus->GetState() != ON_MORPH_LEFT && samus->GetState() != ON_MORPH_RIGHT
			&& samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT
			&& samus->GetState() != ON_JUMPING_SHOOTING_LEFT && samus->GetState() != ON_JUMPING_SHOOTING_RIGHT
			/*&& samus->GetState() != ON_SOMERSAULT_LEFT*/ && samus->GetState() != ON_SOMERSAULT_RIGHT)
		{
			if (IsKeyDown(DIK_X))
			{
				if (samus->GetState() != ON_SOMERSAULT_LEFT /*&& samus->GetState() != ON_JUMP_AIM_UP_LEFT*/)
				{
					start_jump = GetTickCount();
					now_jump = GetTickCount();
					samus->SetState(ON_SOMERSAULT_LEFT);
					samus->SetVelocityY(samus->GetVelocityY() + JUMP_VELOCITY_BOOST_FIRST);
				}
				else
				{
					now_jump = GetTickCount();
					if ((now_jump - start_jump) <= 20 * tick_per_frame)
					{
						samus->SetVelocityY(samus->GetVelocityY() + JUMP_VELOCITY_BOOST);
					}
				}
			}
			else if (samus->GetState() != ON_SOMERSAULT_LEFT)
				samus->SetState(LEFTING);
		}
	}
	else if (IsKeyDown(DIK_X))
	{
		if (samus->GetVelocityXLast() < 0)
		{
			if (samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_SOMERSAULT_LEFT 
				&& samus->GetState() != ON_JUMPING_SHOOTING_LEFT && samus->GetState() != ON_JUMP_AIM_UP_LEFT)
			{
				start_jump = GetTickCount();
				now_jump = GetTickCount();
				if (samus->GetState() == IDLING_AIM_UP_LEFT)
					samus->SetState(ON_JUMP_AIM_UP_LEFT);
				else
					samus->SetState(ON_JUMP_LEFT);
				samus->SetVelocityY(samus->GetVelocityY() + JUMP_VELOCITY_BOOST_FIRST);
			}
			else
			{
				now_jump = GetTickCount();
				if ((now_jump - start_jump) <= 20 * tick_per_frame)
				{
					samus->SetVelocityY(samus->GetVelocityY() + JUMP_VELOCITY_BOOST);
				}
			}
		}
		if (samus->GetVelocityXLast() > 0)
		{
			if (samus->GetState() != ON_JUMP_RIGHT  && samus->GetState() != ON_SOMERSAULT_RIGHT 
				&& samus->GetState() != ON_JUMPING_SHOOTING_RIGHT && samus->GetState() != ON_JUMP_AIM_UP_RIGHT)
			{
				start_jump = GetTickCount();
				now_jump = GetTickCount();
				if (samus->GetState() == IDLING_AIM_UP_RIGHT)
					samus->SetState(ON_JUMP_AIM_UP_RIGHT);
				else
					samus->SetState(ON_JUMP_RIGHT);
				samus->SetVelocityY(samus->GetVelocityY() + JUMP_VELOCITY_BOOST_FIRST);
			}
			else
			{
				now_jump = GetTickCount();
				if ((now_jump - start_jump) <= 20 * tick_per_frame)
				{
					samus->SetVelocityY(samus->GetVelocityY() + JUMP_VELOCITY_BOOST);
				}
			}
		}
	}
	else
	{
		samus->SetVelocityX(0);
		
		if (samus->GetVelocityXLast() < 0)
		{
			if (samus->GetState() != ON_MORPH_LEFT && samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT
				&& samus->GetState() != ON_JUMPING_SHOOTING_LEFT && samus->GetState() != ON_JUMPING_SHOOTING_RIGHT
				&& samus->GetState() != ON_SOMERSAULT_LEFT && samus->GetState() != ON_SOMERSAULT_RIGHT
				&& samus->GetState() != ON_JUMP_AIM_UP_LEFT)
			{
				samus->SetState(IDLE_LEFT);
				samus->ResetAllSprites();
			}
		}
		else
		{
			if (samus->GetState() != ON_MORPH_RIGHT && samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT
				&& samus->GetState() != ON_JUMPING_SHOOTING_LEFT && samus->GetState() != ON_JUMPING_SHOOTING_RIGHT
				&& samus->GetState() != ON_SOMERSAULT_LEFT && samus->GetState() != ON_SOMERSAULT_RIGHT
				&& samus->GetState() != ON_JUMP_AIM_UP_RIGHT)
			{
				samus->SetState(IDLE_RIGHT);
				samus->ResetAllSprites();
			}
		}
	}

	if (IsKeyDown(DIK_UP))
	{
		if (samus->GetState() == LEFTING)
			samus->SetState(AIMING_UP_LEFT);
		if (samus->GetState() == RIGHTING)
			samus->SetState(AIMING_UP_RIGHT);
		if (samus->GetState() == IDLE_LEFT)
			samus->SetState(IDLING_AIM_UP_LEFT);
		if (samus->GetState() == IDLE_RIGHT)
			samus->SetState(IDLING_AIM_UP_RIGHT);
		if (samus->GetState() == ON_JUMP_LEFT/* || samus->GetState() == ON_JUMPING_SHOOTING_LEFT*/)
			samus->SetState(ON_JUMP_AIM_UP_LEFT);
		if (samus->GetState() == ON_JUMP_RIGHT/* || samus->GetState() == ON_JUMPING_SHOOTING_RIGHT*/)
			samus->SetState(ON_JUMP_AIM_UP_RIGHT);

		if (samus->GetState() == ON_MORPH_LEFT)
			samus->SetState(IDLE_LEFT);
		if (samus->GetState() == ON_MORPH_RIGHT)
			samus->SetState(IDLE_RIGHT);
	}

	if (IsKeyDown(DIK_Z))
	{
		if (samus->GetState() == AIMING_UP_LEFT || samus->GetState() == AIMING_UP_RIGHT
			|| samus->GetState() == IDLING_AIM_UP_LEFT || samus->GetState() == IDLING_AIM_UP_RIGHT
			|| samus->GetState() == ON_JUMP_AIM_UP_LEFT || samus->GetState() == ON_JUMP_AIM_UP_RIGHT)
		{
			_Shoot(ON_UP);
		}
		if (samus->GetState() == ON_JUMP_LEFT || samus->GetState() == ON_SOMERSAULT_LEFT || samus->GetState() == ON_JUMPING_SHOOTING_LEFT)
		{
			samus->SetState(ON_JUMPING_SHOOTING_LEFT);

			_Shoot(ON_LEFT);
		}
		if (samus->GetState() == ON_JUMP_RIGHT || samus->GetState() == ON_SOMERSAULT_RIGHT || samus->GetState() == ON_JUMPING_SHOOTING_RIGHT)
		{
			samus->SetState(ON_JUMPING_SHOOTING_RIGHT);

			_Shoot(ON_RIGHT);
		}
		if (samus->GetState() == LEFTING)
		{
			samus->SetState(ON_RUN_SHOOTING_LEFT);

			_Shoot(ON_LEFT);
		}
		if (samus->GetState() == RIGHTING)
		{
			samus->SetState(ON_RUN_SHOOTING_RIGHT);

			_Shoot(ON_RIGHT);
		}
		if (samus->GetState() == IDLE_LEFT)
		{
			_Shoot(ON_LEFT);
		}
		if (samus->GetState() == IDLE_RIGHT)
		{
			_Shoot(ON_RIGHT);
		}
	}
	
}

void Metroid::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	srand((unsigned)time(NULL));
	_InitSprites(d3ddv);
	_InitPositions();

	Background = CreateSurfaceFromFile(_d3ddv, BACKGROUND_FILE);
	
	//Có thể chỗ này dư
	//samus->SetPosX(50);
	//samus->SetPosY(200);
	//
	//samus->SetVelocityX(0);
	//samus->SetVelocityXLast(1.0f);
	//samus->SetPosY(0);
}

void Metroid::OnKeyDown(int KeyCode)
{
	switch (KeyCode)
	{
	case DIK_DOWN:
		//if samus is idle then do morph
		if (samus->GetState() == IDLE_LEFT)
		{
			samus->SetVelocityX(0);
			samus->ResetAllSprites();
			samus->SetState(ON_MORPH_LEFT);
		}
		else if (samus->GetState() == IDLE_RIGHT)
		{
			samus->SetVelocityX(0);
			samus->ResetAllSprites();
			samus->SetState(ON_MORPH_RIGHT);
		}
		else if (samus->GetState() == ON_MORPH_LEFT) //otherwise, reset to idle (left of right)
		{
			samus->SetVelocityX(0);
			samus->ResetAllSprites();
			samus->SetState(IDLE_LEFT);
		}
		else if (samus->GetState() == ON_MORPH_RIGHT)
		{
			samus->SetVelocityX(0);
			samus->ResetAllSprites();
			samus->SetState(IDLE_RIGHT);
		}
		break;
	//case DIK_X:
	//	//**********************************************************************************
	//	// [CAUTION!!!] Vi pos_y chua chinh theo toa do World, code duoi day chi la tam thoi,
	//	// se cap nhat lai sau
	//	if (samus->GetPosY() >= GROUND_Y)
	//	{
	//		if (samus->GetVelocityXLast() < 0)
	//		{
	//			samus->SetState(ON_JUMP_LEFT);
	//			samus->SetVelocityY(samus->GetVelocityY() - JUMP_VELOCITY_BOOST);
	//		}
	//		else if (samus->GetVelocityXLast() > 0)
	//		{
	//			samus->SetState(ON_JUMP_RIGHT);
	//			samus->SetVelocityY(samus->GetVelocityY() - JUMP_VELOCITY_BOOST);
	//		}
	//	}
	//	//***********************************************************************************
	//	break;
	case DIK_LEFT:
		/*if (samus->GetState() == ON_JUMP_RIGHT)
			samus->SetState(ON_JUMP_LEFT);*/
		if (samus->GetState() == ON_MORPH_RIGHT)
			samus->SetState(ON_MORPH_LEFT);
		/*else if (samus->GetState() != ON_MORPH_LEFT && samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT 
			&& samus->GetState() != ON_SOMERSAULT_RIGHT)
			samus->SetState(LEFTING);*/
		break;
	case DIK_RIGHT:
		/*if (samus->GetState() == ON_JUMP_LEFT)
			samus->SetState(ON_JUMP_RIGHT);*/
		if (samus->GetState() == ON_MORPH_LEFT)
			samus->SetState(ON_MORPH_RIGHT);
		/*else if (samus->GetState() != ON_MORPH_RIGHT && samus->GetState() != ON_JUMP_LEFT && samus->GetState() != ON_JUMP_RIGHT
			&& samus->GetState() != ON_SOMERSAULT_LEFT)
			samus->SetState(RIGHTING);*/
		break;
	}

}
