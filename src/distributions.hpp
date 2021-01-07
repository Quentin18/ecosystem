/**
 * @file distributions.hpp
 * @brief Header file defining random distributions
 */
#pragma once

#include <random>

#include "constants.hpp"

// Random engine
static std::random_device RD;
static std::default_random_engine RANDOM_ENGINE(RD());

// Distributions
static std::uniform_real_distribution<float> TIME_DISTRIBUTION(0, 10000);
static std::uniform_real_distribution<float> X_DISTRIBUTION(0, WINDOW_WIDTH);
static std::uniform_real_distribution<float> Y_DISTRIBUTION(0, WINDOW_HEIGHT);
static std::uniform_real_distribution<float> RAND_DISTRIBUTION(0, 1);
