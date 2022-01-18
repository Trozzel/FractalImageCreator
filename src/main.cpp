#include <iostream>
#include <string>

#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace std;

const string baseDir { "../images/" };
constexpr int WIDTH { 800 }, HEIGHT { 600 };

int main()
{
	const string fileName { "allBlack.bmp" };

	Bitmap bitmap(WIDTH, HEIGHT);

	for (int i{0}; i<256; ++i) {
		for (int j{0}; j<HEIGHT; ++j) {
			bitmap.setPixel(i, j, i, 0, 0);
		}
	}
	for (int i{256}; i< 2 * 256; ++i) {
		for (int j{0}; j<HEIGHT; ++j) {
			bitmap.setPixel(i, j,511-i, 0, 0);
		}
	}

	bitmap.write(baseDir + fileName);
	cout << "Finished." << endl;
}
