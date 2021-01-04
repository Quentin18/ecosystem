#include <iostream>
#include <string>
#include <sstream>

#include "ecosystem.hpp"
#include "constants.hpp"

Ecosystem::Ecosystem() : nb_rabbits(NB_RABBITS_START), nb_foxes(NB_FOXES_START)
{
    // Init font
    if (!font.loadFromFile(FONT_PATH))
    {
        std::cerr << "Error: can't load " << FONT_PATH << std::endl;
        exit(EXIT_FAILURE);
    }

    // Init text
    text.setFont(font);
    text.setCharacterSize(TEXT_SIZE);
    text.setFillColor(TEXT_COLOR);
    text.setPosition(TEXT_POS);

    // Create animals
    for (int i = 0; i < nb_rabbits; i++)
    {
        rabbits.emplace_back();
    }
    for (int i = 0; i < nb_foxes; i++)
    {
        foxes.emplace_back();
    }
    // Create foods
    for (unsigned int i = 0; i < NB_FOODS; i++)
    {
        foods.emplace_back();
    }
}

Ecosystem::~Ecosystem() {}

void Ecosystem::run()
{
    // Define stringstream for text
    std::stringstream ss;
    // Define iterators
    std::vector<Rabbit>::iterator it_rabbits;
    std::vector<Fox>::iterator it_foxes;
    std::vector<Food>::iterator it_foods;

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

        window.clear(BG_COLOR);
        // Update and draw rabbits
        it_rabbits = rabbits.begin();
        while (it_rabbits != rabbits.end())
        {
            it_rabbits->update();
            if (!it_rabbits->is_dead())
            {
                window.draw(*it_rabbits);
                it_rabbits++;
            }
            else
            {
                // Remove rabbit
                rabbits.erase(it_rabbits);
                nb_rabbits--;
            }   
        }
        // Update and draw foxes
        it_foxes = foxes.begin();
        while (it_foxes != foxes.end())
        {
            it_foxes->update();
            if (!it_foxes->is_dead())
            {
                window.draw(*it_foxes);
                it_foxes++;
            }
            else
            {
                // Remove fox
                foxes.erase(it_foxes);
                nb_foxes--;
            }   
        }
        // Draw foods
        for (it_foods = foods.begin(); it_foods < foods.end(); ++it_foods)
        {
            window.draw(*it_foods);
        }
        // Draw text
        ss.str("");
        ss.clear();
        ss << "Time: " << clock.getElapsedTime().asSeconds() << "\n"
           << "Rabbits: " << nb_rabbits << "\n"
           << "Foxes: " << nb_foxes << "\n";
        text.setString(ss.str());
        window.draw(text);
        window.display();
    }
}
