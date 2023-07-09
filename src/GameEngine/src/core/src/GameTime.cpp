#include "../include/GameTime.h"
#include "shared/include/Logger.h"

GameTime::GameTime()
{
	elapsedTime = 0;
}

void GameTime::updateTime()
{
	elapsedTime += deltaClock.restart().asMilliseconds();
}

int GameTime::getDeltaTime()
{
	return deltaClock.getElapsedTime().asMilliseconds();
}