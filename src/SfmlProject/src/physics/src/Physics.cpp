#include "physics/include/Physics.h"

Physics::Physics()
{
	gravityModifier = 1;
	velocity = 100;
	debug = Debug();
}

Physics::~Physics()
{
}

void Physics::updatePosition(sf::Transformable &t)
{
	float dt = clock.restart().asSeconds();
	velocity += gravityAcceleration * gravityModifier;
	t.setPosition(
		t.getPosition().x,
		t.getPosition().y + velocity * dt
	);
}

void Physics::addVelocity(float vel) { velocity += vel; }