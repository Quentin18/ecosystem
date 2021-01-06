/**
 * @file rabbit.hpp
 * @brief Header file for Rabbit class
 */
#pragma once

#include <list>

#include "animal.hpp"
#include "food.hpp"

/**
 * Represent a rabbit. It inherits from the Animal class.
 */
class Rabbit : public Animal
{
public:
    Rabbit();
    ~Rabbit();
    void eat(std::list<Food> &foods);
};
