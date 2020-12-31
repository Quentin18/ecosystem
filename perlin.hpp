#pragma once

/**
 * Simple Perlin noise implementation in 1D.
 * 
 * Inspired by: https://en.wikipedia.org/wiki/Perlin_noise
 */
namespace Perlin
{
    float interpolate(float a0, float a1, float w);
    float rand_noise(int t);
    float noise(float x);
}
