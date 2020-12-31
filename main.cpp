#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include "rabbit.hpp"
#include "fox.hpp"

int main()
{
    // Init window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(FRAMERATE_LIMIT);

    // Nb rabbits and foxes to start
    const int NB_RABBITS = 30;
    const int NB_FOXES = 3;

    // Init animals
    Rabbit* rabbits = new Rabbit[NB_RABBITS];
    Fox* foxes = new Fox[NB_FOXES];

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
        for (size_t i = 0; i < NB_RABBITS; i++)
        {
            rabbits[i].update();
            window.draw(rabbits[i]);
        }
        // Draw foxes
        for (size_t i = 0; i < NB_FOXES; i++)
        {
            foxes[i].update();
            window.draw(foxes[i]);
        }
        window.display();
    }

    delete[] rabbits;
    delete[] foxes;

    return 0;
}
