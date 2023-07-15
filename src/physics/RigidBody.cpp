#include <SFML/Graphics.hpp>
#include "RigidBody.h"

RigidBody::RigidBody() : Physics()
{
}

RigidBody::~RigidBody() { }

void RigidBody::updatePhysics(sf::Transformable &shape)
{
	applyGravity(shape);
}
