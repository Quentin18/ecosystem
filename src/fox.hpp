/**
 * @file fox.hpp
 * @brief Header file for Fox class
 */
#pragma once

#include <list>

#include "animal.hpp"
#include "rabbit.hpp"

/**
 * Represent a fox. It inherits from the Animal class.
 */
class Fox : public Animal
{
public:
    Fox();
    ~Fox();
    void eat(std::list<Rabbit> &rabbits);
};
