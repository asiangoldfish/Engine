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

void Physics::applyGravity(sf::Transformable &t)
{
	float dt = clock.restart().asSeconds();

	if (t.getPosition().y > 600.0)
	{
		velocity = 0;
	}
	else
	{
		velocity += gravityAcceleration * gravityModifier;
		t.setPosition(
			t.getPosition().x,
			t.getPosition().y + velocity * dt
		);
	}
}

void Physics::addVelocity(float vel) { velocity += vel; }

void Physics::addThrust(float t, sf::Transformable& trans) 
{
	if (!velocity)
	{
		trans.setPosition(
			trans.getPosition().x,
			trans.getPosition().y - 10
		);
		velocity = -t; 
	}
}
