#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
#include "Worm.h"
#include "Options.h"

using namespace std;
using namespace sf;
class CreateWorms: public Options
{
public:
	CreateWorms();
	~CreateWorms();

	void createWorms( vector <Worm> &wormM, vector <Worm> &wormF, unsigned short x, unsigned short y);
	void addWorms(vector <Worm> &wormM, vector <Worm> &wormF, Vector2f position);
	Worm addOneWorm(bool isMale, Vector2f position);
private:
	Texture tWormM;
	Texture tWormF;
	int numberS;
};