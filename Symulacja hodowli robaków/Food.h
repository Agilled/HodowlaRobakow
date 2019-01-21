#pragma once
#include "Worm.h"
#include "Options.h"
#include "Map.h"

class Food
{
public:
	Food();
	~Food();

	void generateFood();
	void draw(RenderWindow &window);
	void eaten(int i, int j, int cooldown);
	void update(float deltaTime);
	int isEating(Worm worm, float cooldown);

	struct Circle: Options {
		CircleShape shape;
		bool active;
		float cooldownInSec = (float)*optionsVar[4];
	};

	vector <vector <Circle>> foods;
	vector <Circle*> foodsInCd;
};