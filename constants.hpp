#pragma once

#include <SFML/Graphics.hpp>

// Window
const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;
const char WINDOW_TITLE[] = "Ecosystem";
const int FRAMERATE_LIMIT = 60;

// Animals
const int NB_RABBITS_START = 30;
const int NB_FOXES_START = 3;
const float ANIMAL_MIN_RADIUS = 5;
const float ANIMAL_MAX_RADIUS = 10;

// Colors
const sf::Color BG_COLOR(34, 139, 34);
const sf::Color ANIMAL_DEFAULT_COLOR = sf::Color::Black;
const sf::Color RABBIT_COLOR(192, 192, 192, 220);
const sf::Color FOX_COLOR(210, 105, 30, 220);
