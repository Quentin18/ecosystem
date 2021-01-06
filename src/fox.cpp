#include "fox.hpp"
#include "constants.hpp"

Fox::Fox()
{
    this->setRadius(FOXES_RADIUS);
    this->setFillColor(FOX_COLOR);
}

Fox::~Fox() {}

void Fox::eat(std::list<Rabbit> &rabbits)
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
        }
    }
}
