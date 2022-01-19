#include <iostream>
#include <string>

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

	for (int x{0}; x<WIDTH; ++x) {
		for (int y{0}; y<HEIGHT; ++y) {
			double xFractal = (x - static_cast<double>(WIDTH)  / 2) * 2./WIDTH;
			double yFractal = (y - static_cast<double>(HEIGHT) / 2) * 2./HEIGHT;

			min = (min > yFractal) ? yFractal : min;
			max = (max < yFractal) ? yFractal : max;
		}
	}
	 cout << "MIN: " << min << ", MAX: " << max << endl;

	bitmap.write(baseDir + fileName);
	cout << "Finished." << endl;
}
