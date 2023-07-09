#include <SFML/Graphics.hpp>

#include "core/include/BasicShape.h"

#include "physics/include/Particle.h"

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
