#pragma once
#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_


#include <d3dx9.h>

class GameObject
{
protected:
	int pos_x;		// x postition of samus
	int pos_y;		// y position of samus

	float vx;		//x velocity
	float vy;		//y velocity

	float vx_last; // last vx of samus before stop ( to determine the direction of samus)
	float vy_last;

	DWORD last_time; // this is to control the animate rate of kitty

	float width = 16;
	float height = 16;
	float lastPosX;
	float lastPosY;
public:
	GameObject();
	~GameObject();

	void setlastPosX(float posx)
	{
		this->lastPosX = posx;
	}
	void setlastPosY(float posy)
	{
		this->lastPosY = posy;
	}

	float getlastPosX()
	{
		return this->lastPosX;
	}
	float getlastPosY()
	{
		return lastPosY;
	}

	void SetVelocityX(float value);
	float GetVelocityX();

	void SetVelocityY(float value);
	float GetVelocityY();

	void SetPosX(int value);
	int GetPosX();
	void SetPosY(int value);
	int GetPosY();

	void SetVelocityXLast(float value);
	float GetVelocityXLast();

	void SetVelocityYLast(float value)
	{
		this->vy_last = value;
	}
	float GetVelocityYLast()
	{
		return this->vy_last;
	}

	void SetWidth(float value);
	float GetWidth();

	void SetHeight(float value);
	float GetHeight();

	virtual void Update();
	virtual void _Render();
};
#endif // !_GAME_OBJECT_
