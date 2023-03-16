#include "shared/include/Logger.h"

void Logger::_printTime(bool includeTime)
{
	if (includeTime)
	{
		now = time(0);				// Update time
		localtime_s(&ltm, &now);	// local time

		std::cout
			// Date
			<< '[' << ltm.tm_mday << '.' << ltm.tm_mon << '.' << 1900 + ltm.tm_year << ' '
			// Time
			<< ltm.tm_hour << ':' << ltm.tm_min << ':' << ltm.tm_sec << "] ";
	}
}

Logger::Logger()
{
	now = time(0);
}

/**
 * Log message with date
 * @param msg 
*/
void Logger::log(std::string msg, bool includeTime)
{
	_printTime(includeTime);

	// Message
	std::cout << msg << '\n';
}

void Logger::log(int msg, bool includeTime)
{
	_printTime(includeTime);

	// Message
	std::cout << msg << '\n';
}
