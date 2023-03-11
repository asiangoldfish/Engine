#pragma once

// Input/output
#include <iostream>

// Windows specific APIs
#include <windows.h>

// Time
#include <sysinfoapi.h> // Time

#include <ctime>

class Debug
{
private:
	/**
	 * System time
	*/
	struct tm newTime;
	time_t now = time(0);
	localtime_s(&newTime, &now);


public:
	/**
	 * Default constructor
	*/
	Debug()
	{
	}

	void log(std::string msg)
	{
		std::cout << "[" << now->tm_mday << '.'
			<< now->tm_mon + 1 << '.'
			<< now->tm_year + 1990 << '\n';
	}
};