#include "backstory.h"
#include "Game.h"
#include <iostream>

backstory::backstory()
{
}


backstory::~backstory()
{
}

void backstory::setUp(sf::Font & font)
{
	m_font = font;

	m_message.setFont(m_font);
	m_message.setString(" backstory ");
	m_message.setCharacterSize(34);
	m_message.setColor(sf::Color::Red);
	m_message.setPosition(100, 100);

	m_escPressed = false;
}

void backstory::render(sf::RenderWindow & window)
{
	window.draw(m_message);

}

void backstory::keyIsPressed(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			m_escPressed = true;
		}
	}
}

void backstory::update(sf::Time)
{
	if (m_escPressed)
	{
		Game::currentState = GameState::Game;
	}
	m_escPressed = false;
}
