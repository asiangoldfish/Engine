#pragma once

// Input/output
#include <iostream>

// Windows specific APIs
#include <windows.h>

// Time
#include <sysinfoapi.h> // Time

#include <chrono>
#include <ctime>

class Debug
{
private:
	// System time
	time_t now;
	tm ltm;						// Time struct

public:
	/**
	 * Default constructor
	*/
	Debug()
	{
		now = time(0);
	}

	/**
	 * Log message with date
	 * @param msg 
	*/
	void log(std::string msg, bool includeTime=true)
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
};