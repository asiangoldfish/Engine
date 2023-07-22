#ifndef EMITTER_H
#define EMITTER_H

#include <SFML/Graphics.hpp>

#include "core/BasicShape.h"
#include "physics/Particle.h"

class Emitter {
private:
    // Basic properties
    sf::Vector2f position;
    std::vector<Particle*> particles;
    uint maxCount;
    bool emitterVisibility;
    BasicShape emitterShape;

    // Physics
    sf::Vector2f initialVelocity;
    float drag;

    // Life cycle
    float maxLifetime;
    float lifetimeVariance;

public:
    Emitter();

    void addParticle(int num);
    void addParticle(Particle* p);

    void removeParticle(int id);

    Particle* getParticle(int id);

    void draw(sf::RenderWindow* target);
    void update();

    // Getters and setters
public:
    int getMaxCount() { return maxCount; }
    void setMaxCount(int m) { maxCount = m; }

    sf::Vector2f getPosition() { return emitterShape.getPosition(); }
    void setPosition(sf::Vector2f v);
    void setPosition(float x, float y) { setPosition({ x, y }); }

    void setEmitterVisibility(bool v) { emitterVisibility = v; }
    void setInitialVelocity(float x, float y);
    void setInitialVelocity(float vel);
    void setMaxLifeTime(float life) { maxLifetime = life; }
    void setLifeVariance(float variance) { lifetimeVariance = variance; }

    // Sprites
public:
    void setSpriteColor(sf::Color color);
    void setSpriteColor(float r, float g, float b);
};

#endif
