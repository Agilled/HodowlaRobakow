#include "Options.h"

int Options::boardWidth = 20;//20
int Options::boardHeight = 11;//11
int Options::wormQuantity = 5;//5
int Options::health = 8;//8
int Options::foodRegeneration = 13;//13
int Options::lifeTime = 75;//75


Options::Options()
{
	optionsVar[0] = &boardWidth;
	optionsVar[1] = &boardHeight;
	optionsVar[2] = &wormQuantity;
	optionsVar[3] = &health;
	optionsVar[4] = &foodRegeneration;
	optionsVar[5] = &lifeTime;
}

Options::~Options()
{
}
