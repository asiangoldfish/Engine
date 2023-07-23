#include "farmGame/Tilemap.h"
#include "Tilemap.h"
#include "shared/pch.h"
#include "nlohmann/json.hpp"
#include <fstream>

bool Tilemap::load(const std::string& tileset, std::string mapFile)
{
    nlohmann::json jsonData;
    std::ifstream infile(tileset);
    std::string tilesetPath;
    int tilesize;
    std::vector<int> mapTiles;
    int width, height = 0;      // Map size

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
            height++;
            width = lineRead.size();
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
    vertices.resize(width * height * 4);

    // Populate the vertex array with one quad per tile
    for (unsigned int i = 0; i < width; i++) {
        for (unsigned int j = 0; j < height; j++) {
            // Get the current tile number
            int tileNumber = mapTiles[i + j * width];

            // Find its position in the tileset texture
            int tu = tileNumber & (tilesetTexture.getSize().x / tilesize);
            int tv = tileNumber / (tilesetTexture.getSize().x / tilesize);

            // Get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices[(i + j * width) * 4];

            // Define the tile's 4 corners
            quad[0].position = sf::Vector2f(i * tilesize, j * tilesize);
            quad[1].position = sf::Vector2f((i + 1) * tilesize, j * tilesize);
            quad[2].position = sf::Vector2f((i + 1) * tilesize, (j + 1) * tilesize);
            quad[3].position = sf::Vector2f(i * tilesize, (j + 1) * tilesize);

            // Define the 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tilesize, tv * tilesize);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tilesize, tv * tilesize);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tilesize, (tv + 1) * tilesize);
            quad[3].texCoords = sf::Vector2f(tu * tilesize, (tv + 1) * tilesize);
        }
    }

    return true;
}

void Tilemap::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    // Apply the transformations
    states.transform *= getTransform();
    
    // Apply the tileset texture
    states.texture = &tilesetTexture;

    // Draw the vertex array
    target.draw(vertices, states);
}