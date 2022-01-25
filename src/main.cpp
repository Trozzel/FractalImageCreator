#include <ctime>
#include <memory>
#include <cmath>
#include <numeric>
#include <cmath>
#include <iostream>
#include <string>
#include <memory>

#include "FractalCreator.hpp"

using namespace std;

const     string baseDir { "../images/" };
constexpr int _width { 800 }, _height { 600 };

int main()
{
	time_t start = clock();

	FractalCreator fractalCreator(800, 600);

	const string fileName { "allBlack.bmp" };

	fractalCreator.addZoom(Zoom(295, _height - 202, 0.1));
	fractalCreator.addZoom(Zoom(312, _height - 304, 0.1));
	fractalCreator.calculateIteration();
	fractalCreator.calculateTotalIterations();
	fractalCreator.drawFractal();

	// INITIATE TO VALUES 
	double min {  999999 };
	double max { -999999 };


	fractalCreator.writeBitmap(baseDir + fileName);

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
