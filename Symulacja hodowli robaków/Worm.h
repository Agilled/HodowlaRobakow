#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "Options.h"

using namespace sf;

class Worm: public Options
{
public:
	Worm();
	~Worm();

	void move(float x, float y);
	void setPosition(float x, float y);
	void setTexture(Texture &t);
	void addMovement(float x, float y);
	void setMovement(float x, float y);
	void setMale(bool);
	Vector2f getMovement();
	bool getMale();
	float getX();
	float getY();
	Collider getCollider();
	FloatRect getGlobalBounds();
	void draw(RenderWindow &window);
	Vector2u textureSize;
	int random;
	float lifeTime;
	float pregnacyTime;
	float hp;
private:
	Sprite sprite;
	bool isMale;
	Vector2f movement;
	float maxMovement;
	Texture *texture;
};

