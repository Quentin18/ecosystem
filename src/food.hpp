#pragma once

#include <SFML/Graphics.hpp>

class Food : public sf::CircleShape
{
public:
    Food();
    ~Food();
    void move();
};
