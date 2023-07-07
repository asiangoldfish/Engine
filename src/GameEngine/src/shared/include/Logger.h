#pragma once

#include <SFML/Graphics.hpp>

class Logger
{
private:
	// System time
	time_t now;					///< Current time
	tm ltm;						///< Time struct

private:
	void printTime();
	Logger();
	static void _log(bool includeTime);

public:
	static Logger& getInstance();

	/**
	 * Log message with date
	 * @param msg 
	*/
	static void log(std::string msg, bool includeTime=true);
	static void log(int msg, bool includeTime=true);
	static void log(std::string msg, sf::Vector2f vec, bool includeTime = true);
};