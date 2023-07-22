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
    // std::cout << argv[0] << std::endl; 

    // Instantiate the engine framework
    Framework framework;

    Emitter* emitter = new Emitter();
    emitter->setEmitterVisibility(false);
    emitter->setInitialVelocity(10.f);
    emitter->setMaxCount(100);
    emitter->setMaxLifeTime(1.f);
    emitter->setLifeVariance(0.2f);

    Tilemap* tilemap = new Tilemap("assets/textures/tilesets/tileset_grass.png", "assets/maps/map.dta", 1.f);

    //return 0;

    // Game loop
    while (framework.isWindowOpen()) {
        // Handle events
        while (framework.pollEvent()) {
            switch (framework.getEvent().type) {
            case sf::Event::Closed:
                framework.stopGameLoop();
                break;

            case sf::Event::KeyPressed:
                // Quit game
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    framework.stopGameLoop();
                break;
            case sf::Event::MouseWheelScrolled:
                tilemap->setTileScale(tilemap->getTileScale() + framework.getEvent().mouseWheelScroll.delta * 3);
            }
        }

        framework.clearScreen();

        // float mouseX, mouseY;
        // mouseX = framework.getMousePos().x;
        // mouseY = framework.getMousePos().y;
        tilemap->draw(framework.getWindow());
        
        framework.update();
    }

    framework.closeEngine();

    delete emitter;
    delete tilemap;

    return 0;
}
