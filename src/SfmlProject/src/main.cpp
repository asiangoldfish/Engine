#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include "core/include/Engine.h"
#include "shared/include/Debug.h"

void closeGame(std::vector<void*> ptr);

int main()
{
    std::vector<void*> ptr;

    // Create window
    Engine *engine = new Engine(sf::VideoMode(800, 800), "Aim Game", 60);
    sf::RenderWindow *window = engine->getWindow();

    // Mouse
    sf::Vector2i mousePos;

    // Debugger
    Debug debug = Debug();

    ptr.push_back(engine);
    ptr.push_back(window);

    // Game loop
    while (window->isOpen())
    {
        mousePos = sf::Mouse::getPosition(*window);

        // Handle events
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window->close();
                    break;

                //case sf::Event::MouseButtonPressed:
                //    break;

                case sf::Event::KeyPressed:
                    // Quit game
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                        window->close();

                    // Jump
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                        engine->getPerson()->jump();                    
                    break;
            }
        }

        float speed = 5;

        // Move right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            engine->getPerson()->move(-speed, 0);
        }

        // Move left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            engine->getPerson()->move(speed, 0);

        engine->draw();

    }

    // Deallocate memory
    closeGame(ptr);

    return 0;
}

void closeGame(std::vector<void*> ptr)
{
    for (auto p : ptr)
    {
        delete p;
        p = nullptr;
    }
}
