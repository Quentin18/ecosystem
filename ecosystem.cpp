#include "ecosystem.hpp"
#include "constants.hpp"

Ecosystem::Ecosystem() : nb_rabbits(NB_RABBITS_START), nb_foxes(NB_FOXES_START)
{
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
        window.display();
    }
}
