#pragma once

#include <SFML/Graphics.hpp>

#include "physics/include/Physics.h"

class RigidBody : public Physics
{
private:
	sf::Vector2f position;

public:
	RigidBody();
	virtual ~RigidBody();
};