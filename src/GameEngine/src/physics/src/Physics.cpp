#include "physics/include/Physics.h"

Physics::Physics()
{
	gravityModifier = 1;
	velocity = sf::Vector2f(0, 100);
}

Physics::~Physics()
{
}

void Physics::applyGravity(sf::Transformable &t)
{
	float dt = clock.restart().asSeconds();

	if (t.getPosition().y > 600.0)
	{
		velocity = sf::Vector2f(velocity.x, 0);
	}
	else
	{
		velocity.y += gravityAcceleration * gravityModifier;
		t.setPosition(
			t.getPosition().x,
			t.getPosition().y + velocity.y * dt
		);
	}
}

void Physics::addVelocity(float vel) { velocity.y += vel; }

void Physics::addThrust(float t, sf::Transformable& trans) 
{
	if (!velocity.y)
	{
		trans.setPosition(
			trans.getPosition().x,
			trans.getPosition().y - 10
		);
		velocity.y = -t; 
	}
}
