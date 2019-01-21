#include "Worm.h"

Worm::Worm()
{
	hp = *optionsVar[3];
	lifeTime = *optionsVar[5];
	texture = NULL;
	isMale = true;
	textureSize.x = 0;
	textureSize.y = 0;
	random = 0;
	movement.x = 0;
	movement.y = 0;
	maxMovement = 0.8;
	pregnacyTime = 0;
}

Worm::~Worm()
{
}



void Worm::move(float x, float y)
{
	sprite.move(x, y);
}



void Worm::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Worm::setTexture(Texture &t)
{
	texture = &t;
	sprite.setTexture(*texture);
}

void Worm::addMovement(float x, float y)
{
	movement.x += x;
	movement.y += y;

	if (movement.x > maxMovement)
		movement.x = maxMovement;
	else if (movement.x < -maxMovement)
		movement.x = -maxMovement;

	if (movement.y > maxMovement)
		movement.y = maxMovement;
	else if (movement.y < -maxMovement)
		movement.y = -maxMovement;

}

void Worm::setMovement(float x, float y)
{
	movement.x = x;
	movement.y = y;

	if (movement.x > maxMovement)
		movement.x = maxMovement;
	else if (movement.x < -maxMovement)
		movement.x = -maxMovement;

	if (movement.y > maxMovement)
		movement.y = maxMovement;
	else if (movement.y < -maxMovement)
		movement.y = -maxMovement;
}

Vector2f Worm::getMovement()
{
	return movement;
}

void Worm::draw(RenderWindow &window)
{
	window.draw(sprite);
}


void Worm::setMale(bool t)
{
	isMale = t;
}

bool Worm::getMale()
{
	return isMale;
}

float Worm::getX()
{
	return sprite.getPosition().x;
}

float Worm::getY()
{
	return sprite.getPosition().y;
}

FloatRect Worm::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}


Collider Worm::getCollider()
{
	return Collider(sprite);
}


