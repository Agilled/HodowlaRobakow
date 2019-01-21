#pragma once
#include <SFML\Graphics.hpp>
#include "Worm.h"
#include <vector>
#include "const.h"
#include "Map.h"

using namespace sf;
using namespace std;

class UpdateWorm
{
public:
	UpdateWorm(float speed);
	~UpdateWorm();
	void update(vector <Worm> &worm, float deltaTime);
	Vector2f movement;
private:
	void moveWorm(vector <Worm> &worm,float deltaTime);
	void checkBorderCollision(Worm &worm);
	Clock time;
	float speed;
};