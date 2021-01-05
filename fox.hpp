#pragma once

#include <list>

#include "animal.hpp"
#include "rabbit.hpp"

class Fox : public Animal
{
public:
    Fox();
    ~Fox();
    void eat(std::list<Rabbit> *rabbits);
};
