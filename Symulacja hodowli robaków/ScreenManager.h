#pragma once
#include <iostream>
#include "GameScreen.h"
#include "MenuScreen.h"
#include "RunScreen.h"


class ScreenManager
{
public:
	~ScreenManager();
	ScreenManager();
	static ScreenManager &GetInstance();

	void Initialize();
	void LoadContent(RenderWindow &window);
	void Update(RenderWindow &window, Event event);
	void Draw(RenderWindow &window);
	void AddScreen(GameScreen *screen);
	
};