#include "RunScreen.h"

RunScreen::RunScreen() :updateworm(10.0f)
{
	push = 0.0f;
	texture.loadFromFile("data/tile.png");
	WIDTH = SCRN_WIDTH / TILE_SIZE;
	HEIGHT = SCRN_HEIGHT / TILE_SIZE;

	Sprite standard(texture);
	if (Map::GetInstace().getHeight() < HEIGHT)
		TRUEHEIGHT = Map::GetInstace().getHeight();
	else
		TRUEHEIGHT = HEIGHT;

	if (Map::GetInstace().getWidth() < WIDTH)
	{
		TRUEWIDTH = Map::GetInstace().getWidth();
	}
	else
	{
		TRUEWIDTH = WIDTH;
	}
	
	sprite.resize(Map::GetInstace().getHeight());
	for (int y = 0; y < Map::GetInstace().getHeight(); y++)
	{
		sprite[y].resize(Map::GetInstace().getWidth(), standard);
	}
	
	for (int y = 0; y < Map::GetInstace().getHeight(); y++)
	{
		for (int x = 0; x < Map::GetInstace().getWidth(); x++)
		{
			sprite[y][x].setPosition(x*TILE_SIZE, y*TILE_SIZE);
			sprite[y][x].setTexture(texture);
		}
	}
	createWorms.createWorms(wormM, wormF, Map::GetInstace().getWidth(), Map::GetInstace().getHeight());
	food.generateFood();
}


RunScreen::~RunScreen()
{
}

void RunScreen::Update(RenderWindow & window, Event event)
{
	if (event.type == Event::Closed) window.close();
	
	float deltaTime = time.getElapsedTime().asSeconds() - lastUpdate.asSeconds();
	updateworm.update(wormM, deltaTime);
	updateworm.update(wormF, deltaTime);
	deltaTime = time.getElapsedTime().asSeconds() - lastUpdate.asSeconds();
	food.update(deltaTime);

	for (int i = 0; i < wormInPregnacy.size(); i++)
	{
		wormInPregnacy[i]->pregnacyTime -= deltaTime;
		if (wormInPregnacy[i]->pregnacyTime <= 0)
		{
			wormInPregnacy[i]->pregnacyTime = 5;
			wormInPregnacy[i] = wormInPregnacy[wormInPregnacy.size() - 1];
			wormInPregnacy.pop_back();
			i--;
		}
	}

	for (int i = 0; i < eggs.eggs.size(); i++)
	{
		eggs.eggs[i].time -= deltaTime;
		if (eggs.eggs[i].time <= 0)
		{
			createWorms.addWorms(wormM, wormF, eggs.eggs[i].shape.getPosition());
			eggs.eggs[i] = eggs.eggs[eggs.eggs.size() - 1];
			eggs.eggs.pop_back();
			i--;
		}
	}
	lastUpdate = time.getElapsedTime();
	
	for (int i = 0; i < wormM.size(); i++)
	{
		for (int j = 0; j < wormM.size(); j++)
		{
			if (i == j) {
				continue;
			}
			wormM[i].getCollider().CheckCollision(wormM[j].getCollider(), 0.0f);
		}
		int eat = food.isEating(wormM[i], *optionsVar[4]);
		if (eat > 0)
		{
			wormM[i].hp = *optionsVar[3];
		}

	}

	for (int i = 0; i < wormF.size(); i++)
	{
		for (int j = 0; j < wormF.size(); j++)
		{
			if (i == j) {
				continue;
			}
			wormF[i].getCollider().CheckCollision(wormF[j].getCollider(), 0.0f);
		}
		for (int j = 0; j < wormM.size(); j++)
		{
			if(wormF[i].getCollider().CheckCollision(wormM[j].getCollider(), 0.0f))
			{
				if (wormF[i].pregnacyTime >= 5)
				{
					wormF[i].pregnacyTime -= 0.01;
					wormInPregnacy.push_back(&wormF[i]);
					eggs.addEgg(wormF[i].getX(), wormF[i].getY());
				}
			}
		}
		int eat = food.isEating(wormF[i], *optionsVar[4]);
		if (eat > 0)
		{
			wormF[i].hp = *optionsVar[3];
		}
	}

}

void RunScreen::Draw(RenderWindow & window)
{
	for (int y = 0; y < sprite.size(); y++)
	{
		for (int x = 0; x < sprite[y].size(); x++)
			window.draw(sprite[y][x]);
	}
	food.draw(window);
	eggs.draw(window);

	for (int i = 0; i < wormF.size(); i++)
	{
		wormF[i].draw(window);
	}

	for (int i = 0; i < wormM.size(); i++)
	{
		wormM[i].draw(window);
	}
}