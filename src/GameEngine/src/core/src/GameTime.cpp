#include "SFML/Graphics.hpp"

#include "core/include/GameTime.h"

GameTime::GameTime()
{
	elapsedTime = 0.f;
}

GameTime& GameTime::getInstance()
{
	static GameTime gt;
	return gt;
}

void GameTime::updateTime()
{
	GameTime::getInstance().elapsedTime += GameTime::getInstance().deltaClock.restart().asMilliseconds();
}

