/**
 * @file plot.cpp
 * @brief Source code for Plot class
 */
#include "plot.hpp"

/**
 * Plot constructor
 */
Plot::Plot()
{
    imageReference = CreateRGBABitmapImageReference();
}

/**
 * Plot destructor
 */
Plot::~Plot()
{
    DeleteImage(imageReference->image);
}

/**
 * Update the vectors of the Plot object
 * 
 * @param time time to add
 * @param nbRabbits number of rabbits to add
 * @param nbFoxes number of foxes to add
 */
void Plot::update(const double time, const double nbRabbits, const double nbFoxes)
{
    timeVect.push_back(time);
    rabbitsVect.push_back(nbRabbits);
    foxesVect.push_back(nbFoxes);
}

/**
 * Save the scatter plot to PNG files
 * 
 * @param width width of the scatter plot
 * @param height height of the scatter plot
 */
void Plot::savePNG(const double width, const double height)
{
    std::vector<double> *pngdata;
    DrawScatterPlot(imageReference, width, height, &timeVect, &rabbitsVect);
	pngdata = ConvertToPNG(imageReference->image);
	WriteToFile(pngdata, "rabbitsPlot.png");
    DrawScatterPlot(imageReference, width, height, &timeVect, &foxesVect);
	pngdata = ConvertToPNG(imageReference->image);
	WriteToFile(pngdata, "foxesPlot.png");
}
