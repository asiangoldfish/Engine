#ifndef BASIC_SHAPE_H
#define BASIC_SHAPE_H

#include <SFML/Graphics.hpp>

/**
 * The shape that a particle may have
 * Although sf::SquareShape may be used, this class is lower level for better
 * performance.
*/
class BasicShape
{
private:
    sf::Vertex vertices[4];     // Shape to render to screen
    sf::Vector2f size;
    sf::Color color;

    // Internal methods
private:
    /**
     * Constructs the particle shape
     * The shape in 0 to 1 Cartesian coordinate space, then multiplied by the shape's size.
     * Code for generating vertex array using vector array taken from:
     * https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
    */
    void constructShape();

public:
    // Default constructor
    BasicShape();
    /**
     * Initialize the particle.
    */
    BasicShape(sf::Vector2f size, sf::Color color);
    BasicShape(float size, sf::Color color);
    void draw(sf::RenderTarget* target);

    // Checks whether the particle contains a thing by a given position
    bool contains(sf::Vector2f point);
    bool contains(sf::Vector2i point);
    bool isOverlapping(BasicShape particle);

    // Getters and setters
public:
    // Set the particle's color
    void setColor(sf::Color color);
    // Get the particle's position. (0, 0) is top-left corner
    sf::Vector2f getPosition();
    // Set the particle's position
    void setPosition(sf::Vector2f pos);
    // Set/get the particle's size
    void setSize(sf::Vector2f size);
    void setSize(float size);
    sf::Vector2f getSize();
};

#endif