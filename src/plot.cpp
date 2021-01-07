/**
 * @file plot.cpp
 * @brief Source code for Plot class
 */
#include "plot.hpp"
#include "constants.hpp"

/**
 * Plot constructor
 * 
 * @param width width of the scatter plot
 * @param height height of the scatter plot
 */
Plot::Plot()
{
    // Create image reference
    imageReference = CreateRGBABitmapImageReference();

    // Create rabbits series
    seriesRabbits = GetDefaultScatterPlotSeriesSettings();
    seriesRabbits->xs = &timeVect;
    seriesRabbits->ys = &rabbitsVect;
    seriesRabbits->linearInterpolation = true;
    seriesRabbits->lineType = toVector(L"dashed");
    seriesRabbits->lineThickness = 2;
    seriesRabbits->color = GetGray(0.3);

    // Create foxes series
    seriesFoxes = GetDefaultScatterPlotSeriesSettings();
    seriesFoxes->xs = &timeVect;
    seriesFoxes->ys = &foxesVect;
    seriesFoxes->linearInterpolation = true;
    seriesFoxes->lineType = toVector(L"solid");
    seriesFoxes->lineThickness = 2;
    seriesFoxes->color = GetBlack();

    // Create scatter plot settings
    settings = GetDefaultScatterPlotSettings();
    settings->width = PLOT_WIDTH;
    settings->height = PLOT_HEIGHT;
    settings->autoBoundaries = true;
    settings->autoPadding = true;
    settings->title = toVector(L"Results of the simulation");
    settings->xLabel = toVector(L"Time");
    settings->yLabel = toVector(L"Number of animals");
    settings->scatterPlotSeries->push_back(seriesRabbits);
    settings->scatterPlotSeries->push_back(seriesFoxes);
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
 * Save the scatter plot to a PNG file
 */
void Plot::savePNG()
{
    DrawScatterPlotFromSettings(imageReference, settings);
    pngdata = ConvertToPNG(imageReference->image);
	WriteToFile(pngdata, "results.png");
}

/**
 * Reset the data vectors
 */
void Plot::reset()
{
    timeVect.clear();
    rabbitsVect.clear();
    foxesVect.clear();
}
