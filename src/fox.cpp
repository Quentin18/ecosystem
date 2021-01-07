/**
 * @file fox.cpp
 * @brief Source code for Fox class
 */
#include "fox.hpp"
#include "constants.hpp"

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
