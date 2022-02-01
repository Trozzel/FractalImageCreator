#ifndef __FRACTALCREATOR_HPP__
#define __FRACTALCREATOR_HPP__

#include <string>
#include <memory>

#include "ZoomList.hpp"
#include "Mandelbrot.hpp"
#include "Bitmap.h"
#include "Rgb.hpp"

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

private:

	void calculateIteration();
	void calculateTotalIterations();
	void drawFractal();

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator() = default;

	void addZoom(const Zoom& zoom);
	void writeBitmap(const std::string& name);

	void run(const std::string& name);
};

#endif // __FRACTALCREATOR_HPP__

