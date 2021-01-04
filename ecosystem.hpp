#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "rabbit.hpp"
#include "fox.hpp"

class Ecosystem
{
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text animals_text;
    std::vector<Rabbit> rabbits;
    std::vector<Fox> foxes;
    int nb_rabbits;
    int nb_foxes;
public:
    Ecosystem();
    ~Ecosystem();
    void run();
};
