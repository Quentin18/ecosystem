#include <iostream>
#include <string>

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
    animals_text.setFont(font);
    animals_text.setCharacterSize(TEXT_SIZE);
    animals_text.setFillColor(TEXT_COLOR);
    animals_text.setPosition(TEXT_POS);
    
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
        animals_text.setString(
            "Rabbits: " + std::to_string(nb_rabbits) +
            "\nFoxes: " + std::to_string(nb_foxes)
        );
        window.draw(animals_text);
        window.display();
    }
}
