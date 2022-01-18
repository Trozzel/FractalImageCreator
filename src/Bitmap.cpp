#include <iostream>
#include <stdexcept>

#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace std;

// CTOR
/******************************************************************************/
Bitmap::Bitmap(int width, int height) : _width(width), _height(height),
	_pPixels {new uint8_t[height * width * 3]{}}
{
}

// WRITE TO FILE
/******************************************************************************/
bool Bitmap::write(const string& fileName)
{
	bool success {false};
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader)
		+ _width * _height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
	infoHeader.width  = _width;
	infoHeader.height = _height;

	ofstream ofs{fileName, ios::binary};
	if (!ofs)
		cerr << "Could not open file, " << fileName << endl;
	// IF THE FILE IS SUCCESSFULLY OPENED...
	else {
		ofs.write( (char*)&fileHeader, sizeof(fileHeader));
		ofs.write( (char*)&infoHeader, sizeof(infoHeader));
		ofs.write( (char*)_pPixels.get(), 
				_height * _width * 3 );
		ofs.close();
	}

	return success;
}

// SET PIXEL
/******************************************************************************/
void Bitmap::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
	uint8_t* pPixel = _pPixels.get(); // GET THE PIXEL AT [0,0][0,0,0]
	pPixel += 3 * ( y * _width + x );
	
	*pPixel       = b;
	*(pPixel + 1) = g;
	*(pPixel + 2) = r;
}
