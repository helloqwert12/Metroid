#include "World.h"
#include "GroupObject.h"
#include "Brick.h"
#include "Camera.h"

World::World()
{
}

World::World(LPD3DXSPRITE spriteHandler, Metroid * metroid)
{
	//Gán
	this->spriteHandler = spriteHandler;
	this->metroid = metroid;

	//Khởi tạo các đối tượng trong World
	samus = new Samus(spriteHandler, this);
	//brick = new Brick(spriteHandler, this, BLUE, 1, 32*3, 32*10);
	quadtreeGroup = new GroupObject(this);
	rootQNode = NULL;
	
}


World::~World()
{
	delete(samus);
}

void World::Update(float t)
{
	samus->Update(t);
	quadtreeGroup->GetCollisionObjectQTree();
}

void World::Render()
{
	samus->Render();
	quadtreeGroup->Render();
	//brick->Render();
}
