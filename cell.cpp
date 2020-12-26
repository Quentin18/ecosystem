#include <random>
#include <experimental/random>

#include "cell.hpp"
#include "constants.hpp"

Cell::Cell()
{
    // Generators
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> dist_radius(CELL_MIN_RADIUS, CELL_MAX_RADIUS);
    std::uniform_real_distribution<float> dist_speed(CELL_MIN_SPEED, CELL_MAX_SPEED);
    std::uniform_real_distribution<float> dist_x(0, WINDOW_WIDTH);
    std::uniform_real_distribution<float> dist_y(0, WINDOW_HEIGHT);

    // Set variables
    radius = dist_radius(eng);
    speed = dist_speed(eng);
    x = dist_x(eng);
    y = dist_y(eng);

    // Init circle
    this->setOrigin(radius, radius);
    this->setRadius(radius);
    this->setFillColor(sf::Color::White);
    this->setPosition(x, y);
}

Cell::~Cell() {}

void Cell::update()
{
    int dx = std::experimental::randint(-1, 1);
    int dy = std::experimental::randint(-1, 1);
    x += dx * speed;
    y += dy * speed;
    if (x < 0 || x > WINDOW_WIDTH)
    {
        x -= 2 * dx * speed;
    }
    if (y < 0 || y > WINDOW_HEIGHT)
    {
        y -= 2 * dy * speed;
    }
    this->setPosition(x, y);
}
