#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>
#include "shared/pch.h"
#include "farmGame/Tileset.h"
#include "farmGame/Tile.h"

class Tilemap
{
private:
    std::vector<Tile*> tiles;
    std::vector<sf::RectangleShape> rectShapes;
    std::vector<Tileset*> tilesets;
    std::vector<Sprites> sprites;

    // Tile size
    float tilesize;

    sf::Texture grass;
    sf::Texture rock;
    sf::Texture water;

    Logger *logger;

public:
    Tilemap();
    virtual ~Tilemap();

    void draw(sf::RenderTarget* target);

public: // Tilesets
    void addTileset(std::string filepath);
    void loadMap();
};

#endif
