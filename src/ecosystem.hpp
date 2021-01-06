#pragma once

#include <list>
#include <SFML/Graphics.hpp>

#include "food.hpp"
#include "rabbit.hpp"
#include "fox.hpp"
#include "plot.hpp"

class Ecosystem
{
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text text;
    sf::Clock clock;
    std::list<Rabbit> rabbits;
    std::list<Fox> foxes;
    std::list<Food> foods;
    float timer;
    float timeSpeed;
    bool paused;
    bool showStats;
    void initText();
    void initAnimals(const unsigned int nbRabbits, const unsigned int nbFoxes);
    void initFoods(const unsigned int nbFoods);
    void update();
    void drawText();
    void drawAnimals();
    void drawFoods();
    void redraw();
    Plot plot;
public:
    Ecosystem();
    ~Ecosystem();
    void run();
};
