#include <SFML/Graphics.hpp>
#include <type_traits>

#include "shared/pch.h"

#include "core/BasicShape.h"

#include "Particle.h"
#include "physics/Particle.h"

Particle::Particle()
{
    drag = 0.f;
    maxLifetime = 0;
    lifetime = 0;
    isDead = false;
    id = 0;
    initialVelocity = sf::Vector2f(0.f, 0.f);

    shape.setColor(sf::Color::Green);
    shape.setSize(5.f);

    sprite = new Sprite();
}

void Particle::draw(sf::RenderTarget* target)
{
    if (!isDead) {
        shape.draw(target);
    }
}

void Particle::update()
{
    // Update life
    if (!isDead) {
        time.updateTime();
        lifetime = time.getElapsedTime();

        isDead = lifetime >= maxLifetime;
    }

    if (isDead) {
        return;
    }

    // Update position
    shape.setPosition(
        { getPosition().x + initialVelocity.x, getPosition().y + initialVelocity.y });

    initialVelocity.x *= drag;
    initialVelocity.y *= drag;
}

void Particle::setInitialVelocity(float x, float y)
{
    initialVelocity = sf::Vector2f(x, y);
}

Particle::~Particle()
{
    delete sprite;
}
