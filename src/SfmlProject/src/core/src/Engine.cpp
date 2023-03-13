#include <core/include/Engine.h>

Engine::Engine()
{
	window = new sf::RenderWindow();
	debug = Logger();
}

/**
 * @brief Creates window
 * @param videoMode Screen size
 * @param title Window class name and displayed window title
 */
Engine::Engine(sf::VideoMode videoMode, std::string title, int fps)
{
	// Initialize main game window
	window = new sf::RenderWindow();
	window->create(videoMode, title);
	window->setFramerateLimit(fps);

	debug = Logger();

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

	// Test physics
	p.setPosition(200, window->getSize().y/2);

	debug.log("Game initialized!");
}

Person *Engine::getPerson() { return &p; }

/**
 * @brief Destructor
 *
 * Deallocates and releases memory
 */
Engine::~Engine()
{
	// Window
	delete window;
	window = nullptr;
}

/**
 * @brief Draw things to screen.
 *
 * This method should be called every frame to display images
 * to the screen
 */
void Engine::draw()
{
	window->clear();

	p.draw(window);

	window->display();
}

sf::RenderWindow *Engine::getWindow()
{
	return window;
}