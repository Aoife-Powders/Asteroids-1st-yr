//names : Aaron O'Dea & Aoife Powders
//date started  : 17  febuary 2017 
//time taken : 6h
//knowbugs :: no known bugs 
#include<iostream>

#include <SFML/Graphics.hpp>
#include "SFML/OpenGL.hpp" 
#include <stdio.h>
#include <tchar.h>

#include "Licence.h"
#include"SplashScreen.h"
#include "MainMenu.h"
#include "HelpScreen.h"
#include "backstory.h"
#include "UpgradeMenu.h"
#include "LevelScreen.h"
#include "GameScreen.h"
#include "PauseScreen.h"



//prees esc to close thegame from the menu 
// from the menu press h to go help
// u to go to the upgrades 
// L to go levelselect  
//to get back from each of these menus to the main menu press backspace
//in level select press B to go to the backstory and then space to go to
//the game.In the game press P to pause and again to unpause  in pause press 
//backspace to go to the main menu





//enum used to determine gamestate

enum class
	GameState
{
	Licence,
	Splash,
	Menu,
	upgrade,
	Help,
	Game,
	levelSelect,
	story,
	pause
};

class Game
{
public:
	Game();
	void run();

	//	static properties accessed by all classes
	/// width of the screen in pixels (stored as float? for parameter conversion)
	static float screenWidth;
	/// screen width in pixels
	static float screenHeight;
	/// current game state
	static GameState currentState;

protected:
	void	processEvents();
	void	update(sf::Time time);
	void	render();
	void	loadContent();

	// variable
	sf::Font m_space_font;
	// variable
	sf::RenderWindow m_Window;

	// instance used to run splash screen
	SplashScreen m_splashScreen;
	// instance used to run licence screen
	Licence	m_licenceScreen;
	// instance used to run menu screen
	MainMenu m_menuScreen;
	// instance used to run help screen
	HelpScreen m_helpscreen;
	// instance used to run background screen
	backstory m_backStory;
	// instance used to run upgrade screen
	UpgradeMenu m_upgradescreen;
	//instance used to run level select screen
	LevelScreen m_levelScreen;
	//instance used to run game screen
	GameScreen m_gameScreen;
	//instance used to run pause screen
	PauseScreen m_pauseScreen;
};

