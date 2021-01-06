#include "plot.hpp"

Plot::Plot()
{
    imageReference = CreateRGBABitmapImageReference();
}

Plot::~Plot()
{
    DeleteImage(imageReference->image);
}

void Plot::update(const double time, const double nbRabbits, const double nbFoxes)
{
    timeVect.push_back(time);
    rabbitsVect.push_back(nbRabbits);
    foxesVect.push_back(nbFoxes);
}

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
