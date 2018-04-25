//author Aoife Powders and Aaron O Dea
//date: Febuary 2017
//display licence texted for certain amount of time

#ifndef LICENCE_H
#define LICENCE_H

#include <SFML\Graphics.hpp>

class Licence
{
public:
	Licence();
	~Licence();

	void setUpMessage(sf::Font&);
	void render(sf::RenderWindow& m_Window);
	void update(sf::Time time);

protected:
	//font used by whole game
	sf::Font m_font;
	//licence text
	sf::Text m_message;
	//counter for pause time
	sf::Time m_pauseTime;

};



#endif	