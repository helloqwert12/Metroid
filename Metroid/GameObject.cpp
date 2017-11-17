#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::_Render()
{
}

void GameObject::Update()
{
}

void GameObject::SetVelocityX(float value)
{
	vx = value;
}

float GameObject::GetVelocityX()
{
	return vx;
}

void GameObject::SetVelocityY(float value)
{
	vy = value;
}

float GameObject::GetVelocityY()
{
	return vy;
}

void GameObject::SetPosX(int value)
{
	pos_x = value;
}

int GameObject::GetPosX()
{
	return pos_x;
}

void GameObject::SetPosY(int value)
{
	pos_y = value;
}

int GameObject::GetPosY()
{
	return pos_y;
}

void GameObject::SetVelocityXLast(float value)
{
	vx_last = value;
}

float GameObject::GetVelocityXLast()
{
	return vx_last;
}

void GameObject::SetWidth(float value)
{
	width = value;
}

float GameObject::GetWidth()
{
	return width;
}

void GameObject::SetHeight(float value)
{
	height = value;
}

float GameObject::GetHeight()
{
	return height;
}
