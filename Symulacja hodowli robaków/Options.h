#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Options
{
public:
	Options();
	~Options();

protected:
	int* optionsVar[6];
private:
	static int boardWidth;
	static int boardHeight;
	static int wormQuantity;
	static int health;
	static int foodRegeneration;
	static int lifeTime;


};