#include "MenuScreen.h"
#include "const.h"

MenuScreen::MenuScreen()
{
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::LoadContent(RenderWindow &window)
{
	font.loadFromFile("data/CaviarDreams.ttf");

	title.setFont(font);
	title.setString("Symulacja Hodowli Robakow");
	title.setCharacterSize(80);
	title.setPosition(SCRN_WIDTH / 2 - title.getGlobalBounds().width / 2, 20);

	string str[] = {"Start", "Wyjscie"};

	for (int i = 0; i < 2; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(65);
		text[i].setString(str[i]);
		text[i].setPosition(SCRN_WIDTH  / 2 - text[i].getGlobalBounds().width / 2, 2 * SCRN_HEIGHT / 7 + i * 300);
	}
}


void MenuScreen::Update(RenderWindow &window, Event event)
{
	Vector2f mouse(Mouse::getPosition(window));

	for (int i = 0; i < 2; i++)
		if (text[i].getGlobalBounds().contains(mouse))

			text[i].setFillColor(Color(233, 150, 122));

		else
			text[i].setFillColor(Color::White);

	if (event.type == Event::MouseButtonReleased  && event.mouseButton.button == Mouse::Left && text[0].getGlobalBounds().contains(mouse))
	{
		ScreenManager::GetInstance().AddScreen(new RunScreen);
	}

	else if (event.type == Event::MouseButtonReleased  && event.mouseButton.button == Mouse::Left && text[1].getGlobalBounds().contains(mouse) || event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}
}

void MenuScreen::Draw(RenderWindow & window)
{
	window.draw(title);
	for (int i = 0; i < 2; i++)
		window.draw(text[i]);

}
