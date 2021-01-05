#include <iostream>
#include <string>
#include <sstream>

#include "ecosystem.hpp"
#include "constants.hpp"

void Ecosystem::initText()
{
    if (!font.loadFromFile(FONT_PATH))
    {
        std::cerr << "Error: can't load " << FONT_PATH << std::endl;
        exit(EXIT_FAILURE);
    }
    text.setFont(font);
    text.setCharacterSize(TEXT_SIZE);
    text.setFillColor(TEXT_COLOR);
    text.setPosition(TEXT_POS);
}

void Ecosystem::initAnimals(const unsigned int nbRabbits, const unsigned int nbFoxes)
{
    for (unsigned int i = 0; i < nbRabbits; i++)
    {
        rabbits.emplace_back();
    }
    for (unsigned int i = 0; i < nbFoxes; i++)
    {
        foxes.emplace_back();
    }
}

void Ecosystem::initFoods(const unsigned int nbFoods)
{
    for (unsigned int i = 0; i < nbFoods; i++)
    {
        foods.emplace_back();
    }
}

Ecosystem::Ecosystem()
{
    initText();
    initAnimals(NB_RABBITS_START, NB_FOXES_START);
    initFoods(NB_FOODS);
}

Ecosystem::~Ecosystem() {}

void Ecosystem::drawText()
{
    std::stringstream ss;
    ss << "Time: " << clock.getElapsedTime().asSeconds() << "\n"
        << "Rabbits: " << rabbits.size() << "\n"
        << "Foxes: " << foxes.size() << "\n";
    text.setString(ss.str());
    window.draw(text);
}

void Ecosystem::drawAnimals()
{
    // Update and draw rabbits
    for (std::list<Rabbit>::iterator it = rabbits.begin(); it != rabbits.end(); ++it)
    {
        it->update();
        if (it->is_dead())
        {
            // Remove rabbit
            it = rabbits.erase(it);
        }
        else
        {
            // Draw rabbit
            window.draw(*it);
        }
    }
    // Update and draw foxes 
    for (std::list<Fox>::iterator it = foxes.begin(); it != foxes.end(); ++it)
    {
        it->update();
        if (it->is_dead())
        {
            // Remove fox
            it = foxes.erase(it);
        }
        else
        {
            // Draw fox
            window.draw(*it);
        }
    }
}

void Ecosystem::drawFoods()
{
    for (std::list<Food>::iterator it = foods.begin(); it != foods.end(); ++it)
    {
        window.draw(*it);
    }
}

void Ecosystem::redraw()
{
    window.clear(BG_COLOR);
    drawAnimals();
    drawFoods();
    drawText();
    window.display();
}

void Ecosystem::run()
{
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(FRAMERATE_LIMIT);

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    redraw();
    }
}
