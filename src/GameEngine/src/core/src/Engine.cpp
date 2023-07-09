#include "shared/include/Logger.h"
#include "core/include/Engine.h"

#include "core/include/GameTime.h"


Engine::Engine()
{
	_onInit();

	// Set member variable default values
}

/**
 * @brief Destructor
 * Deallocates and releases memory
 */
Engine::~Engine()
{
}

void Engine::_onInit()
{
	Logger::debug("Starting time...");
	
	// Setup window properties
	window.create(sf::VideoMode(200, 200), "Game");
	setFps(30);
}

void Engine::closeEngine()
{
}

void Engine::stopGameLoop()
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
void Engine::draw()
{
}

void Engine::clearScreen()
{
	window.clear();
}

void Engine::update()
{
	mousePos = sf::Mouse::getPosition(window);
	gameTime.updateTime();
	window.display();
}

sf::RenderWindow& Engine::getWindow()
{
	return window;
}

void Engine::setTitle(std::string title)
{
	windowTitle = title;
	window.setTitle(title);
}

void Engine::setVideoMode(sf::VideoMode mode)
{
	window.create(mode, windowTitle);
}

void Engine::setFps(int fps)
{
	window.setFramerateLimit(fps);
}
