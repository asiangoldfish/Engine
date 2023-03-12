#include "physics/include/testPerson.h"

Person::Person() : RigidBody()
{
	shape = sf::CircleShape(1);
	shape.setScale(30, 30);
	shape.setFillColor(sf::Color::Red);
}

void Person::draw(sf::RenderTarget *target)
{
	// Apply and update the person's physics
	updatePhysics(shape);

	target->draw(shape);
}

void Person::setPosition(float x, float y)
{
	shape.setPosition(x, y);
}

void Person::jump() { addThrust(500); }

void Person::move(float x, float y)
{
	shape.setPosition(
		shape.getPosition().x + x, shape.getPosition().y + y
	);
}

