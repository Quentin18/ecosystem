#include <random>

#include "food.hpp"
#include "constants.hpp"

Food::Food()
{
    // Init circle
    this->setOrigin(FOOD_RADIUS, FOOD_RADIUS);
    this->setRadius(FOOD_RADIUS);
    this->setFillColor(FOOD_COLOR);
    move();
}

Food::~Food() {}

void Food::move()
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> dist_x(0, WINDOW_WIDTH);
    std::uniform_real_distribution<float> dist_y(0, WINDOW_HEIGHT);
    this->setPosition(dist_x(eng), dist_y(eng));
}
