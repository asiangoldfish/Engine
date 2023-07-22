#include <SFML/Graphics.hpp>

#include "farmGame/Tileset.h"
#include "shared/Logger.h"
#include "../vendor/nlohmann/json.hpp"

#include "shared/pch.h"
#include <fstream>
#include <typeinfo>
#include <sstream>
#include "Tileset.h"

using json = nlohmann::json;

Tileset::Tileset()
{
    texture = new sf::Texture;
    logger = new Logger();
    tilesize = 0;
}

Tileset::Tileset(std::string path) : Tileset()
{
    Tileset::configureTileset(path);
}

Tileset::~Tileset()
{
    if (texture) {
        delete texture;
    }

    if (logger) {
        delete logger;
    }

    for (auto rect : subrects)
    {
        if (rect)
        {
            delete rect;
        }
    }

    subrects.clear();

    rectShapes.clear();
}

int Tileset::configureTileset(std::string path)
{
    std::string prefix = "assets/textures/tilesets/";

    std::ifstream f(prefix + path);

    if (!f)
    {
        std::cerr << "Cannot load tileset from file at \'" << prefix + path << "\'" << std::endl;
    }

    json data = json::parse(f);
    f.close();

    std::string filename = "assets/textures/tilesets/" + std::string(data["file"]);

    if (!texture->loadFromFile(filename)) {
        logger->debug("Cannot load texture from \'" + filename + "\'");
        return -1;
    } else {
        logger->debug("Successfully loaded tileset!");
    }

    if (data.contains("tile_size") && data["tile_size"].is_number_integer()) {
        tilesize = data["tile_size"];
    } else {
        std::cerr << "Invalid value for 'tile_size' in the JSON file." << std::endl;
        return 1;
    }

    /*
     * Each tile in the config is formatted as a string with 2 values: "3-1",
     * where 3 is x-pos and 1 is y-pos. '-' is the delimiter.
     */
    std::map<std::string, std::string> datamap = data["tiles"];
    
    for (auto &pair : datamap)
    {
        std::vector<int> pos;
        std::string tileStr = pair.second;
        
        // Split string
        std::stringstream ss(tileStr);
        std::string token;
        while (getline(ss, token, '-'))
        {
            pos.push_back(std::stoi(token));
        }

        // Subrect
        sf::IntRect *subrect = new sf::IntRect();
        subrect->height = tilesize;
        subrect->width = tilesize;
        subrect->left = pos[0];
        subrect->top = pos[1];
        subrects.push_back(subrect);

        // Sprite
        
    }

    return 0;
}

sf::RectangleShape Tileset::getRectangleShape(std::string name)
{
    auto pos = rectShapes.find(name);
    if (pos == rectShapes.end())
    {
        // Couldn't find the sprite
        logger->debug("Can't find the rectangle shape by name: \'" + name + "\'.");

        return sf::RectangleShape();
    }

    return pos->second;
}

int Tileset::getTilesize()
{
    return tilesize;
}
