#ifndef PARTICLES_H
#define PARTICLES_H

#include "core/BasicShape.h"

class Particle {
private:
	int id;
	float lifetime;		// Current lifetime
	float maxLifetime;	// Die at x lifetime
	bool isDead;

	BasicShape shape;

public:
	Particle();
	void draw(sf::RenderTarget *target);

// Getters and setters
public:
	// Position
	sf::Vector2f getPosition() { return shape.getPosition(); }
	void setPosition(sf::Vector2f v) { shape.setPosition(v); }

	// Size
	sf::Vector2f getSize() { return shape.getSize(); }
	void setSize(sf::Vector2f s) { shape.setSize(s); }
};

#endif