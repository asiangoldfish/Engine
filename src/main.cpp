#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "core/Framework.h"
#include "shared/Math.h"
#include "shared/pch.h"

// Test rendering
#include "physics/Emitter.h"

#include "farmGame/Tilemap.h"

int main()  // int argc, char * argv[])
{
    // Instantiate the engine framework
    Framework *framework = new Framework();

    // Emitter* emitter = new Emitter();
    // emitter->setEmitterVisibility(false);
    // emitter->setInitialVelocity(10.f);
    // emitter->setMaxCount(100);viewfr
    // emitter->setMaxLifeTime(1.f);
    // emitter->setLifeVariance(0.2f);

    Tilemap map;
    if (!map.load("assets/textures/tilesets/tileset_grass.json", "assets/maps/map.dta"))
    {
        return -1;
    }
    std::cout << map.getTilesize() << std::endl;


    map.enableCursorHighlight = true;

    float movementSpeed = 2.f;

    // Game loop
    while (framework->isWindowOpen()) {
        // Handle events
        while (framework->pollEvent()) {
            switch (framework->getEvent().type) {
            case sf::Event::Closed:
                framework->stopGameLoop();
                break;

            case sf::Event::KeyPressed:
                // Quit game
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    framework->stopGameLoop();
                }
                break;
            
            // Mouse wheel
            case sf::Event::MouseWheelMoved:
                // Zoom camera
                framework->zoomCamera(framework->getEvent().mouseWheel.delta * -0.1f);
                break;

            // Mouse clicks
            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
                    map.enableCursorHighlight = !map.enableCursorHighlight;
                } else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                    map.changeHighlightedTile(8);
                }
                break;
            }
        }

        // Handle camera properties by user input
        {
            // Move camera
            float moveRight = 0, moveUp = 0;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                moveUp -= movementSpeed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                moveUp += movementSpeed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                moveRight += movementSpeed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                moveRight -= movementSpeed;
            }

            framework->moveCamera(moveRight, moveUp);
        }

        // Game logic

        float mouseX, mouseY;
        mouseX = framework->getMouseWorldPos().x;
        mouseY = framework->getMouseWorldPos().y;

        map.highlightTile(mouseX, mouseY, framework->getWindow().getView().getTransform());

        // Rendering
        framework->clearScreen();
        framework->getWindow().draw(map);
        
        framework->update();
    }

    framework->closeEngine();
    
    delete framework;

    return 0;
}
