/**
 * @file perlin.cpp
 * @brief Perlin noise implementation in 1D
 */
#include "perlin.hpp"

using namespace Perlin;

/**
 * Function to linearly interpolate between a0 and a1.
 * Weight w should be in the range [0.0, 1.0].
 * 
 * @param a0
 * @param a1
 * @param w weight
 * @return interpolation between a0 and a1
 */
float Perlin::interpolate(float a0, float a1, float w)
{
    return (a1 - a0) * w + a0;
}

/**
 * Return a random noise from t.
 * 
 * Inspired by https://cochoy-jeremy.developpez.com/tutoriels/2d/introduction-bruit-perlin/
 * 
 * @param t time
 * @return float random noise
 */
float Perlin::randNoise(int t)
{
    t = (t<<13) ^ t;
    t = (t * (t * t * 15731 + 789221) + 1376312589);
    return 1.0 - (t & 0x7fffffff) / 1073741824.0;
}

/**
 * Compute Perlin noise at time t.
 * 
 * @param t time
 * @return float Perlin noise
 */
float Perlin::noise(float t)
{
    int t0 = (int)t;
    int t1 = t0 + 1;
    float sx = t - (float)t0;

    double n0 = randNoise(t0);
    double n1 = randNoise(t1);

    return interpolate(n0, n1, sx);
}
