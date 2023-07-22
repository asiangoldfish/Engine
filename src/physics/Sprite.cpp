#include <SFML/Graphics.hpp>
#include "physics/Sprite.h"
#include "core/BasicShape.h"

Sprite::Sprite()
{
    shape = new BasicShape(20.f, sf::Color::Red);
}

Sprite::~Sprite()
{
    delete shape;
}

BasicShape *Sprite::getShape()
{
    return shape;
}