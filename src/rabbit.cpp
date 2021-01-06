#include "rabbit.hpp"
#include "constants.hpp"

Rabbit::Rabbit()
{
    this->setRadius(RABBIT_RADIUS);
    this->setFillColor(RABBIT_COLOR);
}

Rabbit::~Rabbit() {}

void Rabbit::eat(std::list<Food> &foods)
{
    // TODO to complete
}
