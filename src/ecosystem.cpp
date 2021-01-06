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

Ecosystem::Ecosystem() : timer(0.0f), timeSpeed(1.0f), paused(false), showStats(true)
{
    initText();
    initAnimals(NB_RABBITS_START, NB_FOXES_START);
    initFoods(NB_FOODS);
}

Ecosystem::~Ecosystem() {}

void Ecosystem::update()
{
    // Update rabbits
    for (std::list<Rabbit>::iterator it = rabbits.begin(); it != rabbits.end(); ++it)
    {
        it->move(timeSpeed);
        it->eat(foods);
        if (it->isDead())
        {
            // Remove rabbit
            it = rabbits.erase(it);
        }
    }
    // Update foxes
    for (std::list<Fox>::iterator it = foxes.begin(); it != foxes.end(); ++it)
    {
        it->move(timeSpeed);
        it->eat(rabbits);
        if (it->isDead())
        {
            // Remove fox
            it = foxes.erase(it);
        }
    }
    // Update timer
    timer += clock.getElapsedTime().asSeconds() * timeSpeed;

    // TODO to complete
}

void Ecosystem::drawText()
{
    std::stringstream ss;
    ss << "Time: " << timer << "\n"
        << "Rabbits: " << rabbits.size() << "\n"
        << "Foxes: " << foxes.size() << "\n";
    text.setString(ss.str());
    window.draw(text);
}

void Ecosystem::drawAnimals()
{
    // Draw rabbits
    for (std::list<Rabbit>::iterator it = rabbits.begin(); it != rabbits.end(); ++it)
    {
        window.draw(*it);
    }
    // Draw foxes
    for (std::list<Fox>::iterator it = foxes.begin(); it != foxes.end(); ++it)
    {
        window.draw(*it);
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
    if (showStats)
    {
        drawText();
    }
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
            switch (event.type)
            {
                // Window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // Key pressed
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        // Pause
                        case sf::Keyboard::Space:
                            paused = !paused;
                            break;
                        // Stats
                        case sf::Keyboard::S:
                            showStats = !showStats;
                            break;
                        // Accelerate time
                        case sf::Keyboard::Right:
                            timeSpeed *= 2;
                            break;
                        // Slow down time
                        case sf::Keyboard::Left:
                            timeSpeed /= 2;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        if (!paused)
        {
            update();
        }
        clock.restart();
        redraw();
    }
}
