#include <ctime>
#include <memory>
#include <cmath>
#include <numeric>
#include <cmath>
#include <iostream>
#include <string>
#include <memory>

#include "ZoomList.hpp"
#include "FractalCreator.hpp"
#include "Mandelbrot.hpp"
#include "PixelInfo.hpp"
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace std;

const     string baseDir { "../images/" };
constexpr int _width { 800 }, _height { 600 };

int main()
{
	time_t start = clock();


	FractalCreator fractalCreator(800, 600);

	const string fileName { "allBlack.bmp" };

	Bitmap bitmap(_width, _height);

	ZoomList _zoomList(_width, _height);
	_zoomList.add(Zoom(_width/2, _height/2, 4.0 / _width));
	_zoomList.add(Zoom(295, _height - 202, 0.1));
	_zoomList.add(Zoom(312, _height - 304, 0.1));

	// INITIATE TO VALUES 
	double min {  999999 };
	double max { -999999 };

	unique_ptr<int[]> histogram { new int[Mandelbrot::MAX_ITERATIONS + 1]{} };
	unique_ptr<int[]> fractal   { new int[_width * _height]{} };
	
	for (int x{0}; x<_width; ++x) {
		for (int y{0}; y<_height; ++y) {
			pair<double, double> xy = _zoomList.doZoom(x, y);
			double xFractal = xy.first;
			double yFractal = xy.second;
			//double xFractal = (x - (double)WIDTH  / 2 - 200 ) * 2. / HEIGHT;
			//double yFractal = (y - (double)HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			if (iterations != Mandelbrot::MAX_ITERATIONS)
				++histogram[iterations];

			//pixelInfoHist[y * WIDTH + x] = PixelInfo(x, y, iterations);
			fractal[y * _width + x] = iterations;
		}
	}

	int total = accumulate(&histogram[0], &histogram[Mandelbrot::MAX_ITERATIONS],
			0, [](int pInt1, int pInt2) -> int {
				return pInt1 + pInt2;
			});

	for (int x{0}; x<_width; ++x) {
		for (int y{0}; y<_height; ++y) {

			int iterations = fractal[y * _width + x];

			uint8_t red{};
			uint8_t green{};
			uint8_t blue{};

			if (iterations != Mandelbrot::MAX_ITERATIONS) {

				double hue {};

				for (int i{}; i<=iterations; ++i)
					hue += ((double)histogram[i]) / total;

				green = hue * 255;
			}
			
			bitmap.setPixel(x, y, red, green, blue);
		}
	}


	bitmap.write(baseDir + fileName);

	string openImgCmd {};

	#if defined __APPLE__
		openImgCmd = "open ../images/allBlack.bmp";
	#elif defined __linux__
		openImgCmd = "mimeopen ../images/allBlack.bmp";
	#endif

	time_t finish = clock();
	time_t total_time = (finish - start);
	cout << "Elapsed time: " << (double)total_time / CLOCKS_PER_SEC << endl;

	system(openImgCmd.c_str());

	//cout << "Finished." << endl;
}
