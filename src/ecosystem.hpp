/**
 * @file ecosystem.hpp
 * @brief Header file for Ecosystem class
 */
#pragma once

#include <list>
#include <SFML/Graphics.hpp>

#include "rabbit.hpp"
#include "fox.hpp"
#include "animals.hpp"
#include "foods.hpp"
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
    Animals<Rabbit> rabbits;
    Animals<Fox> foxes;
    Foods foods;
    Plot plot;
    float timer;
    float timeSpeed;
    bool paused;
    bool finished;
    bool showStats;
    bool showPlot;
    void initText();
    void update();
    void drawStats();
    void drawCommands();
    void redraw();
    void restart();
public:
    Ecosystem();
    ~Ecosystem();
    void run();
};
