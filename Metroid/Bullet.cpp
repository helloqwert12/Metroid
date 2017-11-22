#include "Bullet.h"



void Bullet::_Render()
{
	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	bullet->Render(pos_x, pos_y, pos_x_holder - 400, 600);
	_SpriteHandler->End();
}

Bullet::Bullet()
{
	bullet = NULL;
}

Bullet::Bullet(int x_holder, int y_holder)
{
	pos_x_holder = x_holder;
	pos_y_holder = y_holder;
}


Bullet::~Bullet()
{
	delete(bullet);
}

void Bullet::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result = D3DXCreateSprite(d3ddv, &_SpriteHandler);
	if (result != D3D_OK) return;

	//Create sprite
	bullet = new Sprite(_SpriteHandler, BULLET_SPRITE_PATH, BULLET_SPRITE, BULLET_WIDTH, BULLET_HEIGHT, BULLET_COUNT, SPRITE_PER_ROW);
}

void Bullet::InitPosition(int posX, int posY)
{
	pos_x = posX;
	pos_y = posY;

	pos_x_holder = posX;
	pos_y_holder = posY;

}

BULLET_DIRECTION Bullet::GetDirection()
{
	return direction;
}

void Bullet::SetDirection(BULLET_DIRECTION value)
{
	direction = value;
}

void Bullet::Update(int t, int posX, int posY)
{
	//
	// Update bullet status
	//
	switch (direction)
	{
	case ON_LEFT:
		vx = -SPEED;
		vy = 0;
		break;
	case ON_RIGHT:
		vx = SPEED;
		vy = 0;
		break;
	case ON_UP:
		vy = SPEED;
		vx = 0;
		break;
	}
	
	pos_x += vx*t;
	pos_y += vy*t;

	//Update position of samus
	pos_x_holder = posX;
	pos_y_holder = posY;

	//Render
	_Render();
}
