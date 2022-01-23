#include <ctime>
#include <memory>
#include <cmath>
#include <numeric>
#include <cmath>
#include <iostream>
#include <string>
#include <memory>

#include "ZoomList.hpp"
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
	time_t start = clock();

	const string fileName { "allBlack.bmp" };

	Bitmap bitmap(WIDTH, HEIGHT);

	ZoomList zoomList(WIDTH, HEIGHT);
	zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 4.0 / WIDTH));
	zoomList.add(Zoom(295, HEIGHT - 202, 0.1));
	zoomList.add(Zoom(312, HEIGHT - 304, 0.1));

	// INITIATE TO VALUES 
	double min {  999999 };
	double max { -999999 };

	unique_ptr<int[]> histogram { new int[Mandelbrot::MAX_ITERATIONS + 1]{} };
	unique_ptr<int[]> fractal   { new int[WIDTH * HEIGHT]{} };
	
	for (int x{0}; x<WIDTH; ++x) {
		for (int y{0}; y<HEIGHT; ++y) {
			pair<double, double> xy = zoomList.doZoom(x, y);
			double xFractal = xy.first;
			double yFractal = xy.second;
			//double xFractal = (x - (double)WIDTH  / 2 - 200 ) * 2. / HEIGHT;
			//double yFractal = (y - (double)HEIGHT / 2) * 2.0 / HEIGHT;

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

			uint8_t red{};
			uint8_t green{};
			uint8_t blue{};

			if (iterations != Mandelbrot::MAX_ITERATIONS) {

				double hue {};

				for (int i{}; i<=iterations; ++i)
					hue += ((double)histogram[i]) / total;

				green = pow(255, hue);
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
