#include "PauseScreen.h"
#include "Game.h"
#include <iostream>


PauseScreen::PauseScreen()
{
}


PauseScreen::~PauseScreen()
{
}

void PauseScreen::setUp(sf::Font & font)
{
	m_font = font;

	m_message.setFont(m_font);
	m_message.setString("pause");
	m_message.setCharacterSize(34);
	m_message.setColor(sf::Color::Green);
	m_message.setPosition(100, 100);

	m_escPressed = false;
	m_PausePressed = false;
}

void PauseScreen::render(sf::RenderWindow & window)
{
	window.draw(m_message);
}

void PauseScreen::keyIsPressed(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::BackSpace)
		{
			m_escPressed = true;
		}
	}
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::P)
		{
			m_PausePressed = true;
		}
	}
}

void PauseScreen::update(sf::Time)
{
	if (m_escPressed)
	{
		Game::currentState = GameState::Menu;
	}
	m_escPressed = false;
	if (m_PausePressed)
	{
		Game::currentState = GameState::Game;    
	}
	 m_PausePressed = false;
}
