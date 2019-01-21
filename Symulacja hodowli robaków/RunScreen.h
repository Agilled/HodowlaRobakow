#pragma once
#include "ScreenManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Worm.h"
#include "CreateWorms.h"
#include "UpdateWorm.h"
#include "Food.h"
#include "const.h"
#include "Options.h"
#include "Eggs.h"

using namespace std;
using namespace sf;

class RunScreen : public GameScreen, public Options
{
public:
	RunScreen();
	~RunScreen();

	void Update(RenderWindow &window, Event event);
	void Draw(RenderWindow &window);
private:
	Time lastUpdate;
	Clock time;
	int WIDTH;
	int HEIGHT;
	int TRUEWIDTH;
	int TRUEHEIGHT;
	float push;
	Texture texture;
	vector<vector<Sprite>> sprite;

	CreateWorms createWorms;
	vector <Worm> wormM;
	vector <Worm> wormF;
	vector <Worm*> wormInPregnacy;

	UpdateWorm updateworm;
	Food food;
	Eggs eggs;
};