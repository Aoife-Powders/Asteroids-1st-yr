#pragma once
#include "SFML\Graphics.hpp"
class PauseScreen
{
public:
	PauseScreen();
	~PauseScreen();	
	void setUp(sf::Font&);
	void render(sf::RenderWindow&);
	void keyIsPressed(sf::Event);
	void update(sf::Time);
private:
	//local refrence to font used by game
	sf::Font m_font;
	//message for user help
	sf::Text m_message;
	//bool for leaving the screen
	bool m_escPressed;
	//bool for pauseing the screen
	bool m_PausePressed;
};

