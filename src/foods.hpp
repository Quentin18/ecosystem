/**
 * @file foods.hpp
 * @brief Header file for Foods class
 */
#pragma once

#include <list>
#include <SFML/Graphics.hpp>

#include "food.hpp"

/**
 * Represent a group of foods
 */
class Foods : public sf::Drawable
{
private:
    std::list<Food> foods;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Foods();
    ~Foods();
    std::list<Food>* getList();
    void init(const unsigned int nbFoods);
};
