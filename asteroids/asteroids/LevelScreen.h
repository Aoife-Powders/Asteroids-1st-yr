#pragma once
#include <SFML\Graphics.hpp>

class LevelScreen
{
public:
	LevelScreen();
	~LevelScreen();

	void update(sf::Time);
	void setUp(sf::Font&);
	void keyIsPressed(sf::Event event);
	void render(sf::RenderWindow&);

	sf::Font m_font;
	sf::Text message;
	bool buttonPressed;
	bool BPressed;
	static const int col1ButtonNumber = 3;
	static const int col2ButtonNumber = 3;
	static const int col3ButtonNumber = 3;
	sf::Texture buttonTexture;
	sf::Sprite col1ButtonSprite[col1ButtonNumber];
	sf::Text col1ButtonText[col1ButtonNumber];
	sf::Sprite col2ButtonSprite[col2ButtonNumber];
	sf::Text col2ButtonText[col2ButtonNumber];
	sf::Sprite col3ButtonSprite[col3ButtonNumber];
	sf::Text col3ButtonText[col3ButtonNumber];
};

