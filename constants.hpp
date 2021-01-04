#pragma once

#include <SFML/Graphics.hpp>

// Window
const unsigned int WINDOW_WIDTH = 1600;
const unsigned int WINDOW_HEIGHT = 900;
const char WINDOW_TITLE[] = "Ecosystem";
const unsigned int FRAMERATE_LIMIT = 60;
const std::string FONT_PATH = "ComicRelief.ttf";
const unsigned int TEXT_SIZE = 24;
const sf::Vector2f TEXT_POS(5, 5);

// Animals
const unsigned int NB_RABBITS_START = 30;
const unsigned int NB_FOXES_START = 3;
const float ANIMAL_MIN_RADIUS = 5;
const float ANIMAL_MAX_RADIUS = 10;

// Colors
const sf::Color BG_COLOR(34, 139, 34);
const sf::Color TEXT_COLOR = sf::Color::Black;
const sf::Color ANIMAL_DEFAULT_COLOR = sf::Color::Black;
const sf::Color RABBIT_COLOR(192, 192, 192, 220);
const sf::Color FOX_COLOR(210, 105, 30, 220);
