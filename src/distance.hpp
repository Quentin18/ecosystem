#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

float distance(const sf::Vector2f a, const sf::Vector2f b)
{
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}
