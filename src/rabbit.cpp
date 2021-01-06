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
    sf::Vector2f posFood;
    sf::Vector2f posRabbit = this->getPosition();
    float d;
    for (std::list<Food>::iterator it = foods.begin(); it != foods.end(); it++)
    {
        posFood = it->getPosition();
        d = distance(posRabbit, posFood);
        if (d <= this->getRadius() + it->getRadius())
        {
            // The rabbit eats food
            resetHp();
            it->move();
        }
    }
}
