#pragma once

#include <SFML/Graphics.hpp>

class Animal : public sf::CircleShape
{
private:
    float radius;
    float x, y;
    float tx, ty;   // time variables
    float hp;   // health points
    static float map(float value, float start1, float stop1, float start2, float stop2);
public:
    Animal();
    ~Animal();
    void move();
    bool isDead() const;
    void resetHp();
    static float distance(const sf::Vector2f a, const sf::Vector2f b);
};
