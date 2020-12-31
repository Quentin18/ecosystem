#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include "animal.hpp"

int main()
{
    // Init window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(FRAMERATE_LIMIT);

    // Nb animals to start
    const int NB_ANIMALS = 30;

    // Init animals
    Animal* animals = new Animal[NB_ANIMALS];

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
        // Draw Animals
        for (size_t i = 0; i < NB_ANIMALS; i++)
        {
            animals[i].update();
            window.draw(animals[i]);
        }        
        window.display();
    }

    delete[] animals;

    return 0;
}
