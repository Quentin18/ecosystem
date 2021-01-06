#pragma once

#include <list>

#include "animal.hpp"
#include "food.hpp"

class Rabbit : public Animal
{
public:
    Rabbit();
    ~Rabbit();
    void eat(std::list<Food> &foods);
};
