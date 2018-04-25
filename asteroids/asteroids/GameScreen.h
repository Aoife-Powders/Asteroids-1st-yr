#pragma once
#include <SFML\Graphics.hpp>

class GameScreen
{
public:
	GameScreen();
	~GameScreen();
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
	bool m_pausePressed;
};

