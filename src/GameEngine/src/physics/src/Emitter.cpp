#include <vector>

// External libraries
#include <SFML/Graphics.hpp>

// Custom libraries
#include "physics/include/Particle.h"
#include "core/include/BasicShape.h"

#include "shared/include/Logger.h"

#include "physics/include/Emitter.h"

Emitter::Emitter()
{
	count = 0;
	maxCount = 10;
	initialVelocity = 5;
	maxLifetime = 1;
	lifetimeVariance = 0.5f;
	
	emitterVisibility = false;

	// Shape
	emitterShape.setSize(50.f);
}

void Emitter::addParticle(Particle p)
{
	p.setPosition(emitterShape.getPosition());
	p.setSize({ 10.f, 10.f });

	if (count < maxCount)
	{
		particles.emplace_back(p);
		count++;
	}
}

void Emitter::removeParticle(int id)
{
	particles.erase(particles.begin() + id);
}

Particle Emitter::getParticle(int id)
{
	return particles[id];
}

void Emitter::draw(sf::RenderWindow* target)
{
	if (emitterVisibility)
	{
		emitterShape.draw(target);
	}

	// TODO - Draw all particles without loop
	for (auto p : particles)
	{
		p.draw(target);
	}
}


