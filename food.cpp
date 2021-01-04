#include "food.hpp"
#include "constants.hpp"
#include "distributions.hpp"

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
    this->setPosition(X_DISTRIBUTION(RANDOM_ENGINE), Y_DISTRIBUTION(RANDOM_ENGINE));
}
