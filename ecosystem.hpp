#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "rabbit.hpp"
#include "fox.hpp"
#include "food.hpp"

class Ecosystem
{
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;
    sf::Clock clock;
    std::vector<Rabbit> rabbits;
    std::vector<Fox> foxes;
    std::vector<Food> foods;
    int nb_rabbits;
    int nb_foxes;
    int nb_foods;
    void initText();
    void initAnimals();
    void initFoods();
    void drawText();
    void drawAnimals();
    void drawFoods();
    void redraw();
public:
    Ecosystem();
    ~Ecosystem();
    void run();
};
