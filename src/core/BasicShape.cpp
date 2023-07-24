// SFML
#include <SFML/Graphics.hpp>

#include "BasicShape.h"
#include "core/BasicShape.h"

void BasicShape::constructShape()
{
    // Vertex 1 - Top left
    vertices[0].position = sf::Vector2f({ 0.f, 0.f });
    vertices[0].color = color;

    // Vertex 2 - Top right
    vertices[1].position = sf::Vector2f({ 1.f * size.x, 0.f });
    vertices[1].color = color;

    // Vertex 3 - Bottom right
    vertices[2].position = sf::Vector2f({ 1.f * size.x, 1.f * size.y });
    vertices[2].color = color;

    // Vertex 4 - Bottom left
    vertices[3].position = sf::Vector2f({ 0.f, 1.f * size.y });
    vertices[3].color = color;
}

BasicShape::BasicShape()
{
    size = { 0.f, 0.f };
    color = sf::Color::Red;

    constructShape();
}

BasicShape::BasicShape(sf::Vector2f size, sf::Color color)
{
    this->size = size;
    this->color = color;
    constructShape();
}
BasicShape::BasicShape(float size, sf::Color color)
{
    this->size = { size, size };
    this->color = color;

    constructShape();
}
void BasicShape::draw(sf::RenderTarget* target)
{
    target->draw(vertices, 4, sf::Quads);
}

bool BasicShape::contains(sf::Vector2f point)
{
    return
        // Left border
        point.x >= this->vertices[0].position.x &&

        // Right border
        point.x <= this->vertices[0].position.x + size.x &&

        // Upper border
        point.y >= this->vertices[0].position.y &&

        // Bottom border
        point.y <= this->vertices[0].position.y + size.y;
}

bool BasicShape::contains(sf::Vector2i point)
{
    // Cast int to float
    float x = static_cast<float>(point.x);
    float y = static_cast<float>(point.y);
    return contains(sf::Vector2f(x, y));
}

bool BasicShape::isOverlapping(BasicShape target)
{
    return
        // Left border
        target.getPosition().x + target.getSize().x >= this->vertices[0].position.x &&

        // Right border
        target.getPosition().x <= this->vertices[1].position.x &&

        // Upper border
        target.getPosition().y + target.getSize().y >= this->vertices[1].position.y &&

        // Bottom border
        target.getPosition().y <= this->vertices[2].position.y;
}

void BasicShape::setColor(sf::Color color)
{
    // Vertex 1 - Top left
    vertices[0].color = color;

    // Vertex 2 - Top right
    vertices[1].color = color;

    // Vertex 3 - Bottom right
    vertices[2].color = color;

    // Vertex 4 - Bottom left
    vertices[3].color = color;
}

void BasicShape::setColor(float r, float g, float b)
{
    setColor(sf::Color(r, g, b));
}

sf::Vector2f BasicShape::getPosition()
{
    return vertices[0].position;
}

void BasicShape::setPosition(sf::Vector2f pos)
{
    // Vertex 1 - Top left
    vertices[0].position = sf::Vector2f({ 0.f, 0.f }) + pos;

    // Vertex 2 - Top right
    vertices[1].position = sf::Vector2f({ 1.f * size.x, 0.f }) + pos;

    // Vertex 3 - Bottom right
    vertices[2].position = sf::Vector2f({ 1.f * size.x, 1.f * size.y }) + pos;

    // Vertex 4 - Bottom left
    vertices[3].position = sf::Vector2f({ 0.f, 1.f * size.y }) + pos;
}

void BasicShape::setSize(sf::Vector2f size)
{
    this->size = size;
}

void BasicShape::setSize(float size)
{
    setSize({ size, size });
}

sf::Vector2f BasicShape::getSize()
{
    return size;
}
