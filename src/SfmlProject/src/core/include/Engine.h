#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

// SFML
#include <SFML/Graphics.hpp>

// Custom
#include "shared/include/Math.h"
#include "shared/include/Debug.h"

// Physics test
#include "physics/include/testPerson.h"


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

	Person p;

// Initializations
public:
	/**
	 * @brief Default constructor
	 * 
	 * When using this constructor, the window must be created
	 * manually.
	*/
	Engine();

	/**
	 * @brief Creates window
	 * @param videoMode Screen size
	 * @param title Window class name and displayed window title
	*/
	Engine(sf::VideoMode videoMode, std::string title, int fps);

	Person *getPerson();

	/**
	* @brief Destructor
	* 
	* Deallocates and releases memory
	*/
	~Engine();

// Rendering
public:
	/**
	 * @brief Draw things to screen.
	 * 
	 * This method should be called every frame to display images
	 * to the screen
	*/
	void draw();

// Enemies game logic
public:
	sf::RenderWindow* getWindow();
};