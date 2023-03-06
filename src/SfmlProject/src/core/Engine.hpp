#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

// SFML
#include <SFML/Graphics.hpp>

// Custom
#include "shared/math.hpp"
#include "shared/debug.hpp"

class Engine
{
private:
	// Window related data
	sf::RenderWindow* window;

	// Debugger
	Debug debug;

	// Fonts and texts
	sf::Font opensans;
	sf::Text scoreText;

// Initializations
public:
	/**
	 * @brief Default constructor
	 * 
	 * When using this constructor, the window must be created
	 * manually.
	*/
	Engine() 
	{
		window = new sf::RenderWindow();
		debug = Debug();
	}

	/**
	 * @brief Creates window
	 * @param videoMode Screen size
	 * @param title Window class name and displayed window title
	*/
	Engine(sf::VideoMode videoMode, std::string title, int fps)
	{
		// Initialize main game window
		window = new sf::RenderWindow();
		window->create(videoMode, title);
		window->setFramerateLimit(fps);

		debug = Debug();

		// Initialize fonts and texts
		if (!opensans.loadFromFile("data/fonts/OpenSans-Regular.ttf"))
		{
			std::cerr << "ERROR: Could not load OpenSans font from file\n";
		}

		scoreText.setFont(opensans);
		scoreText.setCharacterSize(20);
		scoreText.setString("NONE");
		int width = scoreText.getGlobalBounds().width;
		scoreText.setPosition(window->getSize().x / 2.f - width * 2, 20.f);

		debug.log("Game initialized!");
	}

	/**
	* @brief Destructor
	* 
	* Deallocates and releases memory
	*/
	~Engine()
	{
		// Window
		delete window;
		window = nullptr;
	}

// Rendering
public:
	/**
	 * @brief Draw things to screen.
	 * 
	 * This method should be called every frame to display images
	 * to the screen
	*/
	void draw()
	{
		window->clear();
		
		window->display();
	}

// Enemies game logic
public:
	sf::RenderWindow* getWindow()
	{
		return window;
	}
};