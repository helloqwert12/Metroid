#pragma once
#ifndef _BULLETMANAGER_H_
#define _BULLETMANAGER_H_
#include "Bullet.h"

#define BULLET_COUNT 20

class BulletManager
{
private:
	Bullet ** bullet_list;
	int pos_x_holder;
	int pos_y_holder;
	int _Index;

	void _Render();
public:
	BulletManager();
	BulletManager(int posX, int posY);
	~BulletManager();
	void Init(LPDIRECT3DDEVICE9 d3ddv);
	void Reset();
	void Next(BULLET_DIRECTION dir);
	void Update(int t, int posX, int posY);
};

#endif // !_BULLETMANAGER_H_



