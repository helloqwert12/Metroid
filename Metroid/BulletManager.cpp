#include "BulletManager.h"



BulletManager::BulletManager()
{
	//Create instance bullet_list
	bullet_list = new Bullet*[BULLET_COUNT];
}

BulletManager::BulletManager(int posX, int posY)
{
	this->pos_x_holder = posX;
	this->pos_y_holder = posY;
}


BulletManager::~BulletManager()
{
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		delete(bullet_list[i]);
	}
	delete(bullet_list);
}

void BulletManager::Init(LPDIRECT3DDEVICE9 d3ddv)
{
	for (int i = 0; i < BULLET_COUNT; i++)
	{
		bullet_list[i] = new Bullet(pos_x_holder, pos_y_holder);
		bullet_list[i]->InitSprites(d3ddv);
		bullet_list[i]->InitPosition(pos_x_holder, pos_y_holder);
	}
}

void BulletManager::Reset()
{
	_Index = 0;
}

void BulletManager::Next(BULLET_DIRECTION dir)
{
	_Index = (_Index + BULLET_COUNT - 1) % BULLET_COUNT;
}

void BulletManager::Update(int t, int posX, int posY)
{
	pos_x_holder = posX;
	pos_y_holder = posY;

	for (int i = 0; i < BULLET_COUNT; i++)
	{
		bullet_list[i]->Update(t, posX, posY);
	}
}
