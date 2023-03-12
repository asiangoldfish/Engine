#include "shared/include/debug.h"

Debug::Debug()
{
	now = time(0);
}

/**
 * Log message with date
 * @param msg 
*/
void Debug::log(std::string msg, bool includeTime)
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

	// Message
	std::cout << msg << '\n';
}