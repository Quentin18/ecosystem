#include <cmath>

#include "rabbit.hpp"
#include "constants.hpp"

float distance(const sf::Vector2f a, const sf::Vector2f b)
{
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

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
