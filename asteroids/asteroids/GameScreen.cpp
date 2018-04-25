#include "GameScreen.h"
#include "Game.h"
#include <iostream>



GameScreen::GameScreen()
{
}


GameScreen::~GameScreen()
{
}

void GameScreen::setUp(sf::Font & font)
{
	m_font = font;

	m_message.setFont(m_font);
	m_message.setString("game here");
	m_message.setCharacterSize(34);
	m_message.setColor(sf::Color::Green);
	m_message.setPosition(100, 100);

	m_pausePressed = false;
}

void GameScreen::render(sf::RenderWindow & window)
{
	window.draw(m_message);
}

void GameScreen::keyIsPressed(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::P)
		{
			m_pausePressed = true;
		}
	}

}

void GameScreen::update(sf::Time)
{
	if (m_pausePressed)
	{
		Game::currentState = GameState::pause;
	}
	m_pausePressed = false;
}

