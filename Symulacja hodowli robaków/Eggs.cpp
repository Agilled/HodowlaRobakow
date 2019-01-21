#include "Eggs.h"

Eggs::Eggs()
{
}

Eggs::~Eggs()
{
}

void Eggs::addEgg(float x, float y)
{
	CircleShape egg;
	egg.setPosition(Vector2f(x,y));
	egg.setRadius(15.0f);
	egg.setOutlineThickness(7.5f);
	egg.setFillColor(Color(0, 249, 129));
	egg.setOutlineColor(Color(168, 0, 115));

	Egg newEgg;
	newEgg.shape = egg;
	newEgg.time = 5;
	eggs.push_back(newEgg);
}

void Eggs::draw(RenderWindow & window)
{
	for (int i = 0; i < eggs.size(); i++)
	{
		window.draw(eggs[i].shape);
	}
}