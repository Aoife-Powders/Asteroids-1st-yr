#include "UpgradeMenu.h"
#include "Game.h"
#include <iostream>


UpgradeMenu::UpgradeMenu()
{
}


UpgradeMenu::~UpgradeMenu()
{
}

void UpgradeMenu::setUp(sf::Font & font)
{
	m_font = font;

	m_message.setFont(m_font);
	m_message.setString("buy the upgrades here  ");
	m_message.setCharacterSize(34);
	m_message.setColor(sf::Color::Blue);
	m_message.setPosition(100, 100);

	m_escPressed = false;
}

void UpgradeMenu::render(sf::RenderWindow & window)
{
	window.draw(m_message);
}

void UpgradeMenu::keyIsPressed(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::BackSpace)
		{
			m_escPressed = true;
		}
	}

}

void UpgradeMenu::update(sf::Time)
{
	if (m_escPressed)
	{
		Game::currentState = GameState::Menu;
	}
	m_escPressed = false;
}