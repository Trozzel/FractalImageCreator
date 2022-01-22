#ifndef __ZOOM_HPP__
#define __ZOOM_HPP__

struct Zoom
{
	int x{};
	int y{};
	double scale{};
	Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {}
};

#endif // __ZOOM_HPP__
