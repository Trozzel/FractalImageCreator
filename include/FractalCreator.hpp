#ifndef __FRACTALCREATOR_HPP__
#define __FRACTALCREATOR_HPP__

#include <string>
#include <memory>

#include "ZoomList.hpp"
#include "Mandelbrot.hpp"
#include "Bitmap.h"

class FractalCreator
{
private:
	int _width;
	int _height;

	int _total { 0 };

	std::unique_ptr<int[]> _histogram;
	std::unique_ptr<int[]> _fractal;  
	Bitmap                 _bitmap;
	ZoomList               _zoomList;

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void calculateTotalIterations();
	void drawFractal();
	void addZoom(const Zoom& zoom);
	void writeBitmap(const std::string& name);
};

#endif // __FRACTALCREATOR_HPP__

