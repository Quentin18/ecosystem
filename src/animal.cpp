/**
 * @file animal.cpp
 * @brief Source code for Animal class
 */
#include <cmath>

#include "animal.hpp"
#include "constants.hpp"
#include "perlin.hpp"
#include "distributions.hpp"

/**
 * Re-maps a number from one range to another.
 * 
 * Inspired by https://processing.org/reference/map_.html
 * 
 * @param value the incoming value to be converted
 * @param start1 lower bound of the value's current range
 * @param stop1 upper bound of the value's current range
 * @param start2 lower bound of the value's target range
 * @param stop2 upper bound of the value's target range
 * @return float
 * 
 */
float Animal::map(float value, float start1, float stop1, float start2, float stop2)
{
    return start2 + (stop2 - start2) * (value - start1) / (stop1 - start1);
}

/**
 * Animal constructor
 */
Animal::Animal() : radius(ANIMAL_DEFAULT_RADIUS), hp(ANIMAL_MAX_HP)
{
    // Set time variables
    tx = TIME_DISTRIBUTION(RANDOM_ENGINE);
    ty = TIME_DISTRIBUTION(RANDOM_ENGINE);

    // Init circle
    this->setOrigin(radius, radius);
    this->setRadius(radius);
    this->setFillColor(ANIMAL_DEFAULT_COLOR);
    this->setOutlineColor(CIRCLE_OUTLINE_COLOR);
    this->setOutlineThickness(CIRCLE_THICKNESS);
    this->setPosition(x, y);
}

/**
 * Animal destructor
 */
Animal::~Animal() {}

/**
 * Move the animal using Perlin noise
 * 
 * @param timeSpeed speed of the simulation
 * 
 */
void Animal::move(const float timeSpeed)
{
    x = map(Perlin::noise(tx), -1, 1, 0, WINDOW_WIDTH);
    y = map(Perlin::noise(ty), -1, 1, 0, WINDOW_HEIGHT);
    this->setPosition(x, y);
    tx += 0.01 * timeSpeed;
    ty += 0.01 * timeSpeed;
    hp -= timeSpeed;
}

/**
 * Return true if the animal is dead
 * 
 * @return true if the animal has no health points
 * 
 */
bool Animal::isDead() const
{
    return hp <= 0;
}

/**
 * Reset the health points of the animal
 */
void Animal::resetHp()
{
    hp = ANIMAL_MAX_HP;
}

/**
 * Return the distance between two points of the window
 * 
 * @param a vector representing the first point
 * @param b vector representing the second point
 * @return Euclidean distance between the two points
 * 
 */
float Animal::distance(const sf::Vector2f a, const sf::Vector2f b)
{
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}
