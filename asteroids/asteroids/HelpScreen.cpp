
#include "HelpScreen.h"
#include "Game.h"
#include <iostream>


HelpScreen::HelpScreen()
{
}


HelpScreen::~HelpScreen()
{
}

void HelpScreen::setUp(sf::Font & font ) 
{
	m_font = font;
	 
	m_message.setFont(m_font);
	m_message.setString("help help help help help \n ");
	m_message.setCharacterSize(34);
	m_message.setColor(sf::Color::Red);
	m_message.setPosition(100, 100);

	m_escPressed = false;
}

void HelpScreen::render(sf::RenderWindow & window)
{
	window.draw(m_message);
}

void HelpScreen::keyIsPressed(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::BackSpace)
		{
			m_escPressed = true;
		}
	}

}

void HelpScreen::update(sf::Time)
{
	if (m_escPressed)
	{
		Game::currentState = GameState::Menu;
	}
	m_escPressed = false;
}

