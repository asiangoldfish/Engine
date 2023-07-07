#pragma once

#include "physics/include/Particle.h"
#include "core/include/BasicShape.h"

class Emitter
{
private:
	// Basic properties
	std::vector<Particle> particles;
	int count;
	int maxCount;
	bool emitterVisibility;
	BasicShape emitterShape;

	// Physics
	float initialVelocity;
	
	// Life cycle
	float maxLifetime;
	float lifetimeVariance;

public:
	Emitter();
	
	void addParticle(Particle p);

	void removeParticle(int id);

	Particle getParticle(int id);

	void draw(sf::RenderWindow* target);

// Getters and setters
public:
	int getMaxCount() { return maxCount; }
	void setMaxCount(int m) { maxCount = m; }
	
	sf::Vector2f getPosition() { emitterShape.getPosition(); }
	void setPosition(sf::Vector2f v) { emitterShape.setPosition({ v.x - emitterShape.getSize().x / 2.f, v.y - emitterShape.getSize().y / 2.f }); }

	void setEmitterVisibility(bool v) { emitterVisibility = v; }
};