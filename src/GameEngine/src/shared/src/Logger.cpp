#include <SFML/Graphics.hpp>

// Input/output
#include <iostream>
#include <iomanip>

// Windows specific APIs
#include <windows.h>

// Time
#include <sysinfoapi.h> // Time

#include <chrono>
#include <ctime>


#include "shared/include/Logger.h"

void Logger::printTime()
{
		now = time(0);				// Update time
		localtime_s(&ltm, &now);	// local time

	std::cout
		// ******
		// Date
		// ******
		<< "[ " << std::setw(2) << std::setfill('0') << ltm.tm_mday << '.'	// Day
		<< std::setw(2) << std::setfill('0') << ltm.tm_mon << '.'			// Month
		<< 1900 + ltm.tm_year << ' '										// Year

		// ******
		// Time
		// ******
		<< std::setw(2) << std::setfill('0') << ltm.tm_hour << ':'			// Hour
		<< std::setw(2) << std::setfill('0') << ltm.tm_min << ':'			// Minutes
		<< std::setw(2) << std::setfill('0') << ltm.tm_sec << " ] ";			// Seconds
}

Logger::Logger()
{
	now = time(0);
}

void Logger::_log(bool includeTime)
{
	if (includeTime)
	{
		Logger::getInstance().printTime();
	}
}

Logger& Logger::getInstance()
{
	static Logger instance;
	return instance;
}

/**
 * Log message with date
 * @param msg 
*/
void Logger::log(std::string msg, bool includeTime)
{
	_log(includeTime);

	// Message
	std::cout << "LOGGER: " << msg << '\n';
}

void Logger::log(int msg, bool includeTime)
{
	_log(includeTime);

	// Message
	std::cout << "LOGGER: " << msg << '\n';
}

void Logger::log(std::string msg, sf::Vector2f vec, bool includeTime)
{
	_log(includeTime);
	std::cout << msg << "(" << vec.x << ", " << vec.y << ")" << std::endl;
}
