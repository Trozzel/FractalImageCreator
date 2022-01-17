#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <fstream>
#include <string>
#include <cstdint>
#include <memory>

class Bitmap
{
private:
	int _width  {0};
	int _height {0};
	std::unique_ptr<uint8_t[]> _pPixels {nullptr};

public:
	Bitmap(int width, int height);
	virtual ~Bitmap() = default;

	bool write(const std::string& fileName);
	void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
};

#endif // __BITMAP_H__
