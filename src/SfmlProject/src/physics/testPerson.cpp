#pragma once

#include <SFML/Graphics.hpp>
#include "physics/include/RidigBody.h"

#include "shared/include/Debug.h"

class Person : public RigidBody
{
private:
	sf::CircleShape c;

	Debug debug;

public:
	Person() : RigidBody()
	{
		c = sf::CircleShape(30);
		c.setFillColor(sf::Color::Red);
	}

	~Person()
	{

	}

	void draw(sf::RenderTarget *target)
	{
		updatePosition(c);
		target->draw(c);
	}

	void setPosition(float x, float y) { c.setPosition(x, y); }

	void jump() { Physics::addVelocity(100); debug.log("Jumping!"); }
};