#ifndef LOGGER_H
#define LOGGER_H

#include <SFML/Graphics.hpp>

#include "pch.h"

class Logger
{
private:
	// System time
	time_t now;					///< Current time
	tm ltm;						///< Time struct

private:

	void printTime();
	static void _log(bool includeTime);

public:
	Logger();
	
	/**
	 * Log message with date
	 * @param msg 
	*/
	static void debug(std::string msg, bool includeTime=true);
	static void debug(int msg, bool includeTime = true);
	static void debug(float msg, bool includeTime=true);
	static void debug(std::string msg, sf::Vector2f vec, bool includeTime = true);
};

#endif