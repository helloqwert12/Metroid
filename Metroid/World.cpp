#include "World.h"
#include "GroupObject.h"
#include "Brick.h"
#include "Camera.h"
#include "Bedgehog.h"

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

	zoomer = new Zoomer(spriteHandler, this);
	//brick = new Brick(spriteHandler, this, BLUE, 1, 32*3, 32*10);

	quadtreeGroup = new GroupObject(this);
	rootQNode = NULL;

	collisionGroup = new GroupObject(this);

	enemyGroup = new GroupObject(this);

	hog = new Bedgehog(spriteHandler, this, BEDGEHOG_YELLOW);
	hog->InitPostition(1280, 384);
	hog->InitSprites();
	hog->SetVelocityX(0);
	hog->SetVelocityY(0);
	enemyGroup->AddGameObject(hog);
}


World::~World()
{
	delete(samus);
	delete(zoomer);
}

void World::Update(float t)
{
	samus->Update(t);
	// Cập nhật các đối tượng hiển thị trong camera

	zoomer->Update(t);

	quadtreeGroup->GetCollisionObjectQTree();
	// Cập nhật các đối tượng có khả năng va chạm trong frame này
	collisionGroup->GetCollisionObjects();

	collisionGroup->Update(t);

	hog->Update(t);
	
}

void World::Render()
{
	samus->Render();
	zoomer->Render();
	quadtreeGroup->Render();
	hog->Render();
	collisionGroup->Render();
}
