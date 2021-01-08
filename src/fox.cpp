/**
 * @file fox.cpp
 * @brief Source code for Fox class
 */
#include "fox.hpp"
#include "constants.hpp"
#include "distributions.hpp"

/**
 * Fox constructor
 */
Fox::Fox()
{
    this->setRadius(FOXES_RADIUS);
    this->setFillColor(FOX_COLOR);
}

/**
 * Fox destructor
 */
Fox::~Fox() {}

/**
 * Method for fox vs rabbit interaction.
 * 
 * When a fox is near a rabbit, the fox eats the rabbit.
 * The fox gets health points, the rabbit is dead.
 * 
 * @param rabbits list of rabbits
 * @return int 1 if a rabbit is killed, 0 else
 * 
 */
int Fox::eat(std::list<Rabbit> &rabbits)
{
    sf::Vector2f posRabbit;
    sf::Vector2f posFox = this->getPosition();
    float d;
    for (std::list<Rabbit>::iterator it = rabbits.begin(); it != rabbits.end(); it++)
    {
        posRabbit = it->getPosition();
        d = distance(posFox, posRabbit);
        if (d <= this->getRadius() + it->getRadius())
        {
            // The fox eats the rabbit
            resetHp();
            it = rabbits.erase(it);
            return 1;
        }
    }
    return 0;
}

/**
 * Method for fox vs fox interaction.
 * 
 * When a fox is near another fox, a new fox is created with a probability.
 * 
 * @param fox a fox
 * @return true if there is a new fox, false else
 * 
 */
bool Fox::reproduce(Fox &fox) const
{
    float d = distance(fox.getPosition(), this->getPosition());
    return (d <= this->getRadius() && RAND_DISTRIBUTION(RANDOM_ENGINE) <= FOX_REPRODUCTION_PROBABILITY);
}

/**
 * Operator + between two foxes.
 * 
 * Returns true if there is a reproduction between the two foxes.
 * 
 * @param fox a fox
 * @return true if there is a new fox, false else
 * 
 */
bool Fox::operator+(Fox &fox) const
{
    return this->reproduce(fox);
}
