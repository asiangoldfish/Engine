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

	if (t.getPosition().y >= 600)
	{
		velocity = 0;
		t.setPosition(
			t.getPosition().x,
			600 - 0.001
		);
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

void Physics::addThrust(float t) { velocity = -t; }
