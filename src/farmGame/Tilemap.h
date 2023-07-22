#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>
#include "shared/pch.h"
#include "farmGame/Tileset.h"
#include "farmGame/Tile.h"

class Tilemap
{
private:
    // Contains the tileset
    sf::Texture tilesetTexture;

    // Tile size
    unsigned int tilesize;
    float tileScale;
    unsigned int mapWidth;
    unsigned int mapHeight;

    std::vector<std::vector<char>> levelData;
    sf::VertexArray vertexArray;

    Logger *logger;

public:
    Tilemap(std::string tilesetPath, std::string mapPath, float _tileScale);
    virtual ~Tilemap();
    void draw(sf::RenderTarget &target);

    float getTileScale() { return tileScale; }
    void setTileScale(float newScale);

private:
    // Helper function to build vertex array
    void buildVertexArray();
};

#endif
