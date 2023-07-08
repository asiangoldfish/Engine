#include <SFML/Graphics.hpp>

#include "core/include/Engine.h"

int main()
{
    // Create window
    Engine engine;

    // Game loop
    while (engine.isOpen())
    {

        // Handle events
        while (engine.pollEvent())
        {
            switch (engine.getEvent().type)
            {
                case sf::Event::Closed:
                    engine.stopGameLoop();
                    break;

                case sf::Event::KeyPressed:
                    // Quit game
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                        engine.stopGameLoop();
            }
        }

        engine.clearScreen();

        engine.update();
    }

    engine.closeEngine();
    return 0;
}