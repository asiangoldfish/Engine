#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#include "core/include/Engine.h"
#include "core/include/GameTime.h"
#include "physics/include/Emitter.h"
#include "physics/include/Particle.h"

void closeGame(std::vector<void*> ptr);

int main()
{
    std::vector<void*> ptr;

    // Create window
    Engine *engine = new Engine(sf::VideoMode(800, 800), "Aim Game", 60);
    sf::RenderWindow *window = engine->getWindow();

    // Mouse
    sf::Vector2i mousePos;

    // Particle system
    Emitter emitter;
    emitter.setMaxCount(10);
    emitter.setEmitterVisibility(true);

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
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
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

        window->clear();

        engine->draw();

        emitter.setPosition(sf::Vector2f{ (float)mousePos.x, (float)mousePos.y });

        for (int i = 0; i < 10; i++)
        {
            Particle p;
            emitter.addParticle(p);
        }
        emitter.draw(window);

        window->display();

        Logger::log(GameTime::getDeltaTime());
        GameTime::updateTime();
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
