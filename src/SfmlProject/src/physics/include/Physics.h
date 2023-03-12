#pragma once

#include <cmath>

#include <SFML/Graphics.hpp>

#include "shared/include/Debug.h"

class Physics
{
private:
	const float gravityAcceleration = 9.8f;
	float gravityModifier;
	float velocity;

	sf::Clock clock;

protected:
	Debug debug;

public:
	Physics();

	virtual ~Physics();

	void applyGravity(sf::Transformable &t);

	void addVelocity(float vel);

	void addThrust(float t);
};