
#include "farmGame/Tilemap.h"

#include "shared/pch.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "farmGame/Tileset.h"
#include "shared/Math.h"
#include "Tilemap.h"

Tilemap::Tilemap(std::string tilesetPath, std::string mapPath, float _tileScale) : tileScale(_tileScale)
{
    logger = new Logger();
    tilesize = 16;
    mapWidth = mapHeight = 0;

    // Load tilemap
    if (!tilesetTexture.loadFromFile(tilesetPath))
    {
        // Failed to load texture
        std::cerr 
            << "TILESET::ERROR: Failed to load texture from \'" 
            << tilesetPath
            << "\'"
            << std::endl;
    }
    else
    {
        // Set bilinear texture filtering
        tilesetTexture.setSmooth(true);
    }

    // ---------------------------
    // Assemble the level data
    // ---------------------------
    // Load the map file
    std::ifstream mapfile;
    mapfile.open(mapPath);
    if (!mapfile) {
        std::cout << "Unable to load map from \'" << mapPath << "\'" << std::endl;
    }

    std::string line;
    while (std::getline(mapfile, line))
    {
        // Skip empty lines
        if (line.empty() || ( line[0] == '/' && line[1] == '/' ))
        {
            continue;
        }
        else 
        {
            levelData.push_back(std::vector<char>());
        }

        for (char i : line)
        {
            if (i == ' ' || i == '\t')
            {
                continue;
            }
            else
            {
                levelData[levelData.size() - 1].push_back(i);
            }
        }
        mapHeight++;
        mapWidth = line.size();
    }

    buildVertexArray();
}

Tilemap::~Tilemap()
{
}

void Tilemap::draw(sf::RenderTarget& target)
{
    sf::RenderStates states;
    states.texture = &tilesetTexture;
    target.draw(vertexArray, states);
}

void Tilemap::buildVertexArray()
{
    vertexArray.setPrimitiveType(sf::Quads);
    vertexArray.resize(mapWidth * mapHeight * 4); // 4 vertices per tile (quad)

    for (unsigned int y = 0; y < mapHeight; ++y) {
        for (unsigned int x = 0; x < mapWidth; ++x) {

            // Get the tile index from levelData
            int tileIndex = levelData[y][x];

            unsigned int scaledTileSize = static_cast<unsigned int>(tilesize * tileScale);

            // Calculate the position of the current tile in the vertex array
            int vertexIndex = (x + y * mapWidth) * 4;
            float xPos = static_cast<float>(x * tilesize);
            float yPos = static_cast<float>(y * tilesize);

            // Define the 4 vertices of the current tile
            vertexArray[vertexIndex + 0].position = sf::Vector2f(xPos, yPos);
            vertexArray[vertexIndex + 1].position = sf::Vector2f(xPos + scaledTileSize, yPos);
            vertexArray[vertexIndex + 2].position = sf::Vector2f(xPos + scaledTileSize, yPos + scaledTileSize);
            vertexArray[vertexIndex + 3].position = sf::Vector2f(xPos, yPos + scaledTileSize);

            // Define the texture coordinates for the vertices
            int textureX = tileIndex % (tilesetTexture.getSize().x / tilesize) * tilesize;
            int textureY = tileIndex / (tilesetTexture.getSize().x / tilesize) * tilesize;
            vertexArray[vertexIndex + 0].texCoords = sf::Vector2f(textureX, textureY);
            vertexArray[vertexIndex + 1].texCoords = sf::Vector2f(textureX + tilesize, textureY);
            vertexArray[vertexIndex + 2].texCoords = sf::Vector2f(textureX + tilesize, textureY + tilesize);
            vertexArray[vertexIndex + 3].texCoords = sf::Vector2f(textureX, textureY + tilesize);
        }
    }
}

void Tilemap::setTileScale(float newScale)
{
    if (newScale > 0) {
        tileScale = newScale;
        buildVertexArray();
    }
}
