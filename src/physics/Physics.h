#ifndef PHYSICS_H
#define PHYSICS_H

#include <SFML/Graphics.hpp>

#include <cmath>

#include "shared/Logger.h"

class Physics
{
private:
	const float gravityAcceleration = 9.8f;		///< Gravitational acceleration
	float gravityModifier;	///< Gravitational acceleration modifier
	sf::Vector2f velocity;	///< Velocity at any given point in time

	sf::Clock clock;

public:
	Physics();

	virtual ~Physics();

	void applyGravity(sf::Transformable &t);

	void addVelocity(float vel);

	void addThrust(float t, sf::Transformable& trans);
};

#endif