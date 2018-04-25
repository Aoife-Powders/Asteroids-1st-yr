#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H
#include <SFML\Graphics.hpp>
class SplashScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void setUp(sf::Font&);
	void render(sf::RenderWindow&);
	void KeyIsPressed(sf::Event);
	void update(sf::Time);

private:

	//texture of wallpaper
	sf::Texture m_splashTexture;
	/// sprite tiled to create background
	sf::Sprite m_splashSprite;
	///  refrence to font used by the game
	sf::Font m_font;
	/// text to display
	sf::Text m_message;
	/// if input is taken
	bool m_KeyPressed;

};

#endif