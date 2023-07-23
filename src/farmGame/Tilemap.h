#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>

class Tilemap : public sf::Drawable, public sf::Transformable
{
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::VertexArray vertices;
    sf::Texture tilesetTexture;

public:
    bool load(const std::string &tileset, std::string mapFile);
};

#endif
