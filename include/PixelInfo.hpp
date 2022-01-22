#ifndef __PIXELINFO_HPP__
#define __PIXELINFO_HPP__

#include <iostream>

struct PixelInfo
{
	int x;
	int y;
	int numIterations ;
	PixelInfo(int x=0, int y=0, int iter=0) : 
		x(x), y(y), numIterations(iter) 
	{}
	PixelInfo(const PixelInfo& other) :
		x(other.x), y(other.y), numIterations(other.numIterations)
	{}
	PixelInfo& operator=(const PixelInfo& other) {
		if (&other != this) {
			x = other.x;
			y = other.y;
			numIterations = other.numIterations;
		}
		return *this;
	}
};

std::ostream& operator<<(std::ostream& out, const PixelInfo& pi);

#endif // __PIXELINFO_HPP__
