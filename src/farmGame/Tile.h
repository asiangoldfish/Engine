#ifndef TILE_H
#define TILE_H

#include "core/BasicShape.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

enum Landtype {
    GRASS,
    ROCK,
    WATER
};

/**
 * Possible textures rendered as tile
 */
enum TextureType {
    SOLID,
    IMAGE
};

/**
 * @brief Tile for a slot in a tilemap
 */
class Tile {
private:
    int id;
    Landtype landtype;

    // We internally change the shape's color based on the land type
    BasicShape* shape;
    sf::Texture texture;
    TextureType textureType;
    sf::Sprite sprite;

public:
    Tile(int _id, float _size);
    virtual ~Tile();

    void setLandtype(int id);
    void setLandtype(Landtype _landtype);
    void setPosition(float x, float y) { shape->setPosition(x, y); }

    void draw(sf::RenderTarget* target);
    void setTexture(std::string filepath);
    sf::Sprite getSprite() { return sprite; }
};

#endif
