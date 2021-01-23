/**
 * @file rabbit.cpp
 * @brief Source code for Rabbit class
 */
#include "rabbit.hpp"
#include "constants.hpp"
#include "distributions.hpp"

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
 * @param foods list of foods
 * @return int 1 if a food is eaten, 0 else
 * 
 */
int Rabbit::eat(std::list<Food> &foods)
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
            return 1;
        }
    }
    return 0;
}

/**
 * Method for rabbit vs rabbit interaction.
 * 
 * When a rabbit is near another rabbit, a new rabbit is created with a probability.
 * 
 * @param rabbit a rabbit
 * @return true if there is a new rabbit, false else
 * 
 */
bool Rabbit::reproduce(Rabbit &rabbit) const
{
    float d = distance(rabbit.getPosition(), this->getPosition());
    return (d <= this->getRadius() && RAND_DISTRIBUTION(RANDOM_ENGINE) <= RABBIT_REPRODUCTION_PROBABILITY);
}

/**
 * Operator + between two rabbits.
 * 
 * Returns true if there is a reproduction between the two rabbits.
 * 
 * @param rabbit a rabbit
 * @return true if there is a new rabbit, false else
 * 
 */
bool Rabbit::operator+(Rabbit &rabbit) const
{
    return this->reproduce(rabbit);
}
