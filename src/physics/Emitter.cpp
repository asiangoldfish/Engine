// External libraries
#include <SFML/Graphics.hpp>
#include <algorithm>

#include "shared/pch.h"

// Custom libraries
#include "core/BasicShape.h"

#include "Emitter.h"
#include "Particle.h"
#include "shared/Logger.h"
#include "shared/Math.h"

Emitter::Emitter()
{
    drag = 0.95f;
    maxCount = 10;
    initialVelocity = sf::Vector2f(0.f, 0.f);
    maxLifetime = 1;
    lifetimeVariance = 0.5f;

    emitterVisibility = false;

    emitterShape.setColor(sf::Color::Red);
    emitterShape.setSize(10.f);

    // Shape
    emitterShape.setSize(50.f);
}

void Emitter::setPosition(sf::Vector2f v)
{
    position = v;

    // Update the shape's position
    if (emitterVisibility) {
        // We center the shape, so the center is on our position
        emitterShape.setPosition({ v.x - emitterShape.getSize().x / 2.f, v.y - emitterShape.getSize().y / 2.f });
    }
}

void Emitter::addParticle(Particle* p)
{
    float max = rng(-lifetimeVariance, lifetimeVariance) + maxLifetime;
    max *= 1000.f;

    p->setPosition(position);
    p->setSize({ 10.f, 10.f });
    p->setInitialVelocity(initialVelocity.x * rng(-1.f, 1.f), initialVelocity.y * rng(-1.f, 1.f));
    p->setMaxLifetime(max);
    p->setDrag(drag);

    if (particles.size() < maxCount) {
        particles.emplace_back(p);
    }
}

void Emitter::addParticle(int num)
{
    for (int i = 0; i < num; i++) {
        Particle* p = new Particle();
        p->setSpriteColor(rng(100, 255), rng(100, 255), rng(100, 255));
        addParticle(p);
    }
}

void Emitter::removeParticle(int id)
{
    particles.erase(particles.begin() + id);
}

Particle* Emitter::getParticle(int id)
{
    return particles[id];
}

void Emitter::draw(sf::RenderWindow* target)
{
    if (emitterVisibility) {
        emitterShape.draw(target);
    }

    for (auto p : particles) {
        p->draw(target);
    }
}

void Emitter::update()
{
    for (auto p : particles) {
        p->update();

        if (p->getIsDead()) {
            auto id = std::find(particles.begin(), particles.end(), p);
            particles.erase(id);
        }
    }

    // Fix basic shape position so the center is always on the emitter's position
}

void Emitter::setInitialVelocity(float x, float y)
{
    initialVelocity = sf::Vector2f(x, y);
}

void Emitter::setInitialVelocity(float vel)
{
    initialVelocity = sf::Vector2f(vel, vel);
}

void Emitter::setSpriteColor(sf::Color color)
{
    for (auto p : particles) {
        p->setSpriteColor(color);
    }
}

void Emitter::setSpriteColor(float r, float g, float b)
{
    setSpriteColor(sf::Color(r, g, b));
}
