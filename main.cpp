#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include "cell.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    // Init a cell
    Cell c;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // Draw cell
        window.draw(c);
        window.display();
    }

    return 0;
}
