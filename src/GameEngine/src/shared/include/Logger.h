#pragma once

#include <SFML/Graphics.hpp>

#include <pch.h>

class Logger
{
private:
	// System time
	time_t now;					///< Current time
	tm ltm;						///< Time struct

private:
	Logger();

	void printTime();
	static void _log(bool includeTime);

public:
	/**
	 * @brief Singletons should not be clonable
	*/
	Logger(const Logger& other) = delete;

	/**
	 * @brief Singletons should not be assignable
	*/
	void operator=(const Logger&) = delete;

	/**
	 * @brief Get the one and only instance
	*/
	static Logger& getInstance();

	/**
	 * Log message with date
	 * @param msg 
	*/
	static void debug(std::string msg, bool includeTime=true);
	static void debug(int msg, bool includeTime = true);
	static void debug(float msg, bool includeTime=true);
	static void debug(std::string msg, sf::Vector2f vec, bool includeTime = true);
};