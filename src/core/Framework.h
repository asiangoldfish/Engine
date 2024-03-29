#ifndef FRAMEWORK_H
#define FRAMEWORK_H
// SFML
#include <SFML/Graphics.hpp>

#include "shared/pch.h"

// Custom
#include "shared/Math.h"
#include "shared/Logger.h"
#include "GameTime.h"


class Engine
{
private:
	// Window related data
	sf::RenderWindow window;	///< Main game client window
	std::string windowTitle;	///< Client window title

	// Mouse
	sf::Vector2i mousePos;		///< Mouse position relative to client window

	// Events
	sf::Event event;

public:
	// Time
	GameTime gameTime;

// Internal engine events
private:
	void _onInit();

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
	* @brief Destructor
	* 
	* Deallocates and releases memory
	*/
	~Engine();

	void closeEngine();
	void stopGameLoop();
	bool isOpen() { return window.isOpen(); }

public:
	/**
	 * @brief Draw things to screen.
	 * 
	 * This method should be called every frame to display images
	 * to the screen
	*/
	void draw();
	
	void clearScreen();

	/**
	 * @brief To be called every frame.
	 * Updates necessary internal engine components on per frame basis
	*/
	void update();

// Events
public:
	bool pollEvent() { return window.pollEvent(event); }

public:
	sf::RenderWindow& getWindow();
	
	// Window properties
	void setTitle(std::string title);
	void setVideoMode(sf::VideoMode mode);
	void setFps(int fps);

	sf::Event getEvent() { return event; }

	GameTime* getGameTime() { return &gameTime;  }
};

#endif