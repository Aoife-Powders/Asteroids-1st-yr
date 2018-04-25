#pragma once
#include <SFML\Graphics.hpp>
class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void setUp(sf::Font&);
	void render(sf::RenderWindow&);
	void update(sf::Time, sf::Window&);

protected:
	//button number
	static const int buttonNumber = 4;
	//button background
	sf::Texture buttonBackground;
	//array fo button sprites
	sf::Sprite buttonSprites[buttonNumber];
	//font used by whole game
	sf::Font m_font;
	//array of text for buttons
	sf::Text buttonText[buttonNumber];
	/// sprite tiled to create background
	sf::Sprite m_backgroundSprite;
	//texture of wallpaper
	sf::Texture m_backgroundTexture;

};

