#include <SFML/Graphics.hpp>

#include "shared/pch.h"

#include "core/Framework.h"

int main()
{
    // Instantiate the engine framework
    Framework framework;

    // Game loop
    while (framework.isWindowOpen())
    {
        // Handle events
        while (framework.pollEvent())
        {
            switch (framework.getEvent().type)
            {
                case sf::Event::Closed:
                    framework.stopGameLoop();
                    break;

                case sf::Event::KeyPressed:
                    // Quit game
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                        framework.stopGameLoop();
            }
        }

        framework.clearScreen();

        // All draw calls go here

        framework.update();
    }

    framework.closeEngine();
    return 0;
}