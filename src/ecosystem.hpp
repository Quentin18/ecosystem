/**
 * @file ecosystem.hpp
 * @brief Header file for Ecosystem class
 */
#pragma once

#include <list>
#include <SFML/Graphics.hpp>

#include "food.hpp"
#include "rabbit.hpp"
#include "fox.hpp"
#include "animals.hpp"
#include "plot.hpp"

/**
 * Manage an ecosystem simulation
 */
class Ecosystem
{
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text statsText;
    sf::Text commandsText;
    sf::Clock clock;
    std::list<Food> foods;
    Animals<Rabbit> rabbits;
    Animals<Fox> foxes;
    Plot plot;
    float timer;
    float timeSpeed;
    bool paused;
    bool finished;
    bool showStats;
    bool showPlot;
    void initText();
    void initFoods(const unsigned int nbFoods);
    void update();
    void drawStats();
    void drawCommands();
    void drawFoods();
    void drawPlot();
    void redraw();
    void restart();
public:
    Ecosystem();
    ~Ecosystem();
    void run();
};
