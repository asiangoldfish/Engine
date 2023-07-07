#include <SFML/Graphics.hpp>

#include "core/include/BasicShape.h"

#include "physics/include/Particle.h"

Particle::Particle()
{
}

void Particle::draw(sf::RenderTarget* target)
{
	shape.draw(target);
}
