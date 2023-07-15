#include <SFML/Graphics.hpp>

#include "core/BasicShape.h"

#include "physics/Particle.h"

Particle::Particle()
{
	maxLifetime = 0;
	lifetime = 0;
	isDead = false;
	id = 0;
}

void Particle::draw(sf::RenderTarget* target)
{
	shape.draw(target);
}
