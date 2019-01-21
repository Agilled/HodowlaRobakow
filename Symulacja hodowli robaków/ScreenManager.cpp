#include "ScreenManager.h"

GameScreen *Screen;

ScreenManager::ScreenManager()
{
}

ScreenManager::~ScreenManager()
{
}

ScreenManager & ScreenManager::GetInstance()
{
	static ScreenManager instance;
	return instance;
}

void ScreenManager::Initialize()
{
	Screen = new MenuScreen();
}

void ScreenManager::LoadContent(RenderWindow &window)
{
	Screen->LoadContent(window);
}

void ScreenManager::Update(RenderWindow &window, Event event)
{
	Screen->Update(window, event);
}

void ScreenManager::Draw(RenderWindow & window)
{
	Screen->Draw(window);
}

void ScreenManager::AddScreen(GameScreen * screen)
{
	Screen = screen;
}

