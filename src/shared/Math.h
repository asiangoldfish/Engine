#ifndef MATH_H
#define MATH_H

/**
 * Shared header containing mathematical functions
 */

/**
 * @brief Linear interpolation between start and end value
 * @param start Start value
 * @param end End value
 * @param t Control value that determines where between the start and end
 *			value the return value should be at
 * @return A value between start and end, depending on t
*/
float lerp(float start, float end, float t);

/**
 * @brief Generate a random number between 0.0 and 1.0
 * @return Random number between 0.0 and 1.0
*/
float rng();

/**
 * @brief Generate a random number between named low and high value
 * @param low Lowest number to generate
 * @param high Highest number to generate
 * @return Random number between lowest and highest number
*/
float rng(float low, float high);



#endif