#include <SFML/Graphics.hpp>
#include "physics/include/RidigBody.h"

RigidBody::RigidBody() : Physics()
{
}

RigidBody::~RigidBody() { }

void RigidBody::updatePhysics(sf::Transformable &shape)
{
	applyGravity(shape);
}
