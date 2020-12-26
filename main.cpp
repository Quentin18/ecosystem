#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include "cell.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    const int NB_CELLS = 30;

    // Init cells
    Cell* cells = new Cell[NB_CELLS];

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // Draw cells
        for (size_t i = 0; i < NB_CELLS; i++)
        {
            window.draw(cells[i]);
        }        
        window.display();
    }

    delete[] cells;

    return 0;
}
