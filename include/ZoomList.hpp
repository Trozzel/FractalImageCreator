#ifndef __ZOOMLIST_HPP__
#define __ZOOMLIST_HPP__

#include <vector>

#include "Zoom.hpp"

class ZoomList
{
private:
	double _xCenter;
	double _yCenter;
	double _scale;

	int _width{};
	int _height{};

	std::vector<Zoom> zooms{};
	
public:
	ZoomList(int w, int h);

	void add(const Zoom& zoom);
	std::pair<double, double> doZoom(int x, int y);
};

#endif // __ZOOMLIST_HPP__
