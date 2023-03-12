#pragma once

#include <SFML/Graphics.hpp>
#include "physics/include/RidigBody.h"

#include "shared/include/Debug.h"

class Person : public RigidBody
{
private:
	sf::CircleShape shape;

	Debug debug;

public:
	Person();

	void draw(sf::RenderTarget* target);

	void setPosition(float x, float y);

	void jump();

	void move(float x, float y);
};