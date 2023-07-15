#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <SFML/Graphics.hpp>

#include "Physics.h"

class RigidBody : public Physics
{
public:
	RigidBody();
	virtual ~RigidBody();

	// Update physics
	void updatePhysics(sf::Transformable &shape);

};

#endif