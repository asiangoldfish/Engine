#ifndef FRAMEWORK_H
#define FRAMEWORK_H
// SFML
#include <SFML/Graphics.hpp>

#include "shared/pch.h"

// Custom
#include "shared/Math.h"
#include "shared/Logger.h"
#include "GameTime.h"

class GameObject;
class Renderable;

class Framework
{
private:
	// Window related data
	sf::RenderWindow window;	///< Main game client window
	std::string windowTitle;	///< Client window title

	// Mouse
	sf::Vector2i mousePos;		///< Mouse position relative to client window

	// Events
	sf::Event event;			///< Current SFML event ongoing

	// Logging
	bool enableLogging;			///< If true, logs are output to file

public:
	// Time
	GameTime gameTime;			///< Global time

// Internal engine events
private:
	/**
	 * @brief Initialize necessary framework components
	 * 
	 */
	void _onInit();

	/**
	 * @brief Event when game has begun
	 * 
	 * This event is fired off after all initial setup has completed.
	 */
	void onGameBegin();

// Initializations
public:
	/**
	 * @brief Default constructor
	 * 
	 * When using this constructor, the window must be created
	 * manually.
	*/
	Framework();

	/**
	* @brief Destructor
	* 
	* Deallocates and releases memory
	*/
	~Framework();

	void closeEngine();
	void stopGameLoop();

	/**
	 * @brief Checks whether the client window is running.
	 * 
	 * The application is still running even if the window is closed.
	 * This lets us cleanup resources and do other tasks.
	 * 
	 * @return true If the window is open, otherwise false.
	 */
	bool isWindowOpen() { return window.isOpen(); }

public:
	/**
	 * @brief Draw things to screen.
	 * 
	 * This method should be called every frame to display images
	 * to the screen
	*/
	void draw(sf::RectangleShape shape);
	
	void clearScreen();

	/**
	 * @brief To be called every frame.
	 * Updates necessary internal engine components on per frame basis
	*/
	void update();

// Events
public:
	/**
	 * @brief Manage event queue.
	 * 
	 * Place event in a queue. As there may be several events in the
	 * queue, the functions output signifies whether there still are
	 * events in the queue.
	 * 
	 * @return true if there are remaining events to handle, otherwise
	 * 		   false.
	 */
	bool pollEvent() { return window.pollEvent(event); }

public:
	sf::RenderWindow& getWindow();
	
	// Window properties
	void setTitle(std::string title);
	void setVideoMode(sf::VideoMode mode);
	void setFps(int fps);

	sf::Event getEvent() { return event; }

	GameTime* getGameTime() { return &gameTime;  }
	int getTimeElapsed() { return gameTime.getElapsedTime(); }
	sf::Vector2i getMousePos() { return mousePos; }

// Rendering
public:
	void draw(Renderable *renderable);
};

#endif