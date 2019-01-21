#include "CreateWorms.h"
#include "const.h"
#include <random>

CreateWorms::CreateWorms()
{
	tWormM.loadFromFile("data/blob1.png");
	tWormF.loadFromFile("data/blob6.png");
	numberS = *optionsVar[2];
}

CreateWorms::~CreateWorms()
{
}

void CreateWorms::createWorms(vector <Worm> &wormM, vector <Worm> &wormF, unsigned short x, unsigned short y)
{
	random_device generator;
	uniform_int_distribution<int> randomX(0, x);
	uniform_int_distribution<int> randomY(0, y);
	uniform_int_distribution<int> rmovement(0, 200);

	wormM.resize(numberS);
	wormF.resize(numberS);

	for (int i = 0; i < numberS; i++)
	{
		
		wormM[i].setPosition(randomX(generator) * TILE_SIZE, randomY(generator) * TILE_SIZE);
		wormF[i].setPosition(randomX(generator) * TILE_SIZE, randomY(generator) * TILE_SIZE);
		wormF[i].setMale(false);
		wormF[i].pregnacyTime = 5;

		wormM[i].setTexture(tWormM);
		wormM[i].textureSize = tWormM.getSize();
		wormM[i].setMovement(rmovement(generator)/200, rmovement(generator) / 200);
		
		wormF[i].setTexture(tWormF);
		wormF[i].textureSize = tWormF.getSize();
		wormF[i].setMovement(rmovement(generator)/200, rmovement(generator) / 200);
	}
}

void CreateWorms::addWorms(vector <Worm> &wormM, vector <Worm> &wormF, Vector2f position)
{
	random_device generator;
	uniform_int_distribution<int> one(0, 1);

	if (one(generator))
	{
		wormM.push_back(addOneWorm(1, position));
	}
	else wormF.push_back(addOneWorm(0, position));
}

Worm CreateWorms::addOneWorm(bool isMale, Vector2f position)
{
	random_device generator;
	uniform_int_distribution<int> rmovement(0, 100);

	Worm newWorm;

	newWorm.setPosition(position.x, position.y);
	newWorm.setMale(isMale);
	if (newWorm.getMale())
	{
		newWorm.setTexture(tWormM);
		newWorm.textureSize = tWormM.getSize();
	}
	else
	{
		newWorm.setTexture(tWormF);
		newWorm.textureSize = tWormF.getSize();
		newWorm.pregnacyTime = 5;
	}

	newWorm.textureSize.x /= 7;
	newWorm.textureSize.y /= 5;
	newWorm.setMovement(rmovement(generator) / 100, rmovement(generator) / 100);
	return newWorm;
}