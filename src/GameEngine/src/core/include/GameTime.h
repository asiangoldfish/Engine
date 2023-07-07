#pragma once

class GameTime
{
private:
	int elapsedTime;

	sf::Clock deltaClock;

	GameTime();
	static GameTime& getInstance();

public:
	static void updateTime();
	static int getDeltaTime() { return GameTime::getInstance().deltaClock.getElapsedTime().asMilliseconds(); }
	static int getElapsedTime() { return GameTime::getInstance().elapsedTime; };
};