#include <SFML/Graphics.hpp>
#include "physics/include/RidigBody.h"

RigidBody::RigidBody() : Physics()
{
	position = sf::Vector2f(200, 200);
}

RigidBody::~RigidBody() { }