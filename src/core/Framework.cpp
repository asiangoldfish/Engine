#include "Framework.h"

#include "core/GameTime.h"
#include "core/GameObject.h"
#include "core/Renderable.h"

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
	if (camera) {
		delete camera;
	}
}

void Framework::_onInit()
{
	// Setup window properties
	window.create(sf::VideoMode(800, 800), "Game");
	setFps(60);

	// Logging
	enableLogging = false;
	camera = new Camera(window);
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
void Framework::draw(sf::RectangleShape shape)
{
	window.draw(shape);
}

void Framework::clearScreen()
{
	window.clear();
}

void Framework::update()
{
	// Set mouse positions
	mousePos = sf::Mouse::getPosition(window);
	mouseWorldPos = window.mapPixelToCoords(mousePos, window.getView());

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

void Framework::draw(Renderable *renderable)
{
	renderable->draw(&window);
}
