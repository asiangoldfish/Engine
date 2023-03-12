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
	Debug();

	/**
	 * Log message with date
	 * @param msg 
	*/
	void log(std::string msg, bool includeTime=true);
	void log(int msg, bool includeTime=true);
};