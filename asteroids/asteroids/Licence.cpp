
#include "Licence.h"
#include "Game.h"

Licence::Licence()
{
}

Licence::~Licence()
{
}

//setup font and message
//sigle like of test used on licence screen
//proceeds to splsh screen after 0.8 seconds
void Licence::setUpMessage(sf::Font& font)
{
	m_font = font;
	m_message.setFont(m_font);
	m_message.setString("Hand Made By Aoife and Aaron");
	m_message.setCharacterSize(24);
	m_message.setColor(sf::Color::White);
	m_message.setPosition(150, 150);

}

//brief loop waits 0.8 seconds
//when greater than 0.8 moves on to splash screen
void Licence::update(sf::Time time)
{
	m_pauseTime += time;
	if (m_pauseTime.asSeconds() > 1)
	{
		Game::currentState = GameState::Splash;
	}
}

//draws licence text
void Licence::render(sf::RenderWindow& m_Window)
{
	m_Window.draw(m_message);
}


