#ifndef TILESET_H
#define TILESET_H

#include "shared/pch.h"
#include <SFML/Graphics.hpp>
#include "shared/Logger.h"

/**
 * @brief Class that handles a single tileset.
 * Using this tileset, several small tiles can be created and be assigned to
 * sprites to load them as textures.
 * 
 * It's important that the tilesets are loaded until the game is over or the
 * level is unloaded to ensure that no sprites use any deallocated textures.
 * 
 * https://stackoverflow.com/a/10341211
 */
class Tileset 
{
private:
    sf::Texture *texture;
    Logger *logger;
    int tilesize;

    std::vector<sf::IntRect*> subrects;
    std::map<std::string, sf::RectangleShape> rectShapes;

public:
    Tileset();
    Tileset(std::string path);
    virtual ~Tileset();

    int configureTileset(std::string path);
    int getTilesize();
};

#endif