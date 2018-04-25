#ifndef UPGRADEMENU_H
#define UPGRADEMENU_H


#include <SFML\Graphics.hpp>
class UpgradeMenu
{
public:
	UpgradeMenu();
	~UpgradeMenu();
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
};
#endif // !UPGRADEMENU_H
