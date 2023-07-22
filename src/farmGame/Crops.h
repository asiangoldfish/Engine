
#ifndef CROPS_H
#define CROPS_H

#include <SFML/Graphics.hpp>

#include "core/BasicShape.h"
#include "core/Renderable.h"

class Crops : public Renderable {
private:
    sf::Vector2f position;

    BasicShape* shape;

public:
    Crops();
    virtual ~Crops();

    virtual void draw(sf::RenderTarget* target) override;
};

#endif
