#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScreenManager.h"
#include "const.h"
#include "Map.h"

#define _CRT_SECURE_NO_WARNINGS
//OGARNAC SZYBSZE ZNIKANIE PAJAKOW

using namespace sf;

int main()

{
	RenderWindow window(VideoMode(SCRN_WIDTH, SCRN_HEIGHT), "Symulacja hodowli robaków");
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().LoadContent(window);
	Map::GetInstace().loadMap();

	while (window.isOpen())
	{
		Event event;
		window.pollEvent(event);
		window.clear();
		ScreenManager::GetInstance().Update(window, event);
		ScreenManager::GetInstance().Draw(window);
		window.display();
	}

	return 0;
}