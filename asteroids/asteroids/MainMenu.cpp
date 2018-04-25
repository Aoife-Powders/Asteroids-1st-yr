#include "MainMenu.h"
#include "Game.h"


MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}

// load texture and setup sprite and text for each button and positions on screen
void MainMenu::setUp(sf::Font& font)
{
	//load the background 
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\mainMenu.jpg"))
	{
		std::cout << " error with the main menu screen ";
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(Game::screenWidth), static_cast<int>(Game::screenHeight)));
	m_backgroundSprite.setPosition(0, 0);

	sf::String Text[] = { "Start", "Help", "Upgrade", "Exit" };

	m_font = font;
	if (!buttonBackground.loadFromFile("ASSETS/IMAGES/mainmenu_button.png"))
	{
		std::cout << "error with button file";
	}

	for (int i = 0; i < buttonNumber; i++)
	{
		
		buttonSprites[i].setTexture(buttonBackground);
		buttonSprites[i].setTextureRect(sf::IntRect(0, 0, 250, 77));
		buttonSprites[i].setPosition(300, (i*100)+110);

		
		buttonText[i].setFont(m_font);
		buttonText[i].setString(Text[i]);
		buttonText[i].setColor(sf::Color::Cyan);	
		buttonText[i].setCharacterSize(24);
		buttonText[i].setPosition(370, (i * 100 )+140);
	}
}
void MainMenu::update(sf::Time, sf::Window& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		Game::currentState = GameState::Help;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		Game::currentState = GameState::levelSelect;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		Game::currentState = GameState::upgrade;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}

}

void MainMenu::render(sf::RenderWindow& window)
{
	window.draw(m_backgroundSprite);
	for (int i = 0; i < buttonNumber; i++)
	{
		window.draw(buttonSprites[i]);
		window.draw(buttonText[i]);
	}

}