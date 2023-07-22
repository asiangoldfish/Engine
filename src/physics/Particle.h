#ifndef PARTICLES_H
#define PARTICLES_H

#include "core/BasicShape.h"
#include "core/GameTime.h"
#include "physics/Sprite.h"

enum EFFECT {
    DEFAULT,
    NORMAL
};

class Particle {
private:
    int id;
    float lifetime; // Current lifetime
    float maxLifetime; // Die at x lifetime
    bool isDead;
    sf::Vector2f initialVelocity;
    float drag;
    GameTime time;

    BasicShape shape;

    Sprite* sprite;

public:
    virtual ~Particle();
    Particle();
    void draw(sf::RenderTarget* target);
    void update();

    // Getters and setters
public:
    // Position
    sf::Vector2f getPosition() { return shape.getPosition(); }
    void setPosition(sf::Vector2f v) { shape.setPosition(v); }

    // Size
    sf::Vector2f getSize() { return shape.getSize(); }
    void setSize(sf::Vector2f s) { shape.setSize(s); }

    // Initial velocity
    void setInitialVelocity(float x, float y);

    bool getIsDead() { return isDead; }

    void setMaxLifetime(float life) { maxLifetime = life; }

    void setDrag(float d) { drag = d; }

    // Sprites
public:
    void setSpriteColor(sf::Color color)
    {
        shape.setColor(color);
    }
    void setSpriteColor(float r, float g, float b) { shape.setColor(sf::Color(r, g, b)); }
};

#endif
