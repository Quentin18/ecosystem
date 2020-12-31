#include <random>
#include <experimental/random>

#include "cell.hpp"
#include "constants.hpp"
#include "perlin.hpp"

/** Re-maps a number from one range to another.
 * 
 * Inspired by https://processing.org/reference/map_.html
 */
float Cell::map(float value, float start1, float stop1, float start2, float stop2)
{
    return start2 + (stop2 - start2) * (value - start1) / (stop1 - start1);
}

Cell::Cell()
{
    // Generators
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> dist_radius(CELL_MIN_RADIUS, CELL_MAX_RADIUS);
    std::uniform_real_distribution<float> dist_t(0, 10000);

    // Set variables
    radius = dist_radius(eng);
    tx = dist_t(eng);
    ty = dist_t(eng);

    // Init circle
    this->setOrigin(radius, radius);
    this->setRadius(radius);
    this->setFillColor(sf::Color::White);
    this->setPosition(x, y);
}

Cell::~Cell() {}

void Cell::update()
{
    x = map(Perlin::noise(tx), -1, 1, 0, WINDOW_WIDTH);
    y = map(Perlin::noise(ty), -1, 1, 0, WINDOW_HEIGHT);
    this->setPosition(x, y);
    tx += 0.01;
    ty += 0.01;
}
