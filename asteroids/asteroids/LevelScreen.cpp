#include "LevelScreen.h"
#include "Game.h"


LevelScreen::LevelScreen()
{
}


LevelScreen::~LevelScreen()
{
}

void LevelScreen::update(sf::Time)
{
	if (buttonPressed == true)
	{
		Game::currentState = GameState::Menu;
	}
	buttonPressed = false;
}

void LevelScreen::setUp(sf::Font& font)
{
	m_font = font;

	if (!buttonTexture.loadFromFile("ASSETS/IMAGES/mainmenu_button.png"))
	{
		std::cout << "error with button file";
	}

	for (int i = 0; i < col1ButtonNumber; i++)
	{

		sf::String Text[] = { "Lvl 1", "Lvl 2", "Lvl 3" };

		col1ButtonSprite[i].setTexture(buttonTexture);
		col1ButtonSprite[i].setPosition(0, 140 * i);
		col1ButtonSprite[i].setTextureRect(sf::IntRect(0, 0, 250, 77));

		col1ButtonText[i].setFont(m_font);
		col1ButtonText[i].setString(Text[i]);
		col1ButtonText[i].setColor(sf::Color::White);
		col1ButtonText[i].setCharacterSize(34);
		col1ButtonText[i].setPosition(90, 150 * i);
	}

	for (int i = 0; i < col2ButtonNumber; i++)
	{

		sf::String Text[] = { "Lvl 4", "Lvl 5", "Lvl 6" };

		col2ButtonSprite[i].setTexture(buttonTexture);
		col2ButtonSprite[i].setPosition(300, 140 * i);
		col2ButtonSprite[i].setTextureRect(sf::IntRect(0, 0, 250, 77));

		col2ButtonText[i].setFont(m_font);
		col2ButtonText[i].setString(Text[i]);
		col2ButtonText[i].setColor(sf::Color::White);
		col2ButtonText[i].setCharacterSize(34);
		col2ButtonText[i].setPosition(410, 150 * i);
	}

	for (int i = 0; i < col3ButtonNumber; i++)
	{

		sf::String Text[] = { "Lvl 7", "Lvl 8", "Lvl 9" };

		col3ButtonSprite[i].setTexture(buttonTexture);
		col3ButtonSprite[i].setPosition(600, 140 * i);
		col3ButtonSprite[i].setTextureRect(sf::IntRect(0, 0, 250, 77));

		col3ButtonText[i].setFont(m_font);
		col3ButtonText[i].setString(Text[i]);
		col3ButtonText[i].setColor(sf::Color::White);
		col3ButtonText[i].setCharacterSize(34);
		col3ButtonText[i].setPosition(690, 150 * i);
	}
	buttonPressed = false;
}

void LevelScreen::keyIsPressed(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::BackSpace)
		{
			buttonPressed = true;
		}
		if (event.key.code == sf::Keyboard::B)
		{
			Game::currentState = GameState::story;
		}
	}
}

void LevelScreen::render(sf::RenderWindow& window)
{
	for (int i = 0; i < col1ButtonNumber; i++)
	{
		window.draw(col1ButtonSprite[i]);
		window.draw(col1ButtonText[i]);
	}

	for (int i = 0; i < col2ButtonNumber; i++)
	{
		window.draw(col2ButtonSprite[i]);
		window.draw(col2ButtonText[i]);
	}

	for (int i = 0; i < col3ButtonNumber; i++)
	{
		window.draw(col3ButtonSprite[i]);
		window.draw(col3ButtonText[i]);
	}
}
