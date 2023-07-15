#include <random>

#include "Math.h"

const float PI = 3.1415f;

float lerp(float start, float end, float t)
{
	return start * (1 - t) + end * t;
}

float rng()
{
    // Setup random number generator
    std::random_device rnddev;
    std::mt19937 gen(rnddev());
    std::uniform_real_distribution<float> dist(0.f, 1.f);

    float myRandomNumber = dist(gen);

    return myRandomNumber;
}

float rng(float low, float high)
{
    return rng() * (high - low) + low;
}
