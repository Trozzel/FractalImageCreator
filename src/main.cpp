#include <memory>
#include <numeric>
#include <cmath>
#include <iostream>
#include <string>

#include "Mandelbrot.hpp"
#include "PixelInfo.hpp"
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace std;

const     string baseDir { "../images/" };
constexpr int WIDTH { 800 }, HEIGHT { 600 };

int main()
{
	const string fileName { "allBlack.bmp" };

	Bitmap bitmap(WIDTH, HEIGHT);

	// INITIATE TO VALUES 
	double min {  999999 };
	double max { -999999 };

	int histogram[Mandelbrot::MAX_ITERATIONS + 1]{};
	PixelInfo pixelInfoHist[WIDTH * HEIGHT]{};
	
	for (int x{0}; x<WIDTH; ++x) {
		for (int y{0}; y<HEIGHT; ++y) {
			double xFractal = (x - static_cast<double>(WIDTH+250)  / 2) * 2./HEIGHT;
			double yFractal = (y - static_cast<double>(HEIGHT) / 2) * 2./HEIGHT;

			int numIter = Mandelbrot::getIterations(xFractal, yFractal);
			if (numIter != Mandelbrot::MAX_ITERATIONS)
				++histogram[numIter];

			pixelInfoHist[y * WIDTH + x] = PixelInfo(x, y, numIter);

		}
	}

	for (int i{}; i<Mandelbrot::MAX_ITERATIONS; ++i)
		cout << setw(4) << i << ".) " << histogram[i] << endl;

	int total = accumulate(&histogram[0], &histogram[Mandelbrot::MAX_ITERATIONS],
			0, [](int pInt1, int pInt2) -> int {
				return pInt1 + pInt2;
			});

	for (int x{0}; x<WIDTH; ++x) {
		for (int y{0}; y<HEIGHT; ++y) {

			int numIter = pixelInfoHist[y * WIDTH + x].numIterations;

			//uint8_t color {static_cast<uint8_t>(
			//		256 * static_cast<double>(numIter) / Mandelbrot::MAX_ITERATIONS)};

			double hue {};

			for (int i{}; i<=numIter; ++i)
				hue += (double)(pixelInfoHist[i].numIterations) / total;

			uint8_t red{};
			uint8_t green = (uint8_t)hue * 255;
			uint8_t blue{};


			bitmap.setPixel(x, y, red, blue, green);
		}
	}


	bitmap.write(baseDir + fileName);

	system("open ../images/allBlack.bmp");

	cout << "Finished." << endl;
}
