
#include "farmGame/Tile.h"
#include "shared/Math.h"
#include "shared/pch.h"
#include <iostream>

Tile::Tile(int _id, float _size)
{
    id = _id;
    landtype = GRASS;

    shape = new BasicShape();

    shape->setSize(_size);

    shape->setColor(rng(155, 255), rng(155, 255), rng(155, 255));
}

Tile::~Tile()
{
    if (shape) {
        delete shape;
    }
}

void Tile::setLandtype(int id)
{
    setLandtype(static_cast<Landtype>(id));
}

void Tile::setLandtype(Landtype _landtype)
{
    landtype = _landtype;

    switch (landtype) {
    case GRASS:
        shape->setColor(0, 255, 0);
        break;

    case WATER:
        shape->setColor(0, 0, 255);
        break;

    case ROCK:
        shape->setColor(125, 125, 125);
        break;

    default:
        shape->setColor(0, 0, 0);
        break;
    }
}

void Tile::setTexture(std::string filepath)
{
    textureType = IMAGE;

    // Load from file
    if (!texture.loadFromFile(filepath)) {
        std::cout << "IMAGE::ERROR: Cannot load \'" << filepath << "\'" << std::endl;

        textureType = SOLID;
        std::cout << "Solid\n";
    } else {
        sprite.setTexture(texture);
    }
}

void Tile::draw(sf::RenderTarget* target)
{

    if (textureType == SOLID) {
        shape->draw(target);
    } else {
        target->draw(sprite);
    }
}
