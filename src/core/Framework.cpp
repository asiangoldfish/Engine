#include "Framework.h"

#include "GameTime.h"


Framework::Framework()
{
	_onInit();

	// Set member variable default values
}

/**
 * @brief Destructor
 * Deallocates and releases memory
 */
Framework::~Framework()
{
}

void Framework::_onInit()
{
	// Setup window properties
	window.create(sf::VideoMode(800, 800), "Game");
	setFps(30);

	// Logging
	enableLogging = false;
}

void Framework::onGameBegin()
{
	// Time
	gameTime.resetTime();
}

void Framework::closeEngine()
{
}

void Framework::stopGameLoop()
{
	// Invoke SFML's close function
	window.close();
}

/**
 * @brief Draw things to screen.
 *
 * This method should be called every frame to display images
 * to the screen
 */
void Framework::draw()
{
}

void Framework::clearScreen()
{
	window.clear();
}

void Framework::update()
{
	mousePos = sf::Mouse::getPosition(window);
	gameTime.updateTime();
	window.display();
}

sf::RenderWindow& Framework::getWindow()
{
	return window;
}

void Framework::setTitle(std::string title)
{
	windowTitle = title;
	window.setTitle(title);
}

void Framework::setVideoMode(sf::VideoMode mode)
{
	window.create(mode, windowTitle);
}

void Framework::setFps(int fps)
{
	window.setFramerateLimit(fps);
}
