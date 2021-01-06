#include <cmath>

#include "animal.hpp"
#include "constants.hpp"
#include "perlin.hpp"
#include "distributions.hpp"

/** Re-maps a number from one range to another.
 * 
 * Inspired by https://processing.org/reference/map_.html
 */
float Animal::map(float value, float start1, float stop1, float start2, float stop2)
{
    return start2 + (stop2 - start2) * (value - start1) / (stop1 - start1);
}

Animal::Animal() : radius(ANIMAL_DEFAULT_RADIUS), hp(ANIMAL_MAX_HP)
{
    // Set variables
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

Animal::~Animal() {}

void Animal::move()
{
    x = map(Perlin::noise(tx), -1, 1, 0, WINDOW_WIDTH);
    y = map(Perlin::noise(ty), -1, 1, 0, WINDOW_HEIGHT);
    this->setPosition(x, y);
    tx += 0.01;
    ty += 0.01;
    hp--;
}

bool Animal::isDead() const
{
    return hp <= 0;
}

void Animal::resetHp()
{
    hp = ANIMAL_MAX_HP;
}

float Animal::distance(const sf::Vector2f a, const sf::Vector2f b)
{
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}
