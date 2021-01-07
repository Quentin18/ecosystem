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
 * Init animals
 * 
 * @param nbRabbits number of rabbits
 * @param nbFoxes number of foxes
 */
void Ecosystem::initAnimals(const unsigned int nbRabbits, const unsigned int nbFoxes)
{
    rabbits.clear();
    for (unsigned int i = 0; i < nbRabbits; i++)
    {
        rabbits.emplace_back();
    }
    foxes.clear();
    for (unsigned int i = 0; i < nbFoxes; i++)
    {
        foxes.emplace_back();
    }
}

/**
 * Init foods
 * 
 * @param nbFoods number of foods
 */
void Ecosystem::initFoods(const unsigned int nbFoods)
{
    foods.clear();
    for (unsigned int i = 0; i < nbFoods; i++)
    {
        foods.emplace_back();
    }
}

/**
 * Ecosystem constructor
 */
Ecosystem::Ecosystem() :
    timer(0.0f),
    timeSpeed(1.0f),
    nbFoodsEaten(0),
    nbRabbitsKilled(0),
    nbRabbitsBirths(0),
    nbFoxesBirths(0),
    paused(false),
    finished(true),
    showStats(true),
    showPlot(false)
{
    initText();
}

/**
 * Ecosystem destructor
 */
Ecosystem::~Ecosystem() {}

void Ecosystem::update()
{
    unsigned int nbNewRabbits = 0;
    unsigned int nbNewFoxes = 0;
    // Update rabbits
    for (std::list<Rabbit>::iterator it = rabbits.begin(); it != rabbits.end(); ++it)
    {
        it->move(timeSpeed);
        nbFoodsEaten += it->eat(foods);
        if (it->isDead())
        {
            // Remove rabbit
            it = rabbits.erase(it);
        }
        else {
            // Reproduce
            for (std::list<Rabbit>::iterator it2 = it; it2 != rabbits.end(); ++it2)
            {
                if ((it2 != it) && it->reproduce(*it2))
                {
                    nbNewRabbits++;
                    break;
                }
            }
        }
    }
    nbRabbitsBirths += nbNewRabbits;
    // Create new rabbits
    for (unsigned int i = 0; i < nbNewRabbits; i++)
    {
        rabbits.emplace_back();
    }
    // Update foxes
    for (std::list<Fox>::iterator it = foxes.begin(); it != foxes.end(); ++it)
    {
        it->move(timeSpeed);
        nbRabbitsKilled += it->eat(rabbits);
        if (it->isDead())
        {
            // Remove fox
            it = foxes.erase(it);
        }
        else {
            // Reproduce
            for (std::list<Fox>::iterator it2 = it; it2 != foxes.end(); ++it2)
            {
                if ((it2 != it) && it->reproduce(*it2))
                {
                    nbNewFoxes++;
                    break;
                }
            }
        }
    }
    nbFoxesBirths += nbNewFoxes;
    // Create new foxes
    for (unsigned int i = 0; i < nbNewFoxes; i++)
    {
        foxes.emplace_back();
    }
    // Update timer
    timer += clock.getElapsedTime().asSeconds() * timeSpeed;
    // Update plot
    plot.update(timer, rabbits.size(), foxes.size());
}

/**
 * Draw the stats
 */
void Ecosystem::drawStats()
{
    std::stringstream ss;
    ss << "Time: " << timer << "\n"
        << "Speed: x" << timeSpeed << "\n"
        << "Rabbits: " << rabbits.size() << "\n"
        << "Foxes: " << foxes.size() << "\n"
        << "Foods eaten: " << nbFoodsEaten << "\n"
        << "Rabbits killed: " << nbRabbitsKilled << "\n"
        << "Rabbits born: " << nbRabbitsBirths << "\n"
        << "Foxes born: " << nbFoxesBirths << "\n";
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
 * Draw animals
 */
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

/**
 * Draw foods
 */
void Ecosystem::drawFoods()
{
    for (std::list<Food>::iterator it = foods.begin(); it != foods.end(); ++it)
    {
        window.draw(*it);
    }
}

/**
 * Draw the scatter plot
 */
void Ecosystem::drawPlot()
{
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile(PLOT_FILENAME);
    sprite.setTexture(texture);
    sprite.setPosition(PLOT_POS);
    window.draw(sprite);
}

/**
 * Redraw the window
 */
void Ecosystem::redraw()
{
    window.clear(BG_COLOR);
    if (!finished)
    {
        drawAnimals();
        drawFoods();
    }
    if (showPlot)
    {
        drawPlot();
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
    initAnimals(NB_RABBITS_START, NB_FOXES_START);
    initFoods(NB_FOODS);
    plot.reset();
    finished = false;
    showPlot = false;
    nbFoodsEaten = 0;
    nbRabbitsKilled = 0;
    nbRabbitsBirths = 0;
    nbFoxesBirths = 0;
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
