#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <SFML/Graphics.hpp>

class Renderable
{
public:
    virtual void draw(sf::RenderTarget *target) = 0;
};

#endif