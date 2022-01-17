#include <iostream>
#include <string>

#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace std;

const string baseDir { "../images/" };

int main()
{
	const string fileName { "allBlack.bmp" };

	Bitmap bitmap(800, 600);
	bitmap.write(baseDir + fileName);
	cout << "Finished." << endl;
}
