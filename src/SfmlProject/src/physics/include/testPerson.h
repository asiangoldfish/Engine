#pragma once

#include <SFML/Graphics.hpp>
#include "physics/include/RidigBody.h"

#include "shared/include/Logger.h"

class Person : public RigidBody
{
private:
	sf::CircleShape shape;

	Logger debug;

public:
	Person();

	void draw(sf::RenderTarget* target);

	void setPosition(float x, float y);

	void jump();

	void move(float x, float y);
};