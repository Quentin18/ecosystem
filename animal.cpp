#include <random>
#include <experimental/random>

#include "animal.hpp"
#include "constants.hpp"
#include "perlin.hpp"

/** Re-maps a number from one range to another.
 * 
 * Inspired by https://processing.org/reference/map_.html
 */
float Animal::map(float value, float start1, float stop1, float start2, float stop2)
{
    return start2 + (stop2 - start2) * (value - start1) / (stop1 - start1);
}

Animal::Animal() : hp(ANIMAL_MAX_HP)
{
    // Generators
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> dist_radius(ANIMAL_MIN_RADIUS, ANIMAL_MAX_RADIUS);
    std::uniform_real_distribution<float> dist_t(0, 10000);

    // Set variables
    radius = dist_radius(eng);
    tx = dist_t(eng);
    ty = dist_t(eng);

    // Init circle
    this->setOrigin(radius, radius);
    this->setRadius(radius);
    this->setFillColor(ANIMAL_DEFAULT_COLOR);
    this->setPosition(x, y);
}

Animal::~Animal() {}

void Animal::update()
{
    x = map(Perlin::noise(tx), -1, 1, 0, WINDOW_WIDTH);
    y = map(Perlin::noise(ty), -1, 1, 0, WINDOW_HEIGHT);
    this->setPosition(x, y);
    tx += 0.01;
    ty += 0.01;
    hp--;
}

bool Animal::is_dead() const
{
    return hp <= 0;
}
