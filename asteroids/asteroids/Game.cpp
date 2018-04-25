#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 


#include<SFML\Graphics.hpp>
#include<iostream>

#include "Game.h"
#include "SplashScreen.h"
#include "Licence.h"
#include "HelpScreen.h"
#include "MainMenu.h"
#include "backstory.h"
#include "UpgradeMenu.h"
#include "LevelScreen.h"
#include "GameScreen.h"
#include "PauseScreen.h"

int main()
	{
	Game game;
	game.run();
	}
 
 float Game::screenWidth = 880;
 float  Game::screenHeight = 605;
 GameState Game::currentState = GameState::Licence; 

Game::Game(): m_Window(sf::VideoMode(static_cast<int>(Game::screenWidth), static_cast<int>(Game::screenHeight)), "asteroids", sf::Style::Default)
{		
	loadContent();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_Window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);

		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_Window.close();
		}
		switch (currentState)
		{
		case GameState::Licence:
			break;
		case GameState::Splash:
			m_splashScreen.KeyIsPressed(event);
			break;
		case GameState::Menu:
			break;
		case GameState::Help:
			m_helpscreen.keyIsPressed(event);
			break;
		case GameState::story:
			m_backStory.keyIsPressed(event);
			break;
		case GameState::upgrade:
			m_upgradescreen.keyIsPressed(event);
			break;
		case GameState::levelSelect:
			m_levelScreen.keyIsPressed(event);
			break;
		case GameState::Game:
			m_gameScreen.keyIsPressed(event);
			break;
		case GameState::pause:
			m_pauseScreen.keyIsPressed(event);
			break;
		}


	}
}

void Game::update(sf::Time time)
{
	switch (currentState)
	{
	case GameState::Licence:
		m_licenceScreen.update(time);
		break;
	case GameState::Splash:
		m_splashScreen.update(time);
		break;
	case GameState::Menu:
		m_menuScreen.update(time, m_Window);
		break;
	case GameState::Help:
		m_helpscreen.update(time);
		break;
	case GameState::story:
		m_backStory.update(time);
		break;
	case GameState::upgrade:
		m_upgradescreen.update(time);
		break;
	case GameState::levelSelect:
		m_levelScreen.update(time);
		break;
	case::GameState::Game:
		m_gameScreen.update(time);
		break;
	case::GameState::pause:
		m_pauseScreen.update(time);
		break;

	}
}

void Game::render()
{
	m_Window.clear();
	switch (currentState)
	{
	case GameState::Licence:
		m_licenceScreen.render(m_Window);
		break;
	case GameState::Splash:
		m_splashScreen.render(m_Window);
		break;
	case GameState::Menu:
		m_menuScreen.render(m_Window);
		break;
	case GameState::Help:
		m_helpscreen.render(m_Window);
		break;
	case GameState::story:
		m_backStory.render(m_Window);
		break;
	case GameState::upgrade:
		m_upgradescreen.render(m_Window);
		break;
	case GameState::levelSelect:
		m_levelScreen.render(m_Window);
		break;
	case GameState::Game:
		m_gameScreen.render(m_Window);
		break;
	case::GameState::pause:
		m_pauseScreen.render(m_Window);
		break;
	}
	m_Window.display();
}

void Game::loadContent()
{
	if (!m_space_font.loadFromFile("ASSETS/FONTS/space.otf"))
	{
		std::cout << "error with font :( ";
	}

	m_splashScreen.setUp(m_space_font);
	m_licenceScreen.setUpMessage(m_space_font);
	m_menuScreen.setUp(m_space_font);
	m_helpscreen.setUp(m_space_font);
	m_backStory.setUp(m_space_font);
	m_upgradescreen.setUp(m_space_font);
	m_levelScreen.setUp(m_space_font);
	m_gameScreen.setUp(m_space_font);
	m_pauseScreen.setUp(m_space_font);
}

