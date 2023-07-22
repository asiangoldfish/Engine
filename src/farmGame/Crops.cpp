
#include "farmGame/Crops.h"
#include "shared/pch.h"

Crops::Crops()
{
    shape = new BasicShape();
}

Crops::~Crops()
{
    if (shape) {
        delete shape;
    }
}

void Crops::draw(sf::RenderTarget* target)
{
    shape->draw(target);
}
