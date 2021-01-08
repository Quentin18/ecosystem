/**
 * @file plot.hpp
 * @brief Header file for Plot class
 */
#pragma once

#include <SFML/Graphics.hpp>

#include "pbPlots/pbPlots.hpp"
#include "pbPlots/supportLib.hpp"

/**
 * Manage plots using the pbPlots library
 */
class Plot : public sf::Drawable
{
private:
    RGBABitmapImageReference *imageReference;
    ScatterPlotSeries *seriesRabbits;
    ScatterPlotSeries *seriesFoxes;
    ScatterPlotSettings *settings;
    std::vector<double> timeVect;
    std::vector<double> rabbitsVect;
    std::vector<double> foxesVect;
    std::vector<double> *pngdata;
    void initRabbitsSeries();
    void initFoxesSeries();
    void initSettings();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Plot();
    ~Plot();
    void update(const double time, const double nbRabbits, const double nbFoxes);
    void savePNG();
    void reset();
};
