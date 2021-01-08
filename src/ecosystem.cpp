/**
 * @file ecosystem.cpp
 * @brief Source code for Ecosystem class
 */
#include <iostream>
#include <string>
#include <sstream>

#include "ecosystem.hpp"
#include "constants.hpp"

/**
 * Init Text objects
 */
void Ecosystem::initText()
{
    // Load font
    if (!font.loadFromFile(FONT_PATH))
    {
        std::cerr << "Error: can't load " << FONT_PATH << std::endl;
        exit(EXIT_FAILURE);
    }
    // Init stats text
    statsText.setFont(font);
    statsText.setCharacterSize(TEXT_SIZE);
    statsText.setFillColor(TEXT_COLOR);
    statsText.setPosition(STATS_POS);
    // Init commands text
    commandsText.setFont(font);
    commandsText.setCharacterSize(TEXT_SIZE);
    commandsText.setFillColor(TEXT_COLOR);
    commandsText.setPosition(COMMANDS_POS);
}

/**
 * Ecosystem constructor
 */
Ecosystem::Ecosystem() :
    timer(0.0f),
    timeSpeed(1.0f),
    paused(false),
    finished(true),
    showStats(true),
    showPlot(false)
{
    initText();
    rabbits.init(NB_RABBITS_START);
    foxes.init(NB_FOXES_START);
    foods.init(NB_FOODS);
}

/**
 * Ecosystem destructor
 */
Ecosystem::~Ecosystem() {}

/**
 * Update the ecosystem
 */
void Ecosystem::update()
{
    // Update animals
    rabbits.update(*foods.getList(), timeSpeed);
    foxes.update(*rabbits.getList(), timeSpeed);
    // Update timer
    timer += clock.getElapsedTime().asSeconds() * timeSpeed;
    // Update plot
    plot.update(timer, rabbits.getNb(), foxes.getNb());
}

/**
 * Draw the stats
 */
void Ecosystem::drawStats()
{
    std::stringstream ss;
    ss << "Time: " << timer << "\n"
        << "Speed: x" << timeSpeed << "\n"
        << "Rabbits: " << rabbits.getNb() << "\n"
        << "Foxes: " << foxes.getNb() << "\n"
        << "Foods eaten: " << rabbits.getNbEaten() << "\n"
        << "Rabbits killed: " << foxes.getNbEaten() << "\n"
        << "Rabbits born: " << rabbits.getNbBirths() << "\n"
        << "Foxes born: " << foxes.getNbBirths() << "\n";
    if (paused)
    {
        ss << "Paused";
    }
    statsText.setString(ss.str());
    window.draw(statsText);
}

/**
 * Draw the commands
 */
void Ecosystem::drawCommands()
{
    std::stringstream ss;
    ss << "Enter: start\n"
        << "Space: pause\n"
        << "Right arrow: speed up by 2\n"
        << "Left arrow: slow down by 2\n"
        << "S: show/hide stats\n";
    commandsText.setString(ss.str());
    window.draw(commandsText);
}

/**
 * Redraw the window
 */
void Ecosystem::redraw()
{
    window.clear(BG_COLOR);
    if (!finished)
    {
        window.draw(rabbits);
        window.draw(foxes);
        window.draw(foods);
    }
    if (showPlot)
    {
        window.draw(plot);
    }
    if (showStats)
    {
        drawStats();
    }
    drawCommands();
    window.display();
}

/**
 * Restart the simulation
 */
void Ecosystem::restart()
{
    rabbits.init(NB_RABBITS_START);
    foxes.init(NB_FOXES_START);
    foods.init(NB_FOODS);
    plot.reset();
    finished = false;
    showPlot = false;
}

/**
 * Run the ecosystem simulator
 */
void Ecosystem::run()
{
    // Create window
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
                        // Start
                        case sf::Keyboard::Enter:
                            if (finished)
                            {
                                restart();
                            }
                            break;
                        // Pause
                        case sf::Keyboard::Space:
                            paused = !paused;
                            break;
                        // Stats
                        case sf::Keyboard::S:
                            showStats = !showStats;
                            break;
                        // Speed up
                        case sf::Keyboard::Right:
                            timeSpeed *= 2;
                            break;
                        // Slow down
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
        if (!paused && !finished)
        {
            update();
            if (rabbits.empty() && foxes.empty())
            {
                finished = true;
                plot.savePNG();
                showPlot = true;
            }
        }
        clock.restart();
        redraw();
    }
}
