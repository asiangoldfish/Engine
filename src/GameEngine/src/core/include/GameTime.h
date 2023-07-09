#pragma once

#include <SFML/Graphics.hpp>

#include "events/include/ISubject.h"

class GameTime : public ISubject
{
private:
	int elapsedTime;
	sf::Clock deltaClock;

public:
	GameTime();

	void updateTime();

	/**
	 * @brief Get the time it took between the last and the current frame.
	 * The time it took may be used to roughly estimate in how long the next
	 * frame may happen.
	 * @return the differential time between the last and the current frame
	*/
	int getDeltaTime();

	/**
	 * @brief Get time elapsed since it was last restarted.
	 * @return Time elapsed in milliseconds
	*/
	int getElapsedTime() { return elapsedTime; }

	float getElapsedTimeInSeconds() { return elapsedTime / 1000.f; }

	/**
	 * @brief Reset the time counter
	*/
	void resetTime() { elapsedTime = 0; }
};