/**
 * @file constants.hpp
 * @brief Header file containing the settings of the simulation
 */
#pragma once

#include <SFML/Graphics.hpp>

// Window
const unsigned int WINDOW_WIDTH = 1600;
const unsigned int WINDOW_HEIGHT = 900;
const char WINDOW_TITLE[] = "Ecosystem";
const unsigned int FRAMERATE_LIMIT = 50;
const std::string FONT_PATH = "ComicRelief.ttf";
const unsigned int TEXT_SIZE = 24;
const sf::Vector2f STATS_POS(5, 5);
const sf::Vector2f COMMANDS_POS(5, WINDOW_HEIGHT - 180);
const float CIRCLE_THICKNESS = 1;

// Animals
const unsigned int NB_RABBITS_START = 30;
const unsigned int NB_FOXES_START = 3;
const float RABBIT_RADIUS = 8;
const float FOXES_RADIUS = 12;
const float ANIMAL_DEFAULT_RADIUS = 10;
const unsigned int ANIMAL_MAX_HP = 1000;

// Food
const unsigned int NB_FOODS = 10;
const unsigned int FOOD_RADIUS = 4;

// Colors
const sf::Color BG_COLOR(34, 139, 34);
const sf::Color TEXT_COLOR = sf::Color::Black;
const sf::Color ANIMAL_DEFAULT_COLOR = sf::Color::Black;
const sf::Color RABBIT_COLOR(192, 192, 192, 220);
const sf::Color FOX_COLOR(210, 105, 30, 220);
const sf::Color FOOD_COLOR(255, 165, 0);
const sf::Color CIRCLE_OUTLINE_COLOR = sf::Color::Black;

// Plot
const double PLOT_WIDTH = 900;
const double PLOT_HEIGHT = 600;
const std::string PLOT_FILENAME = "results.png";
const sf::Vector2f PLOT_POS((WINDOW_WIDTH / 2.0) - (PLOT_WIDTH / 2.0), (WINDOW_HEIGHT / 2.0) - (PLOT_HEIGHT / 2.0));
