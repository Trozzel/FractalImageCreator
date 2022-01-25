#include <numeric>

#include "FractalCreator.hpp"

using namespace std;

// CTOR
/******************************************************************************/
FractalCreator::FractalCreator(int width, int height) : 
	_width(width), _height(height), 
	_histogram{ new int[Mandelbrot::MAX_ITERATIONS + 1]{} },
	_fractal  { new int[_width * _height]{} },
	_bitmap   {_width, _height },
	_zoomList {_width, _height }
{
	addZoom(Zoom(_width/2, _height/2, 4.0 / _width));
}

// DTOR
/******************************************************************************/
FractalCreator::~FractalCreator()
{
}

// CALCULATE ITERATION
/******************************************************************************/
void FractalCreator::calculateIteration()
{
	for (int x{0}; x<_width; ++x) {
		for (int y{0}; y<_height; ++y) {
			pair<double, double> xy = _zoomList.doZoom(x, y);
			double xFractal = xy.first;
			double yFractal = xy.second;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			if (iterations != Mandelbrot::MAX_ITERATIONS)
				++_histogram[iterations];

			//pixelInfoHist[y * WIDTH + x] = PixelInfo(x, y, iterations);
			_fractal[y * _width + x] = iterations;
		}
	}

}

// DRAW FRACTAL
void FractalCreator::drawFractal()
/******************************************************************************/
{
	for (int x{0}; x<_width; ++x) {
		for (int y{0}; y<_height; ++y) {

			int iterations = _fractal[y * _width + x];

			uint8_t red{};
			uint8_t green{};
			uint8_t blue{};

			if (iterations != Mandelbrot::MAX_ITERATIONS) {

				double hue {};

				for (int i{}; i<=iterations; ++i)
					hue += ((double)_histogram[i]) / _total;

				green = hue * 255;
			}
			
			_bitmap.setPixel(x, y, red, green, blue);
		}
	}

}

// CALCULATE TOTAL ITERATIONS
/******************************************************************************/
void FractalCreator::calculateTotalIterations()
{
	_total = accumulate(&_histogram[0], &_histogram[Mandelbrot::MAX_ITERATIONS],
			0,
			[](int pInt1, int pInt2) -> int {
				return pInt1 + pInt2;
			});

}
// ADD ZOOM
/******************************************************************************/
void FractalCreator::addZoom(const Zoom& zoom)
{
	_zoomList.add(zoom);
}

// WRITE BITMAP
/******************************************************************************/
void FractalCreator::writeBitmap(const std::string& name)
{
	_bitmap.write(name);
}
