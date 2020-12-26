#pragma once

#include <SFML/Graphics.hpp>

class Cell : public sf::CircleShape
{
private:
    float radius;
    float speed;
    float x;
    float y;
public:
    Cell();
    ~Cell();
    void update();
};
