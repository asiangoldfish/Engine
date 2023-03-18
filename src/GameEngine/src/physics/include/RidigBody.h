#pragma once

#include <SFML/Graphics.hpp>

#include "physics/include/Physics.h"

class RigidBody : public Physics
{
public:
	RigidBody();
	virtual ~RigidBody();

	// Update physics
	void updatePhysics(sf::Transformable &shape);

};