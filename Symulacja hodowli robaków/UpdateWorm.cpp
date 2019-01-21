#include "UpdateWorm.h"
#include <iostream>
#include <random>

UpdateWorm::UpdateWorm(float speed)
{
	this->speed = speed;
	movement.x = 0.0f;
	movement.y = 0.0f;
}

UpdateWorm::~UpdateWorm()
{
}

void UpdateWorm::update(vector <Worm> &worm, float deltaTime)
{
	time.restart();
	moveWorm(worm, deltaTime);
	deltaTime += time.getElapsedTime().asSeconds();
	for (int i = 0; i < worm.size(); i++)
	{
		worm[i].lifeTime -= deltaTime;
		worm[i].hp -= deltaTime;
		if(worm[i].lifeTime <= 0 || worm[i].hp <= 0)
		{

			worm.pop_back();
		}

	}


}

void UpdateWorm::moveWorm(vector<Worm>& worm, float deltaTime)
{

	random_device generator;
	uniform_int_distribution<int> distribution(1, 4);
	int random = 0;

	for (int i = 0; i < worm.size(); i++)
	{
		movement.x = 0.0f;
		movement.y = 0.0f;
		random = distribution(generator);
		worm[i].random = random;

		switch (worm[i].random)
		{
		case 1:
			movement.x -= speed * deltaTime;
			break;
		case 2:
			movement.y -= speed * deltaTime;
			break;
		case 3:
			movement.x += speed * deltaTime;
			break;
		case 4:
			movement.y += speed * deltaTime;
			break;
		default:
			break;
		}
		worm[i].addMovement(movement.x, movement.y);
		checkBorderCollision(worm[i]);

		movement = worm[i].getMovement();
		worm[i].move(movement.x, movement.y);
	}
}

void UpdateWorm::checkBorderCollision(Worm& worm)
{
	Vector2f movement = worm.getMovement();
	Vector2f nextPos(worm.getX() + movement.x, worm.getY() + movement.y);

	if (nextPos.x <= 0.0f)
	{
		worm.setPosition(0, worm.getY());
		worm.setMovement(-movement.x, movement.y);
	}
	if (nextPos.x >= Map::GetInstace().getWidth()*TILE_SIZE - worm.getGlobalBounds().width)
	{
		worm.setPosition(Map::GetInstace().getWidth()*TILE_SIZE - worm.getGlobalBounds().width, worm.getY());
		worm.setMovement(-movement.x, movement.y);
	}
	if (nextPos.y <= 0.0f)
	{
		worm.setPosition(worm.getX(), 0);
		worm.setMovement(movement.x, -movement.y);
	}
	if (nextPos.y >= Map::GetInstace().getHeight()*TILE_SIZE - worm.getGlobalBounds().height)
	{
		worm.setPosition(worm.getX(), Map::GetInstace().getHeight()*TILE_SIZE - worm.getGlobalBounds().height);
		worm.setMovement(movement.x, -movement.y);
	}
}
