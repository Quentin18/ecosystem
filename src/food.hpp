/**
 * @file food.hpp
 * @brief Header file for Food class
 */
#pragma once

#include <SFML/Graphics.hpp>

/**
 * Represent a food object
 */
class Food : public sf::CircleShape
{
public:
    Food();
    ~Food();
    void move();
};
