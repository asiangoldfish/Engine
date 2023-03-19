#pragma once

#include <ctime>

class Logger
{
private:
	// System time
	time_t now;					///< Current time
	tm ltm;						///< Time struct

private:
	void _printTime(bool includeTime);

public:
	/**
	 * Default constructor
	*/
	Logger();

	/**
	 * Log message with date
	 * @param msg 
	*/
	void log(std::string msg, bool includeTime=true);
	void log(int msg, bool includeTime=true);
};