/**
 * @file foods.cpp
 * @brief Source code for Foods class
 */
#include "foods.hpp"

/**
 * Foods constructor
 */
Foods::Foods() {}

/**
 * Foods destructor
 */
Foods::~Foods() {}

/**
 * Get the list of foods
 * 
 * @return list of foods
 */
std::list<Food>* Foods::getList()
{
    return &foods;
}

/**
 * Init the foods
 * 
 * @param nbFoods number of foods
 */
void Foods::init(const unsigned int nbFoods)
{
    foods.clear();
    for (unsigned int i = 0; i < nbFoods; i++)
    {
        foods.emplace_back();
    }
}

/**
 * Draw foods to the target
 */
void Foods::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto it = foods.begin(); it != foods.end(); ++it)
    {
        target.draw(*it);
    }
}
