/**
 * @file plot.hpp
 * @brief Header file for Plot class
 */
#pragma once

#include "pbPlots/pbPlots.hpp"
#include "pbPlots/supportLib.hpp"

/**
 * Manage plots using the pbPlots library
 */
class Plot
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
public:
    Plot();
    ~Plot();
    void update(const double time, const double nbRabbits, const double nbFoxes);
    void savePNG();
    void reset();
};
