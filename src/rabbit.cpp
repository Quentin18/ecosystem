/**
 * @file rabbit.cpp
 * @brief Source code for Rabbit class
 */
#include "rabbit.hpp"
#include "constants.hpp"

/**
 * Rabbit constructor
 */
Rabbit::Rabbit()
{
    this->setRadius(RABBIT_RADIUS);
    this->setFillColor(RABBIT_COLOR);
}

/**
 * Rabbit destructor
 */
Rabbit::~Rabbit() {}

/**
 * Method for rabbit vs food interaction.
 * 
 * When a rabbit is near a food, the rabbit eats the food.
 * The rabbit gets health points, the food disappears.
 * 
 * @param food list of foods
 * 
 */
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
