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
}

Ecosystem::~Ecosystem() {}

void Ecosystem::run()
{
    // Define stringstream for text
    std::stringstream ss;

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
        // Draw rabbits
        for (int i = 0; i < nb_rabbits; i++)
        {
            rabbits[i].update();
            window.draw(rabbits[i]);
        }
        // Draw foxes
        for (int i = 0; i < nb_foxes; i++)
        {
            foxes[i].update();
            window.draw(foxes[i]);
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
