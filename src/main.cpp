#include <memory>
#include <numeric>
#include <cmath>
#include <iostream>
#include <string>
#include <memory>

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

	unique_ptr<int[]> histogram { new int[Mandelbrot::MAX_ITERATIONS + 1]{} };
	unique_ptr<int[]> fractal   { new int[WIDTH * HEIGHT]{} };
	
	for (int x{0}; x<WIDTH; ++x) {
		for (int y{0}; y<HEIGHT; ++y) {
			double xFractal = (x - (double)WIDTH  / 2 - 200 ) * 2. / HEIGHT;
			double yFractal = (y - (double)HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			if (iterations != Mandelbrot::MAX_ITERATIONS)
				++histogram[iterations];

			//pixelInfoHist[y * WIDTH + x] = PixelInfo(x, y, iterations);
			fractal[y * WIDTH + x] = iterations;
		}
	}

//	for (int i{}; i<Mandelbrot::MAX_ITERATIONS; ++i) cout << setw(4) << i << ".) " << histogram[i] << endl;
//
	int total = accumulate(&histogram[0], &histogram[Mandelbrot::MAX_ITERATIONS],
			0, [](int pInt1, int pInt2) -> int {
				return pInt1 + pInt2;
			});

	for (int x{0}; x<WIDTH; ++x) {
		for (int y{0}; y<HEIGHT; ++y) {

			int iterations = fractal[y * WIDTH + x];

			//uint8_t color {static_cast<uint8_t>(
			//		256 * static_cast<double>(numIter) / Mandelbrot::MAX_ITERATIONS)};

			double hue {};

			for (int i{}; i<=iterations; ++i)
				hue += ((double)histogram[i]) / total;

			uint8_t red{};
			uint8_t green = hue * 255;
			uint8_t blue{};
			
			bitmap.setPixel(x, y, red, green, blue);
		}
	}


	bitmap.write(baseDir + fileName);

	#if defined __APPLE__
		system("open ../images/allBlack.bmp");
	#elif defined __linux__
		system("mimeopen ../images/allBlack.bmp");
	#endif

	cout << "Finished." << endl;
}
