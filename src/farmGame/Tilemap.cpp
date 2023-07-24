#include "farmGame/Tilemap.h"
#include "Tilemap.h"
#include "shared/pch.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <SFML/Graphics.hpp>

void Tilemap::setTextureCoords(sf::Vertex* quad, int tileIndex)
{
        int tu = tileIndex % (tilesetTexture.getSize().x / tilesize);
        int tv = tileIndex / (tilesetTexture.getSize().x / tilesize);

        // Define the 4 texture coordinates
        quad[0].texCoords = sf::Vector2f(tu * tilesize, tv * tilesize);
        quad[1].texCoords = sf::Vector2f((tu + 1) * tilesize, tv * tilesize);
        quad[2].texCoords = sf::Vector2f((tu + 1) * tilesize, (tv + 1) * tilesize);
        quad[3].texCoords = sf::Vector2f(tu * tilesize, (tv + 1) * tilesize);
}

void Tilemap::highlightTile(float x, float y, sf::Transform transform)
{
    bool isCollisionDetected = false;

    // Populate the vertex array with one quad per tile
    for (unsigned int i = 0; i < mapWidth; i++) {
        for (unsigned int j = 0; j < mapHeight; j++) {
            // Get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices[(i + j * mapWidth) * 4];
            /*
             * Now we have a quad that is indexed looks as follows:
             *  0 -------- 1
             *   |        |
             *   |        |
             *   |        |
             *  3 -------- 2
             * We perform a collision detection. If the cursor position is within
             * boundaries, then we draw a red square there.
             */

            // Collision check
            if (x > quad[0].position.x && x < quad[1].position.x &&
                y > quad[0].position.y && y < quad[2].position.y) {
                    
                    // When we position the tilemap, we also must consider the
                    // camera's transformation matrix.
                    highlightShape.setPosition({
                        quad[0].position.x,
                        quad[0].position.y
                    });
                    
                    // If the player has already clicked on this tile, do not 
                    // show the highlight shape
                    if (highlightedClicked && highlightQuad == quad) {
                        break;
                    } else {
                        isCollisionDetected = true;
                        highlightQuad = quad;
                        highlightedClicked = false;
                        break;
                    }
                    
            }
        }

        if (isCollisionDetected) {
            break;
        }
    }

    // If collision wasn't detected, then we move the shape out of screen
    if (!isCollisionDetected) {
        highlightShape.setPosition({ -1000.f, -1000.f });
    }
}

Tilemap::Tilemap()
{
    enableCursorHighlight = false;
    tilesize = 0;
    mapWidth = 0.f;
    mapHeight = 0.f;
    highlightQuad = nullptr;
    highlightedClicked = false;
}

bool Tilemap::load(const std::string& tileset, std::string mapFile)
{
    nlohmann::json jsonData;
    std::ifstream infile(tileset);
    std::string tilesetPath;
    std::vector<int> mapTiles;

    //#############
    // Load the tileset JSON configuration
    //#############
    if (infile) {
        infile >> jsonData;
        infile.close();
    } else {
        return false;
    }

    //#############
    // Load tileset
    //#############
    if (jsonData.contains("file") && jsonData["file"].is_string()) {
        tilesetPath = jsonData["file"].get<std::string>();
    } else {
        std::cerr << "Failed to find key \'file\'" << std::endl;
        return false;
    }
    if (!tilesetTexture.loadFromFile(tilesetPath)) {
        return false;
    }

    //#############
    // Get all the tiles. We load this from a file that represents our map.
    // Compute map height and width.
    //#############
    infile.open(mapFile);
    if (!infile) {
        std::cerr << "Failed to load \'" << mapFile << "\'" << std::endl;
        return false;
    } else {
        std::string lineRead;

        // Fetch all the integers representing each tile type and cache them
        while (getline(infile, lineRead)) {
            for (auto num : lineRead) {

                // The ASCII character '0' starts at 48
                mapTiles.push_back(num - 48);
            }
            mapHeight++;
            mapWidth = lineRead.size();
        }


        infile.close();
    }

    // Get tilesize
    if (jsonData.contains("tile_size") && jsonData["tile_size"].is_number_integer()) {
        tilesize = jsonData["tile_size"].get<int>();
    } else {
        std::cerr << "Failed to find key \'tile_size\'" << std::endl;
        return false;
    }
    // Resize the vertex array to fit the level size
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(mapWidth * mapHeight * 4);

    // Populate the vertex array with one quad per tile
    for (unsigned int i = 0; i < mapWidth; i++) {
        for (unsigned int j = 0; j < mapHeight; j++) {
            // Get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices[(i + j * mapWidth) * 4];

            // Define the tile's 4 corners
            quad[0].position = sf::Vector2f(i * tilesize, j * tilesize);
            quad[1].position = sf::Vector2f((i + 1) * tilesize, j * tilesize);
            quad[2].position = sf::Vector2f((i + 1) * tilesize, (j + 1) * tilesize);
            quad[3].position = sf::Vector2f(i * tilesize, (j + 1) * tilesize);

            // Define texture coodinates
            int tileIndex = mapTiles[i + j * mapWidth]; // Tile from tileset
            setTextureCoords(quad, tileIndex);
        }
    }

    // Set highlight tile based on the tileset's properties and tile sizes
    highlightShape.setFillColor(sf::Color(255.f, 0.f, 0.f, 200.f));
    highlightShape.setSize({ 1.f, 1.f });
    highlightShape.setOutlineColor(sf::Color(255.f, 0.f, 0.f, 255.f));
    highlightShape.setScale({ (float)tilesize, (float)tilesize });
    highlightShape.setPosition({ -1000.f, -1000.f });

    return true;
}

void Tilemap::update()
{
}

void Tilemap::changeHighlightedTile(int tileIndex)
{
    if (highlightQuad && enableCursorHighlight) {
        // Find its position in the tileset texture
        setTextureCoords(highlightQuad, tileIndex);

        // Move the highlight shape somewhere else
        highlightShape.setPosition({ -1000.f, -1000.f });

        highlightedClicked = true;
    }
}

void Tilemap::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    // Apply the transformations
    states.transform *= getTransform();
    
    // Apply the tileset texture
    states.texture = &tilesetTexture;

    // Draw the vertex array
    target.draw(vertices, states);

    // Draw highlight tile if it's enabled
    if (enableCursorHighlight) {
        target.draw(highlightShape);
    }
}