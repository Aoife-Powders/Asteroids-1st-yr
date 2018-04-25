#include <iostream>
#include "SplashScreen.h"
#include "Game.h"


SplashScreen::SplashScreen()
{
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::setUp(sf::Font & font)
{

	m_font = font;
	//load the background 
	if (!m_splashTexture.loadFromFile("ASSETS\\IMAGES\\splash-png-12.png"))
	{
		std::cout << " error with the splash screen ";
	}

	m_splashSprite.setTexture(m_splashTexture);
	m_splashSprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(Game::screenWidth), static_cast<int>(Game::screenHeight)));
	m_splashSprite.setPosition(0, 0);

	//set up for continue message .
	m_message.setFont(m_font); 
	m_message.setString("Press space to cotinue");
	m_message.setCharacterSize(24);
	m_message.setStyle(sf::Text::Bold);
	m_message.setColor(sf::Color::White);
	m_message.setPosition(150, 150);
	m_KeyPressed = false;
}

void SplashScreen::KeyIsPressed(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			m_KeyPressed = true;
		}
	}
}

void SplashScreen::update(sf::Time time)
{
	if (m_KeyPressed)
	{
		Game::currentState = GameState::Menu;
	}
	m_KeyPressed = false;
}
void SplashScreen::render(sf::RenderWindow & window)
{
	window.draw(m_splashSprite);
	window.draw(m_message);
}