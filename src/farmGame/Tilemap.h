#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>

class Tilemap : public sf::Drawable, public sf::Transformable
{
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::VertexArray vertices;

    // Tile properties
    sf::Texture tilesetTexture;
    sf::RectangleShape highlightShape;
    int tilesize;
    sf::Vertex* highlightQuad;  // Index of currently highlighted tile
    bool highlightedClicked;    // Helps removing the highlight shape after clicking
    
    // Map dimensions
    float mapWidth;
    float mapHeight;

private:
    void setTextureCoords(sf::Vertex *quad, int tileIndex);


// Public class members
public:
    bool enableCursorHighlight;

public:
    /**
     * @brief Highlight a tile
     * 
     * @param x Position x to check collision against
     * @param y Position y to check collision against
     */
    void highlightTile(float x, float y, sf::Transform transform);

    Tilemap();
    bool load(const std::string &tileset, std::string mapFile);
    void update();

    /**
     * @brief Change the highlighted tile with another from the same tileset
     * @param tileNumber New tile index to replace with
     */
    void changeHighlightedTile(int tileIndex);

    int getTilesize() { return tilesize; }
};

#endif
