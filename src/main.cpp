#include <ctime>
#include <memory>
#include <cmath>
#include <numeric>
#include <cmath>
#include <iostream>
#include <string>
#include <memory>

#include "FractalCreator.hpp"
#include "Rgb.hpp"

using namespace std;

const     string baseDir { "../images/" };
constexpr int WIDTH { 800 }, HEIGHT { 600 };

int main()
{
	time_t start = clock();

	FractalCreator fractalCreator(800, 600);

	fractalCreator.addRange(0.3, Rgb(255,0,0));
	fractalCreator.addRange(0.5, Rgb(255,255,0));
	fractalCreator.addRange(1.0, Rgb(255,255,255));

	fractalCreator.addZoom(Zoom(295,  202, 0.1));
	fractalCreator.addZoom(Zoom(312,  304, 0.1));

	const string fileName { "allBlack.bmp" };

	fractalCreator.run(baseDir + fileName);

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
}
