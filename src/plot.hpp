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
    std::vector<double> timeVect;
    std::vector<double> rabbitsVect;
    std::vector<double> foxesVect;
public:
    Plot();
    ~Plot();
    void update(const double time, const double nbRabbits, const double nbFoxes);
    void savePNG(const double width, const double height);
};
